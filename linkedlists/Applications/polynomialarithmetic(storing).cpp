#include <iostream>
#include <string>

struct node {
    float coeff;
    int expo;
    struct node *link;

};
// Function to insert a new term into the polynomial in descending order of exponents
// It returns the updated head of the list.
struct node* insert(struct node* head, float coeff, int expo) {
    struct node* newP = new node; // Create a new node
    struct node* temp;

    // Initialize the new node with provided coefficient and exponent
    newP->coeff = coeff;
    newP->expo = expo;
    newP->link = nullptr; // New node initially points to null

    // Case 1: List is empty or new term has a higher exponent than the current head
    // Insert new node at the beginning
    if (head == nullptr || expo > head->expo) {
        newP->link = head; // New node points to the old head
        head = newP;       // New node becomes the new head
    } else {
        // Case 2: Traverse the list to find the correct position for insertion
        // Nodes are stored in descending order by exponents
        temp = head;
        // Iterate while there's a next node and the next node's exponent is greater than the new term's exponent
        while (temp->link != nullptr && temp->link->expo > expo) {
            temp = temp->link; // Move to the next node
        }
        // Insert the new node at the found position
        newP->link = temp->link; // New node points to what temp was pointing to
        temp->link = newP;       // Temp now points to the new node
    }
    return head; // Return the (potentially updated) head of the list
}
struct node* create(struct node* head) {
    int n;
    float coeff;
    int expo;

    std::cout << "Enter the number of terms : ";
    std::cin >> n; // Get the number of terms from the user

    // Loop to get coefficient and exponent for each term and insert it into the list
    for (int i = 0; i < n; i++) {
        std::cout << "Enter the coefficient for term " << i + 1 << ": ";
        std::cin >> coeff;
        std::cout << "Enter the exponent for term " << i + 1 << ": ";
        std::cin >> expo;
        // Call insert to add the new term and update the head of the list
        head = insert(head, coeff, expo);
    }
    return head; // Return the head of the fully created polynomial
}
// Function to print the polynomial
void printpolynomial(struct node* head) {
    struct node* temp = head; // Start from the head of the list

    // Check if the polynomial is empty
    if (temp == nullptr) {
        std::cout << "Polynomial is empty." << std::endl;
        return;
    }

    // Traverse the list and print each term
    // The loop condition is changed to `temp != nullptr` to ensure the last node is also printed.
    while (temp != nullptr) {
        std::cout << "Coefficient: " << temp->coeff << ", Exponent: " << temp->expo;
        if (temp->link != nullptr) {
            std::cout << " -> "; // Add an arrow if it's not the last term
        }
        temp = temp->link; // Move to the next node
    }
    std::cout << std::endl; // New line at the end for better formatting
}
int main(){
    struct node* head = nullptr;
    std::cout << "Enter the polynomial" << std::endl;
    head = create(head);
    printpolynomial(head);
}