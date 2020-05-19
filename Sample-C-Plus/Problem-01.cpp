#include <iostream>
#include <fstream>
#include <string>
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
void read_file(student_tag []);

int main(){
    student_tag student_array[100];
    //greeting message
    cout << "Welcome to the Student Management System" << endl;
    return 0;
}

void read_file(student_tag s[]){

}