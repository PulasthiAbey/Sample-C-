#include <iostream>
using namespace std;
//initializing the functions
struct Emp get_data();
void print_data(struct Emp[], int);
double get_average(struct Emp*, int,string);
double get_salary(struct Emp[], string);

//initializing the structs
struct company_detail{
    string company_id;
    string company_name;
};

struct Emp{
    string emp_name;
    string emp_id;
    double salary;
    struct company_detail cmp_detail;
};

int main(){

    //declaring the arrays
    Emp employee[5];    

    return 0;
}

struct Emp get_data(){
    
}