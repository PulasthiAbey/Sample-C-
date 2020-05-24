//This program implements a media playlist
#include <iostream>
#include <string>
//#include <windows.h>
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
int initiateFunction();
void print_all_album(album);
void select_track_to_play(album);
int exit();

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
            print_all_album(w);
        }
        else {
            if (x==3) {
                select_track_to_play(w);
            }
            else {
                if (x==4){
                    exit();
                }
                else {
                    cout<<"The inserted respose is not calid. Please run the program again"<<endl;  
                }
            }
        }
    }

    return 0;
}

//initializing function
int initiateFunction(){
    int n=0;

    cout<<"Enter the Option"<<endl;
    cout<<"\t 1 to add an album"<<endl;
    cout<<"\t 2 to print an album"<<endl;
    cout<<"\t 3 to play an album"<<endl;
    cout<<"\t 4 Exit"<<endl;

    cin>>n;

    return n;
}


//add album function
void add_album(album w){
    int x,y;

    cout<<"Enter Album Name : ";
    cin>>w.album_name;
    
    cout<<"Enter genre\n \t0-->pop \t1-->Jazz \t2-->Classic"<<endl;
    cin>>x;

    w.kind = static_cast<genre>(x);

    cout<<"enter the number of tracks in the album : ";
    cin>>y;

    w.trach_number=y;

    cout<<"Enter the track names"<<endl;
    while (y!=0) {
        cin>>w.tracks[y];
        y--;
    }

    cout<<"Enter the file location for the tracks : ";
    cin>>w.tracklocation;
    cout<<endl<<endl;

    int val = initiateFunction();

    //determinging the functions and activities
    if(val==1){
        add_album(w);
    }
    else {
        if (val==2){
            print_all_album(w);
        }
        else {
            if (val==3) {
                select_track_to_play(w);
            }
            else {
                if (val==4){
                    exit();
                }
                else {
                    cout<<"The inserted respose is not calid. Please run the program again"<<endl;  
                }
            }
        }
    }
    
}

void print_all_album(album w){
    //displaying the values
    cout<<"The Album Name is : "<<w.album_name<<endl;
    cout<<"The Genre of the album : "<<w.kind<<endl;
    cout<<"No of tracks : "<<w.trach_number<<endl;
    cout<<"The tracks are : "<<endl;
    for (int i=0; i<w.trach_number; i++) {
        cout<<w.tracks[i]<<endl;;
    }
    cout<<"Tracks are located at "<<w.tracklocation<<endl;

    int val = initiateFunction();

    //determinging the functions and activities
    if(val==1){
        add_album(w);
    }
    else {
        if (val==2){
            print_all_album(w);
        }
        else {
            if (val==3) {
                select_track_to_play(w);
            }
            else {
                if (val==4){
                    exit();
                }
                else {
                    cout<<"The inserted respose is not calid. Please run the program again"<<endl;  
                }
            }
        }
    }
    
}

void select_track_to_play(album w) {
    //getting the trak name
    cout<<"Select a track to play :";
    string name;
    cin>>name;
/*
    //play the sound track
    bool played = PlaySound(name, NULL, SND_SYNC);
*/
    int val = initiateFunction();
    //determinging the functions and activities
    if(val==1){
        add_album(w);
    }
    else {
        if (val==2){
            print_all_album(w);
        }
        else {
            if (val==3) {
                select_track_to_play(w);
            }
            else {
                if (val==4){
                    exit();
                }
                else {
                    cout<<"The inserted respose is not calid. Please run the program again"<<endl;  
                }
            }
        }
    }

}

int exit() {
    return 0;
}