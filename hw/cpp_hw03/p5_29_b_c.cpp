#include <iostream>
#include <math.h>
#include <fstream> // file stream  
using namespace std;

bool primetable[10000];//declare a bool array

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

    ofstream fcout;
    fcout.open( "prime_number_b_c.txt", ios::out | ios::app);

    int counter = 1;

    for (int number = 2 ; number<=10000 ; number++){
        if(primetable[number]){
            cout << "No." << counter << ": " << number << "\n";
            fcout << "No." << counter++ << ": " << number << endl; //output to the file
        }
    }

    fcout.close();

    return 0;
}

int main(){
    ofstream fcout;
    fcout.open( "prime_number_b_c.txt", ios::trunc ); //clean up the file

    if ( !fcout ){ // overloaded ! operator{
        cerr << "File could not be opened" << endl;
        exit( 1 );
    } // end if
    fcout.close();

    prime_or_not();//call the func

    cout << "\nAll the abovementioned prime_numbers are written in the file!\n" ;
    return 0;
}