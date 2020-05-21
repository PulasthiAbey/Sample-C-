#include <iostream>
#include <iostream>
using namespace std;

//initializing the functions
struct Emp get_data(Emp []);
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
    company_detail cmp_detail;
};

int main(){

    //declaring the arrays
    Emp employee[5];

    //calling the functions
    get_data(employee);    

    return 0;
}

Emp get_data(Emp w[5]){
    int count = 0;
    cout<<"Insert the Number of Employees : ";
    cin>>count;

    //insert details to the array
    while (count!=0){
        cout<<"Insert the name of the employee : ";
        cin>>w[count].emp_name;

        cout<<"Insert the Employee ID : ";
        cin>>w[count].emp_id;

        cout<<"Insert the employee salary : ";
        cin>>w[count].salary;

        cout<<"Insert Company Name : ";
        cin>>w[count].cmp_detail.company_name;

        cout<<"Insert company ID : ";
        cin>>w[count].cmp_detail.company_id;

        count--;
    }

    return w;   

}