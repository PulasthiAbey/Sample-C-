#include <iostream>
using namespace std;

//initializing the self reference struct
struct node {
    int numbers;
    struct node *next;
}; 

//initializing functions
bool isEmpty(node *head);
void insertFirstElement(node *&head, node *&last, int number);
void insert(node *&head, node *&last, int number);
void showList(node *current);

//main method
int main () {


    return 0;
}

//empty function
bool isEmpty(node *head){
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

//insert the first element
void insertFirstElement(node *&head, node *&last, int number){
    node *temp = new node;
    temp->numbers = number;
    temp->next = NULL;
    head = temp;
    last = temp;
}