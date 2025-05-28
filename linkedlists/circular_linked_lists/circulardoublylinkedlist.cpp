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
//code for creating a node
struct node* createNode(int data){
    struct node* newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}
//prints all the data in the nodes of the linked list
void printAllData(struct node* tail){
    struct node* head = tail->next;

    do{
        std::cout << "linked list : " << head->data << std::endl;
        head = head->next;
    }while(head != tail->next);
}

//inserting a node at the beginning of the list
struct node* insertbeginning(struct node* tail,int data){
    struct node* newP = createNode(data);

    //only this applys when you have only one node in the list
    // newP->next = tail;
    // newP->prev = tail;

    // tail->prev = newP;
    // tail->next = newP;

    //we keep a pointer pointing to the first node of the list
    struct node* temp = tail->next;
    //The next value in newP points to temp which is the first node
    newP->next = temp;
    //the prev value in newP points to the tail which is the last node of the linked list
    newP->prev = tail;
    //we then update temp(initial first node of the list) prev value to point to the new inserted node
    temp->prev = newP;
    //we then update tail(last node of the list) next value to point to the address of the new inserted node 
    tail->next = newP;

    return tail;

}
//inserting a node at the end of a linked list
struct node* insertend(struct node* tail,int data){
    //creates a new node
    struct node* newP = createNode(data);
    //this points to the first node of the list
    struct node* temp = tail->next;

    //the next value of the new created node points to the address of the first node(temp) 
    newP->next = temp;
    //the prev value of the new created node points to the address of the initial last node(tail)
    newP->prev = tail;

    //the next value of the initial tail value is updated with the address of the new node
    tail->next = newP;
    //the prev value of the first node is updated with the address of the new added last node
    temp->prev = newP;

    //we then update the tail pointer to point to the new last node 
    tail = newP;

    return tail;
}
//inserting a node between the nodes
void insertbetween(struct node* tail,int pos,int data){
    //points to the first node of the list
    struct node* temp = tail->next;
    //this traverses through the list to reach the destination to insert the node
    //this is one step back the destination if pos = 4 it will go to pos 3
    while(pos>1){
        //updates temp address to point to the next node
        temp=temp->next;
        //we then decrement the pos
        pos--;
    }
    //create the node to insert
    struct node* newP = createNode(data);

    //We then update the prev part in our newly inserted node with the address of the temp(points one step back)
    newP->prev = temp;
    //we then update the next part in our newly inserted node with the address of the next part of temp which points to the next node
    newP->next = temp->next;
    //we then update the prev part of the next node with the address of the new node
    temp->next->prev = newP;
    //we then update the next part of our temp node to point to the newly inserted node
    temp->next = newP;

    //if we have updated the last node we need to update the tail pointser to point point to the last node
    if(temp==tail){
        tail = tail->next;
    }


}
//deleting the first node of the circly doubly linked list
void deleteFirstNode(struct node* tail){
    //points to the first node of the list
    struct node* temp = tail->next;
    //we update the the next part of the last node to the second node address
    tail->next = temp->next;
    //we update the prev of the second node to point to the last node(tail)
    temp->next->prev = tail;
    //we free our temp node address
    delete temp;

    //we nullify temp
    temp = nullptr;
}
//deleting the last node of the circly doubly linked list
struct node* deleteLastNode(struct node* tail){
    //stores the address of the second last node of the list
    struct node* temp = tail->prev;
    //we update the next part of the second last node to point to the address of the first node
    temp->next = tail->next;
    //we update the prev part of the first node to point to the second last node
    tail->next->prev = temp;
    //delete the tail pointer(freeing it from memory) which was the initial last node
    delete tail;
    //we update the address of the tail pointer to point to the new node
    tail = temp;

    //we return the new tail
    return tail;

}
//deleting a node at a specific position
void deleteAtPosition(struct node* tail,int pos){
    //points to the first node of the list
    struct node* temp = tail->next;
    //we then traverse the list to reach the desired location in order to delete the node
    while(pos>1){
        //we updtate temp address to pointto the next node address
        temp = temp->next;
        //we decrement pos
        pos--;
    }
    //we then create temp2 to point to the node just before the one we want to delete
    struct node* temp2 = temp->prev;
    //we update the next part of temp2(node just before the one we want to delete) to point to the next node after the one we want to delete
    temp2->next = temp->next;
    //we then update the prev part of the next node after the one we want to delete to point to the node just before the one we want to delete
    temp->next->prev = temp2;
    //we then free the node
    delete temp;

}
int main(){
    int data = 1;
    struct node* tail = new node;
    tail = circularDoubly(data);
    tail = insertbeginning(tail,2);
    tail = insertbeginning(tail,3);
    tail = insertbeginning(tail,4);
    tail = insertend(tail,3);
    insertbetween(tail,2,200);
    printAllData(tail);
    std::cout << "deleted node ........." << std::endl;
    deleteFirstNode(tail);
    printAllData(tail);
    std::cout << "delete last node ........." << std::endl;
    tail = deleteLastNode(tail);
    printAllData(tail);
    std::cout << "delete specific node ........." << std::endl;
    deleteAtPosition(tail,2);
    printAllData(tail);
}