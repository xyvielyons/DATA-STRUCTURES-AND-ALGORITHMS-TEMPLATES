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
        count++;
    }
    std::cout <<"node count: "<< count << std::endl;
    
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

void addToEnd(struct node*head, int data){
    //we first create the node
    struct node* temp = new node;
    temp->data=data;
    temp->next=nullptr;
    temp->prev=nullptr;
    
    //we create a ptr to point at the head node initially
    struct node* ptr = head;
    //we treverse through the list to reach the end node 
    //the end node has its next pointer assigned to NULL
    while(ptr->next != nullptr){
        ptr = ptr->next;
    }
    //we then assign the last node next address to point to our new node
    ptr->next = temp;
    temp->prev = ptr;
    

}
struct node* add_at_position(struct node* head,int data,int position){
    //stores the address of the new node that will be inserted
    struct node* newP = nullptr;
    //stores the address of the head node
    //it depends on the position variable e.g if pos=2 it is going to point at position one
    struct node* temp = head;
    //this will point to the node at position 2
    struct node* temp2 = nullptr;

//we have now access to the addresses of the two nodes at position one and 2

    //creating a new node in the list
    newP = addToEmptyList(newP,data);


    while(position != 1){
        //we update the address of the temp to point to the next node
        temp = temp->next;
        //we then decrement the position until we reach our destination
        position--;
    }
    if(temp->next == nullptr){
        //we append the address to the next part of the last node
        temp->next = newP;
        //we update the previous part of the inserted node
        newP->prev = temp;
    //adding at beginning of list
    }else if(position == 1){
        head = addToBeginning(head,data);
    }
    else{
        //we update the address of to point to the second next node
        temp2 = temp->next;
        
        //the first node next value is updated with the new address of the inserted node
        temp->next = newP;
        // the second node previous value is updated with the inserted address of the node
        temp2->prev = newP;

        //the new node next adress is updated with the second (next) node address
        newP->next = temp2;
        //the new node previous adress is updated with the previous(first) node address
        newP->prev = temp;
    }

    return head;

};


struct node* delete_first_node(struct node* head){
    //initially the head points to the forst node of the linked list
    struct node* temp = nullptr;
    //we store the address of the head in the temp
    temp=head;
    //we then make head point to the next node
    head=head->next;

    //we free the address in the temporary first node
    delete temp;
    //we nullify temp 
    temp=nullptr;
    //we then nullyfy the prev of the current first node
    head->prev = nullptr;

    //we then return head
    return head;
}

void delete_last_node(struct node* head){
    //initially points to the head node and traverses though the list to reach the last node
    struct node* temp = nullptr;
    //through the last node we obtain the previous node which we store its address here
    struct node* temp2 = nullptr;
    //we point the address of the head to temp 
    temp=head;

    //we then traverse through the list to reach the last node
    while(temp->next != NULL){
        temp = temp->next;
    }
    //we then update temp2 address to the address of the previous node of the last node
    temp2 = temp->prev;
    //we then nullify the next address to remove i from the list
    temp2->next = nullptr;
    //we free the memory held by the removed node
    delete temp;
    //nullify the temp 
    temp = nullptr;

}
struct node* delete_intermediate_node(struct node* head,int position){
    struct node* temp = nullptr;
    struct node* temp2 = nullptr;

    //initially temp points to the head node
    temp = head;
    if(position == 1){
        head = delete_first_node(head);
        return head;
    }
    //This loop moves the temp pointer forward until it reaches the node just before the one we want to delete.
    //For example, if position = 3, temp will end up at position 2 (the node before the one to delete).
    while(position > 1){
        temp = temp->next;
        position --;
    }
    if(temp->next ==nullptr){
        struct node* headaddress = head;
        delete headaddress;
        headaddress = nullptr;
        head = nullptr;
        
    }
    else{
        //temp2 will point to the node just before the one we would want to delete
        temp2 = temp->prev;
        //we then update the next node with the next node in the list
        temp2->next = temp->next;
        //we update the previous node address of the next node on the list to point to the correct previous node
        temp->next->prev = temp2;
        //we then free our node
        delete temp;
        temp = nullptr;
    }
    

}

struct node* reverse_linkedlist(struct node* head){
    //this points to the head node
    struct node* ptr1 = head;
    //ptr2 points to the second node initially
    struct node* ptr2 = ptr1->next;

    ptr1->next = nullptr;
    ptr1->prev = ptr2;

    while(ptr2 != nullptr){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
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

    addToEnd(head,200);
    addToEnd(head,600);
    addToEnd(head,700);

    head = add_at_position(head,2,3);

    count_of_nodes(head);

    head = delete_first_node(head);

    count_of_nodes(head);

    delete_last_node(head);

    count_of_nodes(head);

    head = delete_intermediate_node(head,1);
    
    count_of_nodes(head);

    head = reverse_linkedlist(head);
    
    count_of_nodes(head);
}