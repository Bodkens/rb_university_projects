#include <iostream>
#include "core.hpp"
#include <string>

Core Cortex_X2(H);
Core Cortex_A710(M);
Core Cortex_A510(L);

using namespace std;

int main(int argc, char** argv){
    
    
    if(argv[1] == NULL){
        perror("Error: Missing file path\n");
        return 1;
    }
    if(Core::Init(argv[1]) != 0){
        perror("Error: File not found\n");
        return 1;
    }
    
    printf("Solving this instruction via Round-Robin running %d time frames\n", Core::ComputeRR(Cortex_X2, Cortex_A710, Cortex_A510));
    printf("Solving this instruction via Best-Merge  running %d time frames\n", Core::ComputeBM(Cortex_X2, Cortex_A710, Cortex_A510));
    return 0;
}