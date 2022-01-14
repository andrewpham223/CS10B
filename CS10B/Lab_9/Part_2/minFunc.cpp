#include "minFunc.h"
/* Base cases: if arrSize == 0, return nullptr. Base case 2: if arrSize == 1, just return the address at the single index
Recursive case: Compare the last value of the array with the minimum of an array of size arrSize-1, returning the smaller of the two 
This results in recursive calls that cascade down the entire array. The first value is compared to the second value, the smaller of which is compared
to the third value, and so on. */
const int * min(const int arr[], int arrSize) { 
    if(arrSize == 0) {
        const int* nul = nullptr;
        return nul;
    }
    if(arrSize == 1) {
        return &arr[0];
    }
    else {
        int lastIndex = arrSize-1;
        const int *minCheck = min(arr, lastIndex);
        if(*minCheck < arr[lastIndex]) {
            return minCheck;
        }
        else {
            return &arr[lastIndex];
        }
    }
}