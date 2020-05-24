//this program implements a simple linked list 
#include <iostream>
using namespace std;

//initializing the self reference struct
struct node {
    int numbers;
    struct node *next;
}; 

//initializing functions
void get_numbers(int arr[], node *&head, node *&last);
void sort(int arr[], node *&head, node *&last);
bool isEmpty(node *head);
void insertFirstElement(node *&head, node *&last, int number);
void insert(node *&head, node *&last, int arr[]);
void showList(node *current);

//main method
int main () {
    //creating the instances
    node *head = NULL;
    node *last = NULL;
    int arr[10];

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
void sort(int arr[10], node *&head, node *&last){
    int temp=0, pass=0;
    for(int i = 0; i<10; i++) {
        for(int j = i+1; j<10; j++){
            if(arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        pass++;
    }

    //insert the elements 
    insert(head, last, arr);

    //display numbers
    showList(head);

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
void insert(node *&head, node *&last, int arr[10]){
    if (isEmpty(head)){
        insertFirstElement(head, last, arr[0]);
    }
    else {
        node *temp = new node;
        for (int k=1; k<10; k++) {
            temp->numbers = arr[k];
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
         
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