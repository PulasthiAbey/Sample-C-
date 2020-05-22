#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

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
    case 1:
        
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
    int count = 0, total = 0;

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
    return response;
}