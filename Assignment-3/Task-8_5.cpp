#include <iostream>
using namespace std;

//initialize functions
void reorder(int *a, int *b, int *c);
int main(){
    //initialize variables
    int aa,bb,cc;

    //get the inputs from the user
    cout<<"Insert three integers"<<endl;
    cin>>aa;
    cin>>bb;
    cin>>cc;

    //assigning the pointers
    int * a = & aa;
    int * b = & bb;
    int * c = & cc;

    //call the re-order function
    reorder(a, b, c);
    return 0;
}

void reorder(int *a, int *b, int *c){
    //compare the numbers according to the order
    if(*a>*b){
        if(*b>*c){
            cout<<"The Order is "<<*c<<","<<*b<<","<<*a<<endl;
        }
        else{
            if(*c>*a){
                cout<<"The Order is "<<*b<<","<<*a<<","<<*c<<endl;
            }
            else{
                cout<<"The Order is "<<*b<<","<<*c<<","<<*a<<endl;
            }
        }
    }
    else{
        if(*b>*c){
           if(*a>*c){
               cout<<"The Order is "<<*c<<","<<*a<<","<<*b<<endl;
           }
           else{
               cout<<"The Order is "<<*a<<","<<*b<<","<<*c<<endl;
           }
        }
        else{
           cout<<"The Order is "<<*a<<","<<*c<<","<<*b<<endl; 
        }
    }
}