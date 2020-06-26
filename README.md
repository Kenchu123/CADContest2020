# CAD Contest 2020, Problem C

### Compile
```
make preprocess
make simulator
```

### Run Preprocess
```
./bin/GraphPreprocessing.exe <netlist.gv> <netlist.SDF> <std_cells.vlib> [intermediate_representation.file]
```
### Run Simulator
```
./bin/GPUSimulator.exe <intermediate_representation.file> <input.vcd> <SAIF_or_VCD_flag> <dumpon_time> <dumpoff_time> [SAIF_or_output_VCD.saif.vcd]
```
