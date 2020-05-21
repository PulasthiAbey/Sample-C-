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

int main(){


    return 0;
}