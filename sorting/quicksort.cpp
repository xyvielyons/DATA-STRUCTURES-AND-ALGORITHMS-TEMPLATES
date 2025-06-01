#include <iostream>   // for input and output using std::cin, std::cout
#include <string>     // included but not used in this code (can be removed if unused)

// Define a constant MAX to represent the maximum number of items in the array
#define MAX 10

// Declare a global integer array of size MAX and initialize it with 10 integer values
int arr[MAX] = {280, 100, 978, 670, 1467, 480, 568, 378, 2000, 1000};

/**
 * Partition function for quicksort.
 * This function chooses the last element as a pivot and rearranges
 * the array such that elements smaller than pivot are on the left,
 * and elements greater than pivot are on the right.
 *
 * @param arr[]        The array being sorted
 * @param startIndex   Starting index of the current subarray
 * @param endIndex     Ending index of the current subarray (pivot position)
 * @return             The final position of the pivot element
 */
int Partition(int arr[], int startIndex, int endIndex) {
    int pivot = arr[endIndex];     // Choose the last element as the pivot
    int pIndex = startIndex;       // This will track the correct position for the pivot

    // Loop through the array from startIndex to endIndex - 1
    for (int i = startIndex; i < endIndex; i++) {
        // If current element is less than pivot, swap it with the element at pIndex
        if (arr[i] < pivot) {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;  // Move pIndex to the right
        }
    }

    // After the loop, swap the pivot with the element at pIndex
    // So pivot will be at its correct sorted position
    int temp = arr[endIndex];
    arr[endIndex] = arr[pIndex];
    arr[pIndex] = temp;

    // Return the index where the pivot is now placed
    return pIndex;
}

/**
 * Recursive quicksort function that sorts the array in-place
 *
 * @param myArr[]      The array to be sorted
 * @param startIndex   Start index of the portion of the array to sort
 * @param endIndex     End index of the portion of the array to sort
 */
void quickSort(int myArr[], int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        // Partition the array and get pivot index
        int pivot = Partition(myArr, startIndex, endIndex);

        // Recursively sort the left part (elements before pivot)
        quickSort(myArr, startIndex, pivot - 1);

        // Recursively sort the right part (elements after pivot)
        quickSort(myArr, pivot + 1, endIndex);
    }
}

/**
 * Main function that runs when the program is executed.
 * It prints the array before sorting, performs quicksort,
 * and then prints the sorted array.
 */
int main() {
    std::cout << "Before sorting:" << std::endl;
    for (int i = 0; i < MAX; i++) {
        std::cout << "Value : " << arr[i] << std::endl;
    }

    // Call quickSort on the entire array
    quickSort(arr, 0, MAX - 1);

    std::cout << "...........After sorting.............." << std::endl;
    for (int i = 0; i < MAX; i++) {
        std::cout << "Value : " << arr[i] << std::endl;
    }

    return 0;
}
