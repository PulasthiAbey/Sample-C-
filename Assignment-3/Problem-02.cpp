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
void read_file();
bool isEmpty(student_tag *head);


//main method
int main(){
    //calling readfile function
    read_file();
    return 0;
}

//read files details into the struct array
void read_file(){
    //creating a temparary struct and count varible
    student_tag temp;
    int total = 0;

    //creating the nodes
    student_tag *head;
    student_tag *last;

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
bool isEmpty(student_tag *head){
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}