#include <iostream>
using namespace std;

//initializing the self reference struct
struct node {
    int numbers;
    struct node *next;
}; 

//initializing functions
void get_numbers(int arr[], , node *&head, node *&last);
void sort(int arr[], , node *&head, node *&last);
bool isEmpty(node *head);
void insertFirstElement(node *&head, node *&last, int number);
void insert(node *&head, node *&last, int number);
void showList(node *current);

//main method
int main () {
    node *head = NULL;
    node *last = NULL;

    get_numbers(arr, head, last);
    return 0;
}
//get the inputs from the users
void get_numbers(int arr[10], node *&head, node *&last){
    cout<<"Insert 10 integers you like"<<endl;
    for (int i=0; i<10; i++) {
        cin>>arr[i];
    }

    //sort the numbers
    sort(arr, head, last);
}

//sort the numbers
void sort(int arr[10], , node *&head, node *&last){

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

//insert into the nodes
void insert(node *&head, node *&last, int number){
    if (isEmpty(head)){
        insertFirstElement(head, last, number);
    }
    else {
        node *temp = new node;
        temp->numbers = number;
        temp->next = NULL;
        last->next = temp;
        last = temp; 
    }
}

//show the list
void showList(node *current){
    if (isEmpty(current)){
        cout<<"The List is Empty"<<endl;
    }
    else {
        cout<<"The list Contains\n";
        while (current != NULL) {
            cout<<current->numbers<<endl;
            current = current->next;
        }
    }
}