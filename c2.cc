// //
// // Created by Brian Swenson on 2/8/18.
// //

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "e2.h"

template <typename It>
ansType vecFunc(It begin, It end)
{
	ansType myVal, newVal;

    auto len = end - begin;
    if (len < (50000000/5)) {
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
}