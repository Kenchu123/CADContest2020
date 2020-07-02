CXX = g++
INC = ./inc
LIB = ./lib
OBJDIR = ./build
EXEDIR = ./bin
CFLAGS = -Wall -g
# CFLAGS = 
PREPROCESS_OBJS = ./build/preprocess.o
SIMULATOR_OBJS = ./build/main.o ./build/wire.o ./build/gate.o ./build/vlib.o ./build/vcd.o ./build/simulator.o
# CFLAGS += -O2

all: directories preprocess simulator

directories: $(OBJDIR) $(EXEDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(EXEDIR):
	mkdir -p $(EXEDIR)

$(OBJDIR)/%.o: ./src/%.cpp
	$(CXX) -c -o $@ $< -I$(INC) $(CFLAGS) -std=c++11

preprocess: $(PREPROCESS_OBJS)
	$(CXX) $(CFLAGS) -o $(EXEDIR)/GraphPreprocessing.exe $(PREPROCESS_OBJS) -std=c++11

simulator: $(SIMULATOR_OBJS)
	$(CXX) $(CFLAGS) -o $(EXEDIR)/GPUSimulator.exe $(SIMULATOR_OBJS)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*
	rm -f $(EXEDIR)/*.exe
