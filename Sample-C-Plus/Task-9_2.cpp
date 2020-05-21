#include <iostream>
#include <iostream>
using namespace std;

//initializing the functions
struct Emp get_data(Emp [], int count);
void print_data(Emp[], int count);
double get_average(Emp [], int count, string companyName);
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

    int count = 5;
   
    //calling the functions
    get_data(employee, 5);    
    print_data(employee, 5);

    cout<<"Insert the company name you need : ";
    string company;
    cin>>company;

    //call the average function
    get_average(employee, count, company);
    return 0;
}

//read data for the array of structure
Emp get_data(Emp w[5], int count){
    

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

        cout<<endl<<endl;

        count--;
    }

   

    return w[count];
}

//print data form the struct
void print_data(Emp w[5], int count){
    while (count!=0) {
        cout<<"Employee Name   : "<<w[count].emp_name<<endl;
        cout<<"Employee ID     : "<<w[count].emp_id<<endl;
        cout<<"Employee Salary : "<<w[count].salary<<endl;
        cout<<"Company Name    : "<<w[count].cmp_detail.company_name<<endl;
        cout<<"Company ID      : "<<w[count].cmp_detail.company_id<<endl;

        cout<<endl<<endl;
        count--;
    }
}

//calculate the average salary for the each company
double get_average(Emp w[5], int count, string companyName){
    double avg;

    enum companies = {w[0].cmp_detail.company_name, w[1].cmp_detail.company_name, w[2].cmp_detail.company_name, w[3].cmp_detail.company_name, w[4].cmp_detail.company_name};
    


    return avg;
}