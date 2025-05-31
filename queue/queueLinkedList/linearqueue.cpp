#include <iostream>
#include <string>

struct node {
    int key;//unique identifier
    int value;//actual value
    struct node *next; //pointer to next node(self referential)
};
//stores the addresses of the front and rear nodes
struct node* front = nullptr;
struct node* rear = nullptr;

//function to create the new node
struct node* createNode(int data,int mykey){
    struct node* newPtr = new node;
    newPtr->value=data;
    newPtr->key=mykey;
    newPtr->next=nullptr;

    return newPtr;

}

//function that checks if the list is empty
bool isEmpty(){
    if(front==nullptr && rear==nullptr){
        std::cout << "The queue is empty" << std::endl;
        return true;
    }else{
        return false;
    }
}

//two nodes in our list can have the same data but not the same key
//here we check if a node exist or not by checking the key to see if it exists or not
bool checkIfNodeExists(struct node* n){
    struct node* temp = front;
    //initially exist is set to false
    bool exist = false;
    while(temp != nullptr){
        //we then look if the key match
        if(temp->key == n->key){
            exist = true;
            break;
        }
        //go to the next node;
        temp = temp->next;
    }
    //we are going to return exist boolean state
    return exist;

}

//adding a new node at the reae end of the list
void enqueue(struct node* newNode){
    //if the queue is empty we update the front and rear pointer with the pointer of the new node
    //now front and rear point to the new first node of the list
    if(isEmpty()){
        front = newNode;
        rear = newNode;
        std::cout << "Node enqueued successfully" << std::endl;
    }else if(checkIfNodeExists(newNode)){
        //we look to see if the node exists
        std::cout << "Node already exist key matches" << std::endl;

    }else{
        //the rear pointer is the only node that is updated to point to the new node
        //this is because nodes are added from the rear side
        rear->next = newNode;
        //we then update the rear global pointer to point to the new node
        rear = newNode;
        std::cout << "Node enqueued successfully" << std::endl;

    }
}
//we are going to return the pointer to the new front node
struct node* dequeue(){
    struct node* temp = nullptr;
    //check if queue is empty
    if(isEmpty()){
        std::cout << "The queue is empty" << std::endl;
        return nullptr;
    }else{
        //we have two different scenarios when we have one node and when we have more than one node
        if(front == rear){
            //the temporary node points to the front node 
            temp = front;
            //we free the memory of both front and rear
            delete front;
            delete rear;
            //we nullify both front and rear
            front = nullptr;
            rear = nullptr;
            //we return the temporary node that was dequeued
            return temp;
        }else{
            //the temporary node points to the front node 
            temp = front;
            //we then free the memory held by front
            delete front;
            front = nullptr;

            //we update front to point to the next node on the list
            front = temp->next;
            //we then return temp
            return temp;

        }   
    }

}
//counts the number of nodes in the queue
int count(){
    int count = 0;
    struct node* temp = front;

    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}
//displays the nodes
void display(){
    if(isEmpty()){
        std::cout << "The queue is empty" << std::endl;
    }else{
        std::cout << "All values in the queue are :" << std::endl;
        struct node* temp = front;
        while(temp != nullptr){
            std::cout << "(" << temp->key<<","<< temp->value <<")"<< std::endl;
            //go to next node
            temp=temp->next;
        }
    }

}

int main(){
    enqueue(createNode(20,1));
    enqueue(createNode(30,2));
    enqueue(createNode(40,3));
    display();
    struct node* dequeuedNode = dequeue();
    std::cout << "dequeued node is: " << dequeuedNode->value << std::endl;
    display();
    struct node* dequeuedNode2 = dequeue();
    std::cout << "dequeued node is: " << dequeuedNode2->value << std::endl;
    display();
    enqueue(createNode(50,3));
}