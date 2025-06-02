#include <iostream>
#include <string>

//we are going to define the global variable to control the size of the array
#define MAX 4
//global declaration of an array that stores 4 items
int queue_arr[MAX];

//we need to variables front and rear to keep track of both the ends
int rear = -1;
int front = -1;

//how to know if our queue is empty
bool isEmpty(){
    //when initialization happens front and rear is set to -1
    //which means nothing will be in our array
    if(front == -1 && rear == -1){
        return true;
    }else{
        return false;
    }
}
//function to know if our queue is Full
bool isFull(){
    //if queue is full rear should read 3 because it starts from 0
    if((rear+1)%MAX==front){
        return true;
    }else{
        return false;
    }
}
//adding elements in the rear end of the queue
void enqueue(int value){
    //we want to know if the queue is full before inserting a new element in the queue
    if(isFull()){
        return;
    }else if(isEmpty()){
        //intially they are storing -1 
        //if queue is empty we make rear and front point to index 0
        rear=0;
        front=0;
    }else{
        //we increment rear by +1 and take a modular operation on the size of the array
        //% gives us the reminder
        //lets say rear is 3 so its 3 = (3+1)%4
        rear = (rear+1)%MAX;
    }
    //we then insert the value inside the queue using rear as the index
    queue_arr[rear] = value;
}
//elements are removed at the front of the queue
int dequeue(){
    int x = 0;
    if(isEmpty()){
        exit(1);
    }else if(front == rear){
        //this only happens if there is one element in the queue
        //e.g front=0 rear=0
        //we store the value at that index in x variable
        x = queue_arr[front];
        //we then reset front and rear to -1
        front = -1;
        rear = -1;

    }else{
        //when the queue has more than 1 elements in it;
        //we store the value in the front index first in x 
        x = queue_arr[front];
        //initially front was index 0
        //we are incrementing it to go to the next index 1 so that we can access the second index in the list
        front = (front+1)%MAX;
    }

    return x;

}

int main(){
    enqueue(1);
    enqueue(2);

    int data = dequeue();
    std::cout << "queue data: " << data << std::endl;
    int twodata = dequeue();
    std::cout << "queue data: " << twodata << std::endl;
}
