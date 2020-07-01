#include <iostream>
#include <vector>
#include <string>
#include <cuda_runtime_api.h>
#include <cuda.h>
#define N (2048*2048)
#define THREADS_PER_BLOCK 1024
using namespace std;

class Cell {
public:
    int val;
    char* cs;
    Cell() { val = rand() % 10; }
    Cell(int v): val(v) {}
    ~Cell() {};
    __host__ __device__ void setVal(int v) {
        val = v;
        // cs = "B";
        // vec[0] = v;
    }
    __host__ __device__ int getVal() const {
        return val;
    }
    void print() { cout << val << " "; }
};

__global__ void add(Cell *a, Cell *b, Cell *c, int n) {
    // *c = *a + *b;
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    if (index < n) c[index].setVal(a[index].getVal() + b[index].getVal());
}


int main() {
    cout << "Size of Cell: " << sizeof(Cell) << endl;

    Cell *a, *b, *c;
    Cell *d_a, *d_b, *d_c;
    int size = N * sizeof(Cell);

    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);

    // a = (Cell*)malloc(size);
    // b = (Cell*)malloc(size);
    // c = (Cell*)malloc(size);
    a = new Cell [N];
    b = new Cell [N];
    c = new Cell [N];

    cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);

    add<<<N/THREADS_PER_BLOCK, THREADS_PER_BLOCK>>>(d_a, d_b, d_c, N);

    cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);

    for (int i = 0; i < 10; ++i) {
        a[i].print();
        cout << " ";
        b[i].print();
        cout << " ";
        c[i].print();
        cout << endl;
    }

    delete [] a;
    delete [] b;
    delete [] c;
    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
}