//This program implements a program that calculates and displays voltage amounts according to the resistance and current.
#include <iostream>
using namespace std;
//initializing the functions
void calcVolts(int current[10], int voltage[10], int resistance[10]);
void dispVolts(int arr1[10], int arr2[10], int arr3[10]);

int main(){
    //initalizing the arrays
    int current[10] = {2,4,6,8,2,3,5,12,3,4};
    int voltage[10];
    int resistance[10] = {12,34,54,23,43,76,23,11,24,54};

    //calling the calcVolts function and passing the arrays
    calcVolts(current, voltage, resistance);

    //display voltage values
    dispVolts(current, resistance, voltage);
    return 0;
}

void calcVolts(int current[10], int voltage[10], int resistance[10]){
    for (int i=0; i<10; i++){
        voltage[i] = current[i] * resistance[i];
    }
}

void dispVolts(int arr1[10], int arr2[10], int arr3[10]){
    cout<<"Current \t Resistance \t Voltage"<<endl;
    for (int j=0; j<10; j++){
        cout<<arr1[j]<<" \t\t"<<arr2[j]<<" \t\t"<<arr3[j]<<endl;
    }
}