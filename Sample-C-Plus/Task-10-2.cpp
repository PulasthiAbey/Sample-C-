#include <iostream>
using namespace std;

//initializing the struct
struct studentname {
    char letter;
    studentname *next;
};

//defining the functions
bool isEmpty(studentname *head);
void insertFirstElement(studentname *&head, studentname *&last, char letter);
void insert(studentname *&head, studentname *&last, char letter);
void showList(studentname *current);

int main() {
    studentname *head = NULL;
    studentname *last = NULL;

    //calling functions ffor the insertions
    insertFirstElement(head, last, 'P');
    insert(head, last, 'o');
    insert(head, last, 'n');
    insert(head, last, 't');
    insert(head, last, 'i');

    //diplaying the linked list
    showList(head);

    return 0;
}

bool isEmpty(studentname *head){
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void insertFirstElement(studentname *&head, studentname *&last, char letter) {
    studentname *temp = new studentname;
    temp->letter = letter;
    temp->next = NULL;
    head = temp;
    last = temp;
}

void insert(studentname *&head, studentname *&last, char letter) {
    if (isEmpty(head)){
        insertFirstElement(head, last, letter);
    }
    else {
        studentname *temp = new studentname;
        temp->letter = letter;
        temp->next = NULL;
        last->next = temp;
        last = temp; 
    }
}

void showList(studentname *current){
    if (isEmpty(current)){
        cout<<"The List is Empty"<<endl;
    }
    else {
        cout<<"The list Contains\n";
        while (current != NULL) {
            cout<<current->letter<<endl;
            current = current->next;
        }
    }
}