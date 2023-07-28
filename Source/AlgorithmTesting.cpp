#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "BasicSort.h"
#include "AdvancedSort.h"
#include "NoComparisonSort.h"
#include "FlashSort.h"

void testAlgorithm() {
    std::ifstream* fi = new std::ifstream[4];
    std::ofstream* fo = new std::ofstream[4];

    int inputSize[] = { 10000, 30000, 50000 };

    for (int i = 0; i < sizeof(inputSize)/ sizeof(inputSize[0]); i++) {
        std::cout << "Part " << i << "\n";
        //iterate through inputSize[]
        int n = inputSize[i];

        std::string* s = new std::string[4];

        s[0] = "randomized_data_" + std::to_string(n);
        s[1] = "sorted_data_" + std::to_string(n);
        s[2] = "reversed_sorted_data_" + std::to_string(n);
        s[3] = "nearly_sorted_data_" + std::to_string(n);

        for (int j = 0; j < 4; j++) {
            fi[j].open(s[j] + ".txt");
            fo[j].open(s[j] + "_result.txt");
        }

        int* a = new int[n];

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < n; k++) {
                fi[j] >> a[k];
            }

            clock_t start = clock();

            flashSort(a, n);

            clock_t end = clock();

            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

            std::cout << "Time used for " << j << ": " << timeUsed << "\n";

            for (int k = 0; k < n; k++) {
                fo[j] << a[k] << " ";
            }

            fi[j].clear();
            fi[j].seekg(0, std::ios::beg);

            for (int k = 0; k < n; k++) {
                fi[j] >> a[k];
            }

            long long cmp = flashSortWithCounting(a, n);

            std::cout << "Comparisons used for " << j << ": " << cmp << "\n";
        }

        delete[] a;

        for (int j = 0; j < 4; j++) {
            fi[j].close();
            fo[j].close();
        }

        delete[] s;

    }

    delete[] fi;
    delete[] fo;

}
/*
    randomized_data_
    sorted_data_
    reversed_sorted_data_
    nearly_sorted_data_
*/
void testAlgorithm2() {
    std::ifstream* fi = new std::ifstream[4];

    int inputSize[] = { 10000 };

    // với mỗi order
    for (int order = 0; order < 4; order++) {
        if (order == 0) {
            std::cout << "Random order: " << "\n";

            // với mỗi size
            for (int size = 0; size < sizeof(inputSize)/ sizeof(inputSize[0]); size++)
            {
                if (size == 0) {                    
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "randomized_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) { 
                                fi[order] >> a[k]; 
                            }

                            clock_t start = clock(); 

                            selectionSort(a, n); 

                            clock_t end = clock(); 

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC; 

                            std::cout << "         Time used: " << timeUsed << "\n"; 

                            fi[order].clear(); 
                            fi[order].seekg(0, std::ios::beg); 

                            for (int k = 0; k < n; k++) { 
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n); 

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n-1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 1) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "randomized_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                    }
                else if (size == 2) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "randomized_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                    }
                else if (size == 3) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "randomized_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                    }
                else if (size == 4) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "randomized_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                    }
                else if (size == 5) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "randomized_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                    }
            }
        }
        else if (order == 1) {
            std::cout << "Sorted order: " << "\n";

            // với mỗi size
            for (int size = 0; size < sizeof(inputSize) / sizeof(inputSize[0]); size++)
            {
                if (size == 0) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 1) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 2) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 3) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 4) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 5) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
            }
        }
        else if (order == 2) {
            std::cout << "Reversed Sorted order: " << "\n";

            // với mỗi size
            for (int size = 0; size < sizeof(inputSize) / sizeof(inputSize[0]); size++)
            {
                if (size == 0) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "reversed_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 1) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "reversed_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 2) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "reversed_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 3) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "reversed_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 4) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "reversed_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 5) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "reversed_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
            }
        }
        else if (order == 3) {
            std::cout << "Nearly Sorted order: " << "\n";

            // với mỗi size
            for (int size = 0; size < sizeof(inputSize) / sizeof(inputSize[0]); size++)
            {
                if (size == 0) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "nearly_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 1) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "nearly_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 2) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "nearly_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 3) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "nearly_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 4) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "nearly_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
                else if (size == 5) {
                    int n = inputSize[size];

                    std::cout << "   Size: " << n << "\n";

                    std::string* s = new std::string[4];

                    s[order] = "nearly_sorted_data_" + std::to_string(n);

                    fi[order].open(s[order] + ".txt");

                    // với mỗi thuật toán
                    for (int algo = 0; algo < 11; algo++) {
                        if (algo == 0) {
                            std::cout << "      Selection Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            selectionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = selectionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 1) {
                            std::cout << "      Insertion Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            insertionSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = insertionSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 2) {
                            std::cout << "      Bubble Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            bubbleSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = bubbleSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 3) {
                            std::cout << "      Shaker Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shakerSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shakerSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 4) {
                            std::cout << "      Shell Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            shellSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = shellSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 5) {
                            std::cout << "      Heap Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            heapSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = heapSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 6) {
                            std::cout << "      Merge Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            mergeSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = mergeSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 7) {
                            std::cout << "      Quick Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            quickSort(a, 0, n - 1);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = quickSortWithCounting(a, 0, n - 1);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        /*if (algo == 8) {
                            std::cout << "      Counting Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            countingSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = countingSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }*/
                        if (algo == 9) {
                            std::cout << "      Radix Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            radixSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = radixSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                        if (algo == 10) {
                            std::cout << "      Flash Sort: " << "\n";
                            int* a = new int[n];

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            clock_t start = clock();

                            flashSort(a, n);

                            clock_t end = clock();

                            double timeUsed = (double)(end - start) / CLOCKS_PER_SEC;

                            std::cout << "         Time used: " << timeUsed << "\n";

                            fi[order].clear();
                            fi[order].seekg(0, std::ios::beg);

                            for (int k = 0; k < n; k++) {
                                fi[order] >> a[k];
                            }

                            long long cmp = flashSortWithCounting(a, n);

                            std::cout << "         Comparisons used: " << cmp << "\n";

                            delete[] a;
                        }
                    }

                    fi[order].close();

                    delete[] s;
                }
            }
        }
    }
    
    delete[] fi;
    //delete[] fo;
}
