//
// Created by Brian Swenson on 2/8/18.
//
#include <thread>
#include <future>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>



#ifndef E2_E2_H
#define E2_E2_H


struct ansType{
	int minVal = 0;
    int maxVal = 0;
    long sum = 0;
};

template<typename It> ansType vecFunc(It, It);




/*template <typename It>
ansType vecFunc(It begin, It end)
{
	ansType myVal, newVal;

    auto len = end - begin;
    if (len <= (50000000/4)) {
    	for(; begin != end; ++begin) {
        	myVal.sum = myVal.sum + *begin;
        	if (*begin < myVal.minVal)
            	myVal.minVal = *begin;
        	if (*begin > myVal.maxVal)
            	myVal.maxVal = *begin;
        }
        return myVal;
    }
 
    It mid = begin + len/2;
    auto handle = std::async(std::launch::async,
                             vecFunc<It>, mid, end);
    myVal = vecFunc(begin, mid);
	
	newVal = handle.get();
	myVal.sum += newVal.sum;
	if (myVal.minVal > newVal.minVal)
		myVal.minVal = newVal.minVal;
	if (myVal.maxVal < newVal.maxVal)
		myVal.maxVal = newVal.maxVal;

    return myVal;
}*/

#endif //E2_E2_H

