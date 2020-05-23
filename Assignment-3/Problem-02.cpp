//this program is created to manage the student information using a linked list
//Student Name : 
//student ID : 
#include <iostream>
#include <fstream>
using namespace std;

//global varibles for node count
int count = 0 ;

//initializing the structs and references
struct person_tag{
    string name;
    string id;
};
struct course_tag{
    string course_name;
    int no_of_units;
    int marks[4];
    float avg;
};
struct student_tag{
    struct person_tag student_info;
    struct course_tag course_info;
    student_tag *next;
};

//initialzing the fuctions
void read_file(student_tag *&head, student_tag *&last);
bool isEmpty(student_tag *&head);
int menu();
void showList(student_tag *&current);
void linear_Search(student_tag *&current, string name);
void find_maximum(student_tag *&current, int num);
int quit();


//main method
int main(){
        //creating the nodes
    student_tag *head;
    student_tag *last;

    //calling readfile function
    read_file(head, last);

    //calling the menu function
    int x = menu();

    //determinig the response
    switch (x) {
    case 1:{
        showList(head);
        break;
    }
    case 2:{
        cout<<"Insert the name you are looking for : ";
        string name;
        cin>>name;
        linear_Search(head, name);
        break;
    }
    case 3:{
        find_maximum(head, count);
        break;
    }
    case 4:{
        quit();
        break;
    }
    default:
        cout<<"Invalid Input. Please try again\n\n";
        break;
    }
    return 0;
}

//read files details into the struct array
void read_file(student_tag *&head, student_tag *&last){
    //creating a temparary struct and count varible
    student_tag temp;
    int total = 0;

    //opening and checking for errors
   fstream sample("Students.txt", ios::in | ios::out | ios::app);
    if(sample.fail()){
        cerr<<"error while opening the file"<<endl;
        exit(1);
    }
    while (sample.eof()) {
        sample>>temp.student_info.name>>temp.student_info.id>>temp.course_info.course_name>>temp.course_info.no_of_units>>temp.course_info.marks[0]>>temp.course_info.marks[1]>>temp.course_info.marks[2]>>temp.course_info.marks[3];
        for (int i = 0; i<4; i++) {
            total = total + temp.course_info.marks[i]; 
        }
        temp.course_info.avg = total/4;

        if (isEmpty(head)){
            //insertFirstElement(head, last, temp);
            student_tag *temp1 = new student_tag;
            temp1 = &temp;
            temp1->next = NULL;
            head = temp1;
            last = temp1;
        }
        else {
            student_tag *temp1 = new student_tag;
            for (int k=1; k<10; k++) {
                temp1 = &temp;
                temp1->next = NULL;
                last->next = temp1;
                last = temp1;
            }
         
        }

        count++;
    }

    sample.close();
    
}

//empty function
bool isEmpty(student_tag *&head){
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

//menu function for the responses   
int menu(){
    int response=0;

    //displaying the options
    cout<<"1 --> Display students’ details"<<endl;
    cout<<"2 --> Search for a student’s mark"<<endl;
    cout<<"3 --> Find the details of student with the largest average"<<endl;
    cout<<"4 --> Quit program"<<endl;

    cin>>response;

    //pass the user response
    return response;
}

//quit the program
int quit(){
    cout<<"Thank you for being with us\n\t\t\tGOOD BYE!\n";
    return 0;
}

//show the the details
void showList(student_tag *&current){
    if (isEmpty(current)){
        cout<<"The List is Empty"<<endl;
    }
    else {
        cout<<"The list Contains\n";
        while (current != NULL) {
            cout<<current->student_info.name<<"\t";
            cout<<current->student_info.id<<"\t";
            cout<<current->course_info.course_name<<"\t";
            cout<<current->course_info.no_of_units<<"\t";
            cout<<current->course_info.marks[0]<<"\t";
            cout<<current->course_info.marks[1]<<"\t";
            cout<<current->course_info.marks[2]<<"\t";
            cout<<current->course_info.marks[3]<<"\t";
            cout<<current->course_info.avg<<"\t";

            current = current->next;
        }
    }

    //calling the menu function
    int x = menu();

    //determinig the response
    switch (x) {
    case 1:{
        showList(current);
        break;
    }
     case 2:{
        cout<<"Insert the name you are looking for : ";
        string name;
        cin>>name;
        linear_Search(current, name);
        break;
    }
    case 3:{
        find_maximum(current, count);
        break;
    }
    case 4:{
        quit();
        break;
    }
    default:
        cout<<"Invalid Input. Please try again\n\n";
        break;
    }
}

//void search the students marks
void linear_Search(student_tag *&current, string name){
    while (!isEmpty(current)){
        if (current->student_info.name == name){
            cout<<"The marks are ..\n";
            for (int i = 0; i<4; i++){
                cout<<current->course_info.marks[i]<<"\t";
            }
        }
        else {
             cout << "Cannot find the name" << endl;
        }
    }

    //calling the menu function
    int x = menu();

    //determinig the response
    switch (x) {
    case 1:{
        showList(current);
        break;
    }
     case 2:{
        cout<<"Insert the name you are looking for : ";
        string name;
        cin>>name;
        linear_Search(current, name);
        break;
    }
    case 3:{
        find_maximum(current, count);
        break;
    }
    case 4:{
        quit();
        break;
    }
    default:
        cout<<"Invalid Input. Please try again\n\n";
        break;
    }
}

//searching for the the maximum average value
void find_maximum(student_tag *&current, int num){
    
    int i,j,temp, pass = 0;
    //creating a temparary node for the check
    student_tag *nextVal;
    
    for(i = 0; i<num; i++) {
        current->next = nextVal;
        if(current->course_info.avg < nextVal->course_info.avg) {
            temp = current->course_info.avg;
            current->course_info.avg = nextVal->course_info.avg;
            nextVal->course_info.avg = temp;
        }
        pass++;
    }

    cout<<"The highest scoring student's details are...\n";
    cout<<nextVal->student_info.name<<endl;
    cout<<nextVal->student_info.id<<endl;
    cout<<nextVal->course_info.avg<<endl;

    //calling the menu function
    int x = menu();

    //determinig the response
    switch (x) {
    case 1:{
        showList(current);
        break;
    }
     case 2:{
        cout<<"Insert the name you are looking for : ";
        string name;
        cin>>name;
        linear_Search(current, name);
        break;
    }
    case 3:{
        find_maximum(current, count);
        break;
    }
    case 4:{
        quit();
        break;
    }
    default:
        cout<<"Invalid Input. Please try again\n\n";
        break;
    }

}