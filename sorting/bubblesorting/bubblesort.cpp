#include <iostream>
#include <string>

//we are going to define the global variable to control the size of the array
#define MAX 8
//global declaration of an array that stores 4 items
int arr[MAX] = {280,100,978,670,1467,480,568,378};


void bubbleSort(int myArray[]){
    //we iterate though the array 
    for(int i=0; i < MAX; i++){
        for(int j=0; j<(MAX-i-1); j++){
            //we are picking the current element and comparing if its greater than the next element
            if(myArray[j]>myArray[j+1]){
                int temp = myArray[j];
                //we then perform the swap
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }

        }
    }

}

int main(){
    std::cout << "before sorting" << std::endl;
    for(int i=0; i<MAX; i++){
        std::cout << "value : " << arr[i] << std::endl; 

    };

    bubbleSort(arr);
    std::cout << "after sorting" << std::endl;
    for(int i=0; i<MAX; i++){
        std::cout << "value : " << arr[i] << std::endl; 

    };

}