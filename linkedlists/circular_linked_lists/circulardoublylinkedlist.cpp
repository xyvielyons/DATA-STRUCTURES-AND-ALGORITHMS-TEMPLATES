#include <iostream>
#include <string>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct node* circularDoubly(int data){
    struct node* temp = new node;
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;

    return temp;
}

int main(){
    int data = 45;
    struct node* tail = new node;
    tail = circularDoubly(data);
}