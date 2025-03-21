//adding data at end of list
#include <iostream>
#include <string>

//it takes in the whole array, the free position , and data
int add_at_end(int a[],int freePos,int data){
    //we input the data to the freeposition
    a[freePos] = data;
    //we increment by one
    freePos++;
    //we then return the free position in the array
    return freePos;
}


int main(){
    int a[10];
    int i,n,freePos;

    //here we enter the number of elements we want in the array
    std::cout << "Enter the number of elements: " ;
    std::cin >> n;
    
    //we look how many fill in the data with the number of elements
    for(i=0;i<n;i++){
        int number;
        std::cout << "Enter element" << i << ": "; 
        std::cin >> number;
        a[i] = number;
    }

    //if n = 3 then the free position is 3
    //this is because an array starts counting from 0
    //freepos maintains the index of the empty slot
    freePos = n;
    freePos = add_at_end(a,freePos,65);

    for (int i = 0; i < freePos; i++)
    {
        std::cout << a[i] << std::endl;
    }
    

}