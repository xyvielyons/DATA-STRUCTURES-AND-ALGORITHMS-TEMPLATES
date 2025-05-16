#include <iostream>
#include <string>

struct node {
    int data;
    struct node* next;
};

struct node* circularSingly(int data){
    struct node* temp = new node;
    temp->data = data;
    temp->next = temp;
    return temp;
}

int main(){
    int data = 34;
    struct node* tail = nullptr;
    tail = circularSingly(data);


    // std::cout << tail->next << std::endl;
}