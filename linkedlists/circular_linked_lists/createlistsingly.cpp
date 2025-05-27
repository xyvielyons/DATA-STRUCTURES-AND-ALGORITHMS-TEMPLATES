#include <iostream>
#include <string>

struct node {
    int data;
    struct node* next;
};

struct node* NewEmpty(int data){
    struct node* newP = new node;
    newP->data = data;
    newP->next = newP;
    return newP;

}
//we are inserting at the end of the circly linked list
struct node* insertend(struct node* tail,int data){
    //we create the new node to store the data
    struct node * newP = new node;
    //we store the data innto the new node
    newP->data = data;
    //We then update the next value of the new node with the address of the first node
    //it is stored in the tail->next 
    newP->next = tail->next;
    //the we then update the tail->next of the previous node to point to the new last node 
    tail->next = newP;
    //we update the new tail pointer to point to the new last node
    tail = tail->next;
    return tail;
}
struct node* createList(struct node* tail){
    int i,n,data;
    std::cout <<  "Enter the number of nodes of the linked list:";
    std::cin >> n;

    if(n==0){
        return tail;
    }

    std::cout << "Enter the data for node 1: ";
    std::cin >> data;
    tail = NewEmpty(data);

    for (i = 1; i < n; i++)
    {
        std::cout << "enter the data for node " << i+1 << ": ";
        std::cin >> data;
        tail = insertend(tail,data);

    }
    
    return tail;
}
//we are traversing the whole singly circular linked list and print
void traversePrintAll(struct node* tail){
    //we create a pointer that points to the first node at the beginning
    //we use the last node because its now storing the first address of the linked list
    struct node* p = tail->next;

    //if p is equal to tail next it means we have rreached the end of the list 
    //this is because tail->next is storiing the pointer o fthe first node
    //But we have a PROBLEM !!!! upon the first node at the begginning of the list p is equal to tail->next

    //...............................................................................
    // while(p!=tail->next){
    //     std::cout<< "data: " << p->data << std::endl;
    //     //we then update the p value to the address of the next node
    //     p = p->next;
    // }
    //................................................................................
    
    //we use a do while loop because we first perform the procedure then we check the condition
    //this is because we are not checking the condition for the first time
    do{
        std::cout<< "data: " << p->data << std::endl;
         //we then update the p value to the address of the next node
        p = p->next;
    }while(p!=tail->next);


}
int main(){
    struct node* tail = nullptr;
    tail = createList(tail);
    traversePrintAll(tail);
};