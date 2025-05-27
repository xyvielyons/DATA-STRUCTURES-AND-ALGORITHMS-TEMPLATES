#include <iostream>
#include <string>

struct node {
    int data;
    struct node* next;
};

struct node* circularSingly(int data){
    //creating a new node
    struct node* temp = new node;
    //appending the data into the new node
    temp->data = data;
    //the next value stores the first node of the list
    temp->next = temp;
    //return temp
    return temp;
}

//we are inserting at the begginning of the circly linked list
struct node* insertbeginning(struct node* tail,int data){
    //creating a new node
    struct node* newP = new node;
    //appending the data into the new node
    newP->data=data;

    //The new node (next's value) points to the next node after it
    newP->next=tail->next;
    //The tail value is then updated to point to the new first node inserted at the beginning
    //the tail is the last node thats its (next's) value points to the first node
    tail->next=newP;
    //we then return the new tail
    return tail;
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

//Insertion of a node between the Nodes
void insertbetween(struct node* tail,int data,int pos){
    //we are going first to create the node to insert at the specified position
    struct node* newP = new node;
    newP->data = data;
    newP->next = nullptr;

    //we are going to store a pointer p pointing to the first node
    struct node* p = tail->next;
    //we will decrement the pos by one everytime until we reach our destination
    while(pos > 1){
        p=p->next;
        pos--;
    }
    // //if we are changing the last node
    // if(p==tail){
    //     //We then update the next value of the new node with the address of the first node
    //     //it is stored in the tail->next 
    //     newP->next = tail->next;
    //     //the we then update the tail->next of the previous node to point to the new last node 
    //     tail->next = newP;
    //     //we update the new tail pointer to point to the new last node
    //     tail = tail->next;
    // }else{
    //     //we then update the newp->next to point to the address of the next node
    //     newP->next = p->next;
    //     //we then update the node to point to the new node
    //     p->next = newP;
    // }

    //we then update the newp->next to point to the address of the next node
        newP->next = p->next;
        //we then update the node to point to the new node
        p->next = newP;

    if(p==tail){
        //we then update the tail value to point to the updated last node
        tail=tail->next;
    }
    
   

};
//deleting first node of the circular singly linked list
void deleteFirstNode(struct node* tail){
    //we create a pointer to point to the address of the first node
    struct node* temp = tail->next;
    //we update the next part of the last node so that it can point to the second node of the list 
    tail->next = temp->next;

    delete temp;

    temp = nullptr;


}
//deleting last node of the circular singly linked list
void deleteLastNode(struct node* tail){
    //we craete a pointer to point to the address of the first node
    struct node* temp = tail->next;
    //we will traverse the list till we reach the last node
    while(temp->next != tail){
        //we update the temp value till we reach the last node
        temp = temp->next;
    }
    //we should then update the next part of the second last node with the address of the first node
    temp->next = tail->next;
    //we free our tail node
    delete tail;
    //we then update our tail with the new adress of the last node
    tail=temp; 
} 

//deleting a node at a specific position
void deleteAtPosition(struct node* tail,int pos){
    //we create a pointer to point to the first node of the list
    struct node * temp = tail->next;
    //we traverse through the list till we reach the destination
    while(pos > 2){
        temp = temp->next;
        pos --;
    }
    //we create a pointer to point to the node that is going to be deleted
    struct node * temp2 = temp -> next;
    //we free and delete temp2(the node that was selected to be deleted )
    delete temp2;
    temp2 = nullptr;  
    //we then update the next part for the temp(second last node) to point to the last node(tail)
    temp->next = tail;
}
//counting the number of elements in a singly circly linked list
void countOfElementsInList(struct node* tail){
    //we create a variable named count to keep track of the number of nodes in the list as we traverse through the list
    int count = 0;
    //we use temp to store the address of the first node of the list 
    struct node * temp = tail->next;
    //we run the condition only if temp is not equal to tail
    //this tells us if we have reached the last node
    while(temp != tail){
        //we increment the count by one
        count++;
        //we move thr temp pointer towards right
        temp = temp->next;
    }
    count++;
    std::cout << "count value: " << count << std::endl;

}

int searchElement(struct node* tail,int element){
    //temp points to the first node of the list 
    struct node* temp = tail->next;
    //the first element index is 0;
    int index = 0;

    //we will use a do while loop so that we dont are able to traverse the list from the first node
    do{
        //if the data in the first node matches the element return theindex which is 0
        if(temp->data == element){
            return index;
        }
        //we update temp with the next vale of the node address
        temp = temp->next;
        //we then increment index
        index++;

    }while(temp !=tail->next);

    return -1 ;//if element does not exist return -1
}
int main(){
    int data = 1;
    struct node* tail = nullptr;
    tail = circularSingly(data);

    tail = insertbeginning(tail,2);
    tail = insertend(tail,3);
    insertbetween(tail,4,2);

    
  
    traversePrintAll(tail);
    std::cout << ".............." << std::endl;
    deleteFirstNode(tail);
    traversePrintAll(tail);
    std::cout << ".............." << std::endl;
    deleteLastNode(tail);
    traversePrintAll(tail);
    std::cout << "new data.............." << std::endl;
    tail = insertbeginning(tail,21);
    tail = insertbeginning(tail,22);
    tail = insertbeginning(tail,23);
    tail = insertbeginning(tail,24);
    traversePrintAll(tail);
    std::cout << ".............." << std::endl;
    deleteAtPosition(tail,3);
    traversePrintAll(tail);
    countOfElementsInList(tail);

    int myIElement = searchElement(tail,211);
    std::cout << "element number : " <<myIElement<< std::endl;
}