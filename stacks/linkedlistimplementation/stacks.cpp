#include <iostream>
#include <string>

//we are going to create the structure of the node

struct node {
    int data;
    struct node* link;
    //we are also going to declare the top pointer globally in the code its like head pointer
}*top = nullptr;

//it is the same as add to beginning in singly linked list
struct node* push(int data){
    struct node* ptr = new node;
    ptr->data = data;
    ptr->link = nullptr;
    
    //returns this if we dont cannot allocate the memory again
    //memory is full
    if(ptr == nullptr){
        std::cout << "Stack overflow" << std::endl;
        return nullptr;
    }

    if(top == nullptr){
        top = ptr;
        return top;
    }else{
        ptr->link = top;
        top = ptr;
        return top;
    }


}
//tells us if our linked list is empty
int isEmpty(){
    if(top==nullptr){
        return 1;
    }else{
        return 0;
    }

}

//the pop() function is the same as delete first node function of singly linked list
int pop(){
    int valuePopped;
    if(isEmpty()){
        std::cout << "List is already empty" << std::endl;
        exit(1);
    }
    struct node* temp = top;
    //we are going to store the value to be deleted from the list in a variable
    valuePopped = temp->data;
    top = temp->link;
    delete temp;
    temp = nullptr;
    return valuePopped;

}
//returns the top most element of the stack
int peek(){
    if(isEmpty()){
        std::cout << "stack Underflow" << std::endl;
    }
    return top->data;

}

//we use this function to print the contents of the list
void printList(){
    struct node* temp = top;
    while(temp->link != nullptr){
        std::cout << "node data: " << temp->data << std::endl;
        temp = temp->link;
    }
    std::cout << "node data: " << temp->data << std::endl;

}

int main(){
    int status = isEmpty();
    std::cout << "status..........." << status <<std::endl;

    //struct node* head = nullptr;
    top = push(20);
    top = push(30);
    top = push(40);

    printList();
    int valuePopped = pop();
    std::cout << "deletion request..........." << valuePopped <<std::endl;
    printList();
    int myPeek = peek();
    std::cout << "top most element..........." << myPeek <<std::endl;

};