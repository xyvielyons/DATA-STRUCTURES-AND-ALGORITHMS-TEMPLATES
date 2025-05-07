#include <iostream>
#include <string>

struct node {
    int data;
    struct node *link;
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
        ptr = ptr->link;
    }
    
};

//adding a node to the end of the list
void add_at_end(struct node *head,int data){
    //create two nodes pointer and temp
    struct node *ptr, *temp;
    //assign the head pointer to the head node
    ptr = head;
    
    //we allocate dynamic memory to our temp node
    temp = new node;

    //we add the data to our data in the temp node
    //we assign the link to nullptr
    temp->data=data;
    temp->link=nullptr;

    //if pointer link adress is not equall to NULL
    while(ptr->link != NULL){
        //we update our pointer to the next address
        ptr = ptr->link;
    }

    //if pointer link is null we update the adress of the link part from null to the temps address
    //it is now pointing to the temp
    ptr->link = temp;
};

//adding a node at an empty list
struct node* add_at_end_optimized(struct node *ptr,int data){
    //creates a new temp node
    struct node *temp = new node;
    //ads the data to the temp node
    temp->data=data;
    temp->link=nullptr;

    //we then update the parsed pointer link with the new temp node address
    ptr->link = temp;
    //we return the new node temp which is the last node to be inserted
    return temp;
}

//add a node at the beginning of the list
struct node* add_at_beginning(struct node *headptr,int data){
    struct node *ptr = new node;
    ptr->data = data;
    ptr->link = NULL;

    ptr->link = headptr;
    //we update the main header pointer to the new ptr pointer
    headptr = ptr;
    return headptr;

}
//add a node at the beginning by reference
//the **headptr is like this because its a pointer to a pointer
//we need another pointer to store the address of the main pointer
struct node* add_at_beginning_reference(struct node **headptr,int data){
    struct node *ptr = new node;
    ptr->data = data;
    ptr->link = NULL;

    std::cout << *headptr << std::endl;
    //it will update the link part of the node
    ptr->link = *headptr;
    *headptr = ptr;

}


//inserting a node at certain position
//we take the head position ,data and position of insertion
void add_at_position(struct node* head,int data,int pos){
    //we create a new ptr node and copy the head node address
    struct node *ptr = head;

    //we create a new node for insertion 
    //we have named it ptr2
    struct node *ptr2 = new node;
    ptr2->data=data;
    ptr2->link=NULL;

    //we decrement the inserted position by one
    //we are moving one step back when we reach the position specified
    //if pos=3 we go to the second position/node
    pos--;
    //we traverse through the list if pos is not equal to one
    while(pos != 1){
        //we update our ptr adress as we traverse
        ptr = ptr->link;
        //as we traverse we decrement our position
        pos--;
    }
    //wehen we reach the position update our new node with the link pointing to the next node;
    //the next node address is help by the head node help by ptr
    ptr2->link = ptr->link;
    //we then update our head ptr node with the inserted node
    ptr->link = ptr2;

}

//deleting first node of the list
struct node* delete_first_node(struct node *head){
    //if head is null it means the list is empty
    if(head == NULL){
        std::cout << "List is already empty" << std::endl;
    }else{
        //we copy the head address to ptr
        struct node *ptr = head;
        //we update the head node adress to point to the next address
        head = ptr->link;
        //we delete the first node by freeing its memory
        delete ptr;
        //we return the new head address
        return head;
    }

};

//deleting last node of a single linked list
//method1: using two pointers
void delete_last_nodev1(struct node *head){

    //if head is null it means the list is empty
    if(head == nullptr){
        std::cout << "List is already empty" << std::endl;
        //if head link is null it means there is only one node
    }else if(head->link ==nullptr){
        //we free the memory of the head node which is the first node
        delete head;
        //we then reset the head address to Null
        head = nullptr;
    }else{
        //initially they all point to the head node
        //ptr1 - will point to the second last node on the list
        //ptr2 = will point to the last node of the list
        struct node *ptr1 = head;
        struct node *ptr2 = head;

        //we are using the ptr2 to treverse though the list searching for the last node
        while(ptr2->link != nullptr){
            //we will put the address of ptr2 to ptr1
            ptr1 = ptr2;
            //we will move our pointer towards right
            ptr2 = ptr2->link;

            //NB:ptr1 will point to the second last because we are moving our pointer to the next node 
        }
        //we assign NULL to ptr1->link
        //this is the second last node
        ptr1->link = nullptr; 
        //we delete the last node
        delete ptr2;
    }
}
//method2:using single pointer
void delete_last_nodev2_singlepointer(struct node *head){
    //if head is null it means the list is empty
    if(head == nullptr){
        std::cout << "List is already empty" << std::endl;
        //if head link is null it means there is only one node
    }else if(head->link ==nullptr){
        //we free the memory of the head node which is the first node
        delete head;
        //we then reset the head address to Null
        head = nullptr;
    }else{
        struct node* ptr = head;
        while(ptr->link->link != NULL){
            ptr=ptr->link;
        }

        delete ptr->link;
        ptr->link = nullptr;
    }
}

//deleting a node at a particular position
void delete_position(struct node **head,int position){
    //we create two pointers current and previous
    struct node *current = *head;
    struct node *previous = *head;

    if(*head == nullptr){
        std::cout << "List is already empty"<<std::endl;
        //if position is one it means its the first node
    }else if(position == 1){
        //we update the head node with the link of the next node;
        *head = current->link;
        //we delete the current node;
        delete current;
        //we nullify the current pointer
        current = NULL;
    }else{
        while(position!=1){
            //we update the previous adress with the current address
            previous = current;
            //we update the current to point to the second node of the list 
            current = current->link;
            //we decrement position by one
            position--;
        }
        //if position is equal to one it means we have reached to our desired node
        //we then update the previous node with the link of the next node stored in the current node
        previous->link=current->link;
        //we delete the current node
        delete current;
        //we the nullify the current pointer
        current = nullptr;
    }

}

//how to delete the whole of your linked list
struct node* delete_whole_linkedlist(struct node *head){
    //we store the address of the head in temp
    struct node *temp = head;

    //if we have deleted the whole list temp should be null because its updated Null bu the last node
    //this runs until we have deleted every node on the list
    while(temp != nullptr){
        //temp is updated by the address of the next node
        temp = temp->link;
        //we free the memory of the head address
        delete head;
        //we then update the head address with the next new node address
        head = temp;

    }
    //we return the new head address which is null
    return head;
}

//reversing a single linked list
struct node *reverse_linkedlist(struct node *head){
    struct node *previous = nullptr;
    struct node *next = nullptr;

    while(head != nullptr){
        //this will point to the second node of the list
        next = head->link;
        //in the first iteration the first node link is assigned NULL
        head->link = previous;
        //previous pointer will help us to update the second node
        //we assign the previous with the head pointer
        previous = head;
        //we update our head pointer to the current next node address
        head = next;

    }
    //we update our head with the previous which will be our first node now
    head = previous;
    //we return head
    return head;

}

int main(){
    // Creating a new node dynamically
    //we allocate memory 
    struct node *head = new node;

    // Assigning data and setting link to nullptr
    head->data = 45;
    head->link = nullptr;

    // add_at_end(head,67);
    // add_at_end(head,100);
    // add_at_end(head,1000);

    struct node *ptr = head;
    //ptr stores the new pointer adresss to the last node on the list
    ptr = add_at_end_optimized(ptr,600);
    ptr = add_at_end_optimized(ptr,1000);
    ptr = add_at_end_optimized(ptr,2000);

    //we then reset ptr with the head node
    ptr = head;

    //here we are parsing head by value not by reference
    head = add_at_beginning(head,254);
    ptr = head;
    
    //here we are parsing head by reference
    //we are parsing the adreess 0x67235746 of head
    add_at_beginning_reference(&head,368);


    add_at_position(head,2005,3);
    add_at_position(head,2006,4);

    //we are returning the new updated head node
    head = delete_first_node(head);

    delete_last_nodev1(head);

    delete_last_nodev2_singlepointer(head);

    //traversing through the linked list
    delete_position(&head,1);
    delete_position(&head,3);

    
    count_of_nodes(head);
    head = reverse_linkedlist(head);
    count_of_nodes(head);


    head = delete_whole_linkedlist(head);
    if(head == nullptr){
        std::cout << "The whole of your list has been deleted" << std::endl;
    }
//.........................................................................................
//we then point the second node to the first node through the link
    // struct node *current = new node;
    // current->data=98;
    // current->link=nullptr;
    // head->link = current;

    // current = new node;
    // current->data = 3;
    // current->link = nullptr;
    // head->link->link = current;

    // current = new node;
    // current->data = 200;
    // current->link = nullptr;
    // head->link->link->link = current;
    
    // current = new node;
    // current->data = 800;
    // current->link = nullptr;
    // head->link->link->link->link = current;

//....................................................................................................


    
    
};