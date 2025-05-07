#include <iostream>
#include <string>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct node* createfirstnode(struct node* head,int data){
    struct node* creatednode = new node;
    creatednode->prev = nullptr;
    creatednode->data = data;
    creatednode->next = nullptr;

    head = creatednode;
    return head;

}
void addAtEnd(struct node* head,int data){
    struct node* temp = new node;
    temp->prev = nullptr;
    temp->data=data;
    temp->next=nullptr;

    struct node* ptr = head;

    while(ptr->next != nullptr){
        ptr=ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;

}

struct node* createList(struct node* head){
    int NumberOfNodes;
    std::cout << "Enter the number of nodes: ";
    std::cin >> NumberOfNodes;

    if(NumberOfNodes == 0){
        return head;
    }

    int data;
    std::cout << "Enter the data of node 1: ";
    std::cin >> data;
    head = createfirstnode(head,data);


    for (int i = 1; i < NumberOfNodes; i++)
    {
        std::cout << "Enter the data for node " << i+1 << ":";;
        std::cin >> data;
        addAtEnd(head,data);
    }
    
    // std::cout <<"number of nodes inserted: "<<head->data<< std::endl;

    return head;

}
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
        count++;
    }
    std::cout <<"node count: "<< count << std::endl;
    
};

int main(){
    struct node* head = nullptr;
    head = createList(head);

    count_of_nodes(head);
}