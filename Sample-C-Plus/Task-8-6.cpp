#include <iostream>
using namespace std;
//initializing the functions
void calcVolts(int current[10], int voltage[10], int resistance[10]);
void dispVolts(int *&arr1[10], int *&arr2[10], int *&arr3[10]);

int main(){
    //initalizing the arrays
    int current[10];
    int voltage[10];
    int resistance[10];

    //calling the calcVolts function and passing the arrays
    calcVolts(current, voltage, resistance);

    //assign the pointers to the arrays
    int *arr1 = &current[10];
    int *arr2 = &resistance[10];
    int *arr3 = &voltage[10];
    //display voltage values
    dispVolts(arr1, arr2, arr3);
    return 0;
}

void calcVolts(int current[10], int voltage[10], int resistance[10]){
    for (int i=0; i<10; i++){
        voltage[i] = current[i] * resistance[i];
    }
}

void dispVolts(int *&arr1[10], int *&arr2[10], int *&arr3[10]){
    cout<<"Current \t Resistance \t Voltage"<<endl;
    for (int j=0; j<10; j++){
        cout<<arr1[j]<<" \t"<<arr2[j]<<" \t"<<arr3[j]<<endl;
    }
}