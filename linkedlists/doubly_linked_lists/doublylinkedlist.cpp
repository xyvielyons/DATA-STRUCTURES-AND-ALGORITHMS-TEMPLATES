#include <iostream>
#include <string>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};
void count_of_nodes(struct node *head){
    int count = 0;
    //if the head node is NULL it means our linked list is empty
    if(head == NULL){
        std::cout << "liked list is empty" << std::endl;
    }
    //we create a new ptr and we initialize it to null
    struct node *ptr = nullptr;
    //we assign the address of the head to the ptr
    ptr = head;
    //if the ptr is not NULL which means there is another node on the list
    while (ptr != NULL)
    {
        //print the data on the list
        std::cout << ptr->data << std::endl;
        //update the ptr with the link to the next node
        ptr = ptr->next;
    }
    
};
//adding a node in an empty list
struct node* addToEmptyList(struct node* head,int data){
    struct node* temp = new node;
    //we assign previous and next node with NULL;
    temp->next=nullptr;
    temp->data=data;
    temp->prev=nullptr;
    //we update the head node with the address of the created temp node
    head = temp;
    //we return the head
    return head;

}

//adding a node at the beginning of the list
struct node* addToBeginning(struct node*head,int data){
    //we first create the node to insert
    struct node* temp = new node;
    temp->prev = nullptr;
    temp->data = data;
    temp->next = nullptr;

    //the temp's next address node points to the current head node
    temp->next = head;
    //the head's previous address points to the current temp node
    head->prev = temp;
    //head pointer is updated with the current inserted first node which is temp
    head = temp;
    //we then return head
    return head;
}
int main(){
    //creating our first head node
    struct node *head = new node;
    // //we assign previous and next node with NULL;
    // head->prev = nullptr;
    // head->data=10;
    // head->next=nullptr;


    head = addToEmptyList(head,45);

    head  = addToBeginning(head,100);

    count_of_nodes(head);

}