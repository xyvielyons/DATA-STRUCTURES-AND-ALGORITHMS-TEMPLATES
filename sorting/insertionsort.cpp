#include <iostream>
#include <string>

//we are going to define the global variable to control the size of the array
#define MAX 10
//global declaration of an array that stores 4 items
int arr[MAX] = {280,100,978,670,1467,480,568,378,2000,1000};


// Function to perform insertion sort on an array
void insertionSort(int myArr[]) {
    int key = 0;  // Element to be inserted in the correct position
    int j = 0;    // Index variable for comparison

    // Loop through each element starting from the second one
    for (int i = 1; i <= MAX - 1; i++) {
        key = myArr[i];  // Store the current element as the key
        j = i - 1;

        // Shift elements of the sorted portion of the array that are greater than key
        while (j >= 0 && myArr[j] > key) {
            myArr[j + 1] = myArr[j];  // Move element one position to the right
            j = j - 1;
        }

        // Insert the key at the correct location
        myArr[j + 1] = key;
    }
}

int main(){
    std::cout << "before sorting" << std::endl;
    for(int i=0; i<MAX; i++){
        std::cout << "value : " << arr[i] << std::endl; 

    };

    insertionSort(arr);
    std::cout << "...........after sorting.............." << std::endl;
    for(int i=0; i<MAX; i++){
        std::cout << "value : " << arr[i] << std::endl; 

    };
    return 0;
}