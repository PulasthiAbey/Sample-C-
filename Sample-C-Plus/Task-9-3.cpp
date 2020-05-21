#include <iostream>
#include <string>
using namespace std;

//initializin the enum for genre
enum genre{
    pop,
    Jazz,
    Classic
};

//initializing the struct
struct album {
    string album_name;
    genre kind;
    int trach_number;
    string tracks[5];
    string tracklocation;
};


//initializing the functions
void add_album(album);

//main method
int main(){
    //struct instance
    album w;

    //initializing the program
    cout<<"Enter the Option"<<endl;
    cout<<"\t 1 to add an album"<<endl;
    cout<<"\t 2 to print an album"<<endl;
    cout<<"\t 3 to play an album"<<endl;
    cout<<"\t 4 Exit"<<endl;

    int x;
    cin>>x;

    //determinging the functions and activities
    if(x==1){
        add_album(w);
    }
    else {
        if (x==2){

        }
        else {
            if (x==3) {

            }
            else {
                if (x==4){

                }
                else {
                    cout<<"The inserted respose is not calid. Please run the program again"<<endl;  
                }
            }
        }
    }

    return 0;
}

void add_album(album w){

}