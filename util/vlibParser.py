# Usage: vlibParser <vlib> <output.hpp>

import os
import sys

vlib_path = sys.argv[1]
output_path = sys.argv[2]
vlib = open(vlib_path, 'r')
output = open(output_path + '.hpp', "w")

# define DEFINE in output
defines = ["#ifndef VLIB\n", "#define VLIB\n"]
output.writelines(defines)
# define includes in output
headers = ["#include <string>\n", "#include <unordered_map>\n", "#include \"wire.h\"\n"]
output.writelines(headers)
# write template class
template = open("./vlib_template.hpp", "r")
output.write(template.read())
template.close() 


line = vlib.readline()
line_cnt = 0
while line == '\n': 
    line = vlib.readline()
    line_cnt += 1
module_cnt = 0

# parse module
newKeyWord = {}
def parse_module(out, lines):
    print(lines)
    # line 0, module <name> (params ...)
    module_name = lines[0][1]
    params = lines[0][2:]
    params = ''.join(params).translate({ord(i): None for i in '();'}) # remove '(', ')', ';'
    params = params.split(',')
    print('params', params)

    out.write('class ' + module_name + ' : public Cell {\n')
    out.write('    public:\n')
    # out.write('        unordered_map<string, Wire*> mp;\n')
    out.write('        ' + module_name + '(){}\n')
    out.write('        ~' + module_name + '(){}\n')
    # writing _step
    out.write('        static void step(unordered_map<string, Wire*> &wire) {\n')
    inSpecify = False
    newThings = []
    newBus = []
    built_in = ['and', 'or', 'not', 'buf', 'xor', 'nand', 'nor', 'xnor']
    primitives = ['udp_mux2', 'udp_tlat', 'udp_dff', 'udp_xbuf']
    for i in range(1, len(lines)):
        line = lines[i]
        if inSpecify: continue

        if line[0] == 'wire':
            names = line[1:]

            if names[0][0] == '[': # for Wires, multiple bits
                bits = int(names[0].split(':')[0][1:]) + 1
                print('Bus, bitsize = ' + str(bits))
                # out.write('            Wire** ' + names[1][:-1] + ' = new Wire*[' + str(bits) + '];\n')
                # out.write('            for (int i = 0; i < ' + str(bits) + '; ++i) ' + names[1][:-1] + '[i] = new Wire();\n')
                newBus.append(names[1][:-1])
            else: # for Wire, single bits
                names = ''.join(names)
                names = names[:-1].split(',')
                out.write('            Wire')
                for j in range(len(names)):
                    out.write(' *' + names[j])
                    if j != len(names) - 1: out.write(',')
                out.write(';\n')
                for name in names:
                    out.write('            ' + name + ' = new Wire();\n')
                    newThings.append(name)
                print('Wire names: ', names)
        ## Register only exist in Sequential circuit, which is not need to re-simulate
        # elif line[0] == 'reg':
        #     names = line[1:]
        #     names = ''.join(names)
        #     out.write('            Reg* ' + names + '\n')
        #     names = names[:-1].split(',')
        #     for name in names:
        #         out.write('            ' + name + ' = new Reg();\n')
        #         newThings.append(name)
        #     print('Reg names: ', names)
        elif line[0] == 'specify':
            inSpecify = True
        elif line[0] == 'endspecify':
            inSpecify = False
        elif line[0] == 'endmodule':
            break
        elif line[0] == 'input' or line[0] == 'output': continue
        elif line[0] in built_in or line[0] in primitives:
            out.write('            _' + line[0] + '(')
            if line[0] in built_in: step_params = line[1:]
            else: step_params = line[2:]
            step_params = ''.join(step_params).translate({ord(i): None for i in '();'}) # remove '(', ')', ';'
            step_params = step_params.split(',')
            print('step params: ', step_params)
            for j in range(len(step_params)):
                if step_params[j] in newThings:
                    out.write(step_params[j])
                else:
                    out.write('wire[\"' + step_params[j] + '\"]')
                if j != len(step_params) - 1: out.write(', ')
            out.write(');\n')
            newKeyWord[line[0] + str(len(step_params))] = line[0] + str(len(step_params))
    
    for toDel in newThings:
        out.write('            delete ' + toDel + ';\n')
    out.write('        }\n')
    out.write('};\n')

while line:
    parts = line.split() # split line with spaces
    # Get module lines
    if parts[0] == "module":
        module_lines = []
        module_lines.append(parts)
        while parts[0] != "endmodule":
            line = vlib.readline()
            line_cnt += 1
            while line == '\n': 
                line = vlib.readline()
                line_cnt += 1
            parts = line.split()
            module_lines.append(parts)
    
        module_cnt += 1
        parse_module(output, module_lines)
        

    line = vlib.readline()
    line_cnt += 1
    while line == '\n': 
        line = vlib.readline()
        line_cnt += 1

vlib.close()
print('Line Count: {}'.format(line_cnt))
print('Module Count: {}'.format(module_cnt))

output.write("#endif")

# print(newKeyWord)