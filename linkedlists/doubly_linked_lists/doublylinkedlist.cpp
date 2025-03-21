#include <iostream>
#include <string>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

int main(){
    //creating our first head node
    struct node *head = new node;
    //we assign previous and next node with NULL;
    head->prev = nullptr;
    head->data=10;
    head->next=nullptr;
}