#include <iostream>  // For input and output operations
#include <string>    // Included, but not used in this code

// Define a constant for the maximum number of elements in the array
#define MAX 10

// Declare and initialize a global sorted array with 10 integers
// This is required for binary search to work correctly
int arr[MAX] = {1,2,3,4,5,6,7,8,9,10};

/*
    Function: binarySearch
    -----------------------
    This function searches for a value `x` within a sorted array `myArr[]`
    using the binary search algorithm.

    Parameters:
    - myArr[]: the array in which we search
    - leftInterval: the starting index of the search interval
    - rightInterval: the ending index of the search interval
    - x: the value to be searched

    Returns:
    - the index of the value `x` if found
    - -1 if the value is not found in the array
*/
int binarySearch(int myArr[], int leftInterval, int rightInterval, int x){
    // Loop continues as long as the search range is valid
    while(leftInterval <= rightInterval){
        // Calculate the midpoint to avoid potential overflow
        int midpoint = leftInterval + (rightInterval - leftInterval) / 2;

        // If the midpoint element is equal to x, we've found the value
        if(myArr[midpoint] == x){
            return midpoint;
        }
        // If the midpoint element is less than x, ignore the left half
        else if(myArr[midpoint] < x){
            leftInterval = midpoint + 1;
        }
        // If the midpoint element is greater than x, ignore the right half
        else{
            rightInterval = midpoint - 1;
        }
    }
    // If we reach here, the value was not found
    return -1;
}

int main(){
    // Call binarySearch to search for value 8 in arr from index 0 to MAX
    // Note: MAX is 10, but last valid index is 9, so this can cause out-of-bounds access
    int output = binarySearch(arr, 0, MAX, 8);  // Bug here: should be MAX - 1 instead of MAX

    // Check if the value was found
    if(output == -1){
        std::cout << "The value was not found" << std::endl;
    }else{
        // Add 1 to output to display position as 1-based index (optional)
        std::cout << "The value was found at index : " << output + 1 << std::endl;
    }
}
