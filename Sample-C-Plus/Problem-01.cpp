#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//global varibles
int count = 0;

//declaring the struct
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
};

//initializing the functions
void read_file(student_tag [], ifstream &sample);
int menu();
void display_students(student_tag [], int num);
void sort(student_tag [], int num);
void search(student_tag [], int num, string name);
void find_maximum(student_tag [], int num);
void update_file();
int quite();

//main method
int main(){
    student_tag student_array[100];
    //greeting message
    cout << "Welcome to the Student Management System" << endl;

    //creating an instance from the fstream class
    ifstream sample;
    //call read_file function
    read_file(student_array, sample);
    //calling the menu function
    int x = menu();

    switch (x)
    {
    case 1:{
        display_students(student_array, count);
        menu();
        break;
    }
    case 2:{
        sort(student_array, count);
        menu();
        break;
    }
    case 3:{
        string name;
        cout<<"Insert the name of the studnet : ";
        cin>>name;
        //calling the search function
        search(student_array, count, name);
        menu();
        break;
    }
    case 4:
        find_maximum(student_array, count);
        menu();
        break;

    case 5:
        update_file();
        menu();
        break;

    case 6:
        quite();
        menu();
        break;
    
    default:
        break;
    }


    return 0;
}

//read files details into the struct array
void read_file(student_tag s[], ifstream &sample){
    //creating a temparary struct and count varible
    student_tag temp;
    int total = 0;
   // fstream sample("Students.txt");
    //opening and checking for errors
   sample.open("Students.txt");
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

        s[count]=temp;
        count++;
    }
    
}

int menu(){
    int response=0;

    //displaying the options
    cout<<"1 --> Display students’ details"<<endl;
    cout<<"2 --> Sort the students’ details"<<endl;
    cout<<"3 --> Search for a student’s mark"<<endl;
    cout<<"4 --> Find the details of student with the largest average"<<endl;
    cout<<"5 --> Add new student to the record"<<endl;
    cout<<"6 --> Quit program"<<endl;

    cin>>response;

    //pass the user response
    return response;
}

//display function
void display_students(student_tag s[], int num){
    for (int i=0; i<num; i++) {
        cout<<"Student Name     : "<<s[i].student_info.name<<endl;
        cout<<"Student ID       : "<<s[i].student_info.id<<endl;
        cout<<"Course Name      : "<<s[i].course_info.course_name<<endl;
        cout<<"Number of Units  : "<<s[i].course_info.no_of_units<<endl;
        cout<<"Marks            : "<<s[i].course_info.marks[0]<<", "<<s[i].course_info.marks[1]<<", "<<s[i].course_info.marks[2]<<", "<<s[i].course_info.marks[3]<<endl;
        cout<<"Average of Marks : "<<s[i].course_info.avg<<endl;
    }
}

//sorting the arrays as the user required
void sort(student_tag s[], int num) {

}

//search function
void search(student_tag [], int num, string name){
    //return num;
}

//calculating the maximum average value
void find_maximum(student_tag s[], int num){

}

//update the text file
void update_file(){

}

//quit the program
int quite(){
    cout<<"Thank you for being with us\n\t\t\tGOOD BYE!";
    return 0;
}