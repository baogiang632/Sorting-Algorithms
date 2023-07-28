#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <string.h>
#include "BasicSort.h"
#include "AdvancedSort.h"
#include "NoComparisonSort.h"
#include "FlashSort.h"
#include "DataGenerator.h"
#include "AlgorithmTesting.h"
#include "CommandProcess.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc == 5) { 
        if (strcmp(argv[1], "-a") == 0) { 
            commandOneAndThree(argv[2], argv[3], argv[4]); 
        } else if (strcmp(argv[1], "-c") == 0) { 
            commandFour(argv[2], argv[3], argv[4]); 
        }
    } 
    else if (argc == 6) { 
        if (strcmp(argv[1], "-a") == 0) { 
            commandTwo(argv[2], argv[3], argv[4], argv[5]); 
        } else if (strcmp(argv[1], "-c") == 0) { 
            commandFive(argv[2], argv[3], argv[4], argv[5]); 
        }        
    }
    else if (argc == 2) {
        if (strcmp(argv[1], "-t") == 0) {
			// chạy 1 thuật toán
			//testAlgorithm();
			
			// chạy tất cả thuật toán
            testAlgorithm2();
        }
    }

    // Test commandline
    // Command 1: sortAlgorithm.exe -a radix-sort input.txt -both
    // Command 2: sortAlgorithm.exe -a selection-sort 10000 -rand -time
    // Command 3: sortAlgorithm.exe -a binary-insertion-sort 70000 -comp
    // Command 4: sortAlgorithm.exe -c heap-sort merge-sort input.txt
    // Command 5: sortAlgorithm.exe -c quick-sort merge-sort 100000 -nsorted
    // Command experiment: sortAlgorithm.exe -t
    
    return 0;
}