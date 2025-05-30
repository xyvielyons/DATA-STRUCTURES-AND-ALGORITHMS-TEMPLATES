#include <iostream>
#include <string>
//this indicates maximum size of array
#define MAX 4
//indicates the status of the stack
//initially it is -1 symbolizing the stack is empty
int top = -1;

//global declaration of an array that stores 4 items
int stack_arr[MAX];

//adding elements in the stack
void push(int data){
    //we are checking the stack has free space
    if(top == MAX - 1){
        std::cout << "stack has overflowed for : " << data << std::endl;
        return;

    }
    //incrementing the value of top by 1
    //if top = -1 it will be index 0 of the array
    top = top + 1;
    //the top gives us the index to insert into the array
    stack_arr[top] = data;
}
//removing elements in the stack
int pop(){
    //if stack is empty return error
    if(top == -1){
        std::cout << "stack is empty/undeflow" <<std::endl; 
        return -1;
    }
    //we declare value
    int value;
    //we store the data in the array for that index that is going to be deleted
    value = stack_arr[top];
    //decrement the top variable by one giving an illusion that it has been deleted
    top--;

    return value;

}
//return true if stack is full and return false if stack is empty
bool isFull(){
    //if stack is full return true and vice verca
    if(top == MAX - 1){
        std::cout << "The stack is full" << std::endl;
        return true;
    }else{
        return false;
    }
}
//checking whether the stack is empty
bool isEmpty(){
    //if top == -1 which symbolizes the stack is empty
    if(top == -1){
        std::cout << "The stack is empty" << std::endl;
        return true;
    }else{
        return false;
    }

}
//return the number of elements in the array
int size(){
    return top - 1;
}
int main(){
    isEmpty();
    push(1);
    isFull();
    push(2);
    push(3);
    push(4);
    int mydata = pop();
    std::cout << "data to be deleted: " << mydata << std::endl;
    push(5);
    push(6);
    isFull();
}