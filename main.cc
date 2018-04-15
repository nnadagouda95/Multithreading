#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

#include "e2.h"

//create shortcut
namespace sc = std::chrono;
                            
int main() {

    //ansType myVal;

    std::vector<int> myVec (50000000);
    std::srand(0);

    //another, better option would be to use std::generate and a c++11ish random generator
    for(int i = 0; i < myVec.capacity(); ++i) {
        myVec[i] = std::rand() % 1000;
    }

    //http://en.cppreference.com/w/cpp/chrono
    auto start = sc::high_resolution_clock::now();

    int minVal;
    int maxVal;
    long sum;
    double average;

    //todo:  insert code here to populate these values
    //       the final execution time must be faster
    //       than what can be achieved with a single thread
    //      bonus points will be rewarded for fastest times
    std::vector<int>::iterator begin = myVec.begin();
    auto end1 = myVec.end();

    ansType myVal = vecFunc(begin, end1);
    sum = myVal.sum;
    minVal = myVal.minVal;
    maxVal = myVal.maxVal;

    average = double (sum)/myVec.size();

    auto end = sc::high_resolution_clock::now();

    std::cout << "Min: " << minVal << std::endl;
    std::cout << "Max: " << maxVal << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;

    std::cout << "Elapsed Time: " << sc::duration_cast<sc::milliseconds>(end - start).count() << "ms" << std::endl;
}
