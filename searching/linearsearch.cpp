#include <iostream>
#include <string>

// Define a constant for the maximum size of the array
#define MAX 10

// Declare and initialize a global array with 10 integers
int arr[MAX] = {280, 100, 978, 670, 1467, 480, 568, 378, 2000, 1000};

// Function to perform linear search on the array
void linearSearch(int a[], int numberToSearch) {
    // A temporary flag variable to indicate whether the number was found
    int temp = -1;

    // Loop through the array
    for (int i = 0; i < MAX; i++) {
        // Check if the current element matches the number we're searching for
        if (a[i] == numberToSearch) {
            // Print the index where the number was found (adding 1 for human-friendly output)
            std::cout << "Element found at index: " << i + 1 << std::endl;
            temp = 0; // Set flag to indicate match was found
        }
    }

    // If no match was found, print a message
    if (temp == -1) {
        std::cout << "No element found" << std::endl;
    }
}

int main() {
    // Call the linear search function with the array and the number to find
    linearSearch(arr, 10034); // This number is not in the array
}
