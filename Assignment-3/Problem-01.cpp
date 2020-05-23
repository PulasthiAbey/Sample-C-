//this program is created to manage the student information using a multiple structs
//Student Name : 
//Student ID : 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ncurses.h>
//#include <conio.h>
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
void read_file(student_tag []);
int menu();
void display_students(student_tag [], int num);
void sort(student_tag [], int num);
void search(student_tag [], int num, string name);
void find_maximum(student_tag [], int num);
void update_file(student_tag []);
int quite();

//sorting functions initializing
void sortByMarks (student_tag [], int num);
void sortByName (student_tag [], int num);


//main method
int main(){
    student_tag student_array[100];
    //greeting message
    cout << "Welcome to the Student Management System" << endl;

    //creating an instance from the fstream class
    fstream sample;
    //call read_file function
    read_file(student_array);
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
    case 4:{
        find_maximum(student_array, count);
        menu();
        break;
    }
    case 5:{
        update_file(student_array);
        menu();
        break;
    }
    case 6:
        quite();
        menu();
        break;
    
    default:
        cout<<"Response is not valid"<<endl;
        menu();
        break;
    }


    return 0;
}

//read files details into the struct array
void read_file(student_tag s[]){
    //creating a temparary struct and count varible
    student_tag temp;
    int total = 0;
   //creating the file instance
   fstream sample("Students.txt", ios::in | ios::out | ios::app);
    //opening and checking for errors
   //sample.open("Students.txt", ios::in, ios::out, ios::app);
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

    sample.close();
    
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
    cout<<"1 -> Sort by Name\n";
    cout<<"2 -> Sort by Average Marks\n";
    int method;
    cin>>method;

    if (method == 1){
        //sortByName(s, 6num);
        clrscr();
	    int i, j;
	
        for(i=1; i<num; i++){
		    for(j=1; j<num; j++){
			    if(strcmp(s[j-1].student_info.name, s[j].student_info.name)>0){
				    strcpy(t, str[j-1]);
				    strcpy(str[j-1], str[j]);
				    strcpy(str[j], t);
			    }
		    }
	    }
	    cout<<"Names in alphabetical order : \n";
	    for(i=0; i<5; i++){
		    cout<<str[i]<<"\n";
	    }
	    getch();
    }
    else {
        if (method == 2 ) {
            int i,j,temp, pass = 0;
            for(i = 0; i<num; i++) {
                for(j = i+1; j<num; j++) {
                    if(s[j].course_info.avg < s[i].course_info.avg) {
                    temp = s[i].course_info.avg;
                    s[i].course_info.avg = s[j].course_info.avg;
                    s[j].course_info.avg = temp;
                    }
                }
                pass++;
            }

            cout <<"Sorted List ...\n";
            for(i = 0; i<num; i++) {
                cout <<s[i].student_info.name<<"\t"<<s[i].course_info.avg<<endl;
            }
        }
        else {
            cout<<"Invalid Input. Try Again\n";
            sort(s, num);
        }
    }

    
}

//search function
void search(student_tag s[], int num, string name){
    //return num;
    cout<<"Insert the sorting method : "<<endl;
    cout<<"1    -   Binary Search\n";
    cout<<"2    -   Linear Search\n";
    int method;
    cin>>method;

    //binary search
    if (method == 1) {
        int first = 0;
	    int last = num-1;
	    int middle = (first+last)/2;
	    while (first <= last){
	        if(s[middle].student_info.name != name){
		        first = middle + 1;
     	    }
	        else if(s[middle].student_info.name == name){
		        cout<<name<<" found in the location "<<middle+1<<"\n"; 
                break; 
            } 
            else { 
                last = middle - 1; 
            } 
            middle = (first + last)/2; 
        } 
        if(first > last){
	        cout<<name<<" not found";
	    }
    }
    //linear search
    else {
        if (method == 2) {
            for (int j = 0; j < num; j++ ){
                if (s[j].student_info.name == name) {
                   cout<<name<<" found in the location "<<j<<endl;
                }
                else {
                    cout << "didn't find it" << endl;
                }
            }
        }
        else {
            cout<<"Invalid input try again\n";
            search(s, count, name);

        }
    }

    
}

//calculating the maximum average value
void find_maximum(student_tag s[], int num){
    int i,j,temp, pass = 0;
    for(i = 0; i<num; i++) {
        for(j = i+1; j<num; j++) {
            if(s[j].course_info.avg < s[i].course_info.avg) {
            temp = s[i].course_info.avg;
            s[i].course_info.avg = s[j].course_info.avg;
            s[j].course_info.avg = temp;
      }
    }
    pass++;
    }

    cout<<"The highest scoring student's details are...\n";
    cout<<s[num].student_info.name<<endl;
    cout<<s[num].student_info.id<<endl;
    cout<<s[num].course_info.avg<<endl;


}

//update the text file
void update_file(student_tag s[]){
    //creating a file instance
    fstream sample("Students.txt", ios::in | ios::out | ios::app);
    
    if (!sample.is_open()){
        cout<<"Error while opening the file\n";
    }
    else {
        cout<<"Insert the number of tudents you are going to add : ";
        int num;
        cin>>num;

        //creating a temparary struct
        student_tag temp;

        for (int i=count; i<(count+num); i++){
            cout<<"Insert the name of the student : ";
            cin>>temp.student_info.name;

            cout<<"Insert the Student ID : ";
            cin>>temp.student_info.id;

            cout<<"Insert the course name : ";
            cin>>temp.course_info.course_name;

            cout<<"Insert the number of units : ";
            cin>>temp.course_info.no_of_units;

            cout<<"Insert the marks : ";
            for (int j=0; j<4; j++) {
                cin>>temp.course_info.marks[j];
            }

            sample<<temp.student_info.name<<"\t"<<temp.student_info.id<<"\t"<<temp.course_info.course_name<<"\t"<<temp.course_info.no_of_units<<"\t"<<temp.course_info.marks[0]<<"\t"<<temp.course_info.marks[1]<<"\t"<<temp.course_info.marks[2]<<"\t"<<temp.course_info.marks[3];    
        }
    }
    sample.close();

    //calling the read file function
    read_file(s);
}

//quit the program
int quite(){
    cout<<"Thank you for being with us\n\t\t\tGOOD BYE!\n";
    return 0;
}