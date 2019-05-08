#include <iostream>
#include <math.h>
#include <fstream> // file stream  
using namespace std;

bool primetable[10000];

int prime_or_not(){
    int bound = 10000;

    for (int i=0 ; i<bound ; i++){ //to form a table
        primetable[i] = true;
    }

    primetable[0] = false;
    primetable[1] = false;
    for (int i=2 ; i<bound ; i++){
        if (primetable[i]){
            for (int j=i*i ; j<bound ; j += i){
                primetable[j] = false;
            }
        }
    }

    ofstream fcout( "prime_numberx.txt", ios::out );

    if ( !fcout ){ // overloaded ! operator{
        cerr << "File could not be opened" << endl;
        exit( 1 );
    } // end if

    for (int number = 2 ; number<=10000 ; number++){
        if(primetable[number]){
            cout << number << "\n";
            fcout << number << endl;
        }
    }

    return 0;
}

int main(){
    prime_or_not();
    cout << "All the prime_numbers are printed above and written in the file!\n" ;
    return 0;
}