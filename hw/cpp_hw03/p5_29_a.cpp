#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

bool primetable[10000];

int prime_or_not(int number){
    ofstream fcout( "prime_number_a.txt", ios::out );

    if ( !fcout ){ // overloaded ! operator{
        cerr << "File could not be opened" << endl;
        exit( 1 );
    } // end if

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

    if(number <= bound){ //if the num is in the table
        if(primetable[number]){
            cout << "Yup, this is a prime number!\n";
            fcout << "Yup, " << number << " is a prime number!\n";
        }
        else{
            cout << "Nah, this is not a prime number!\n";
            fcout << "Nah, " << number << " is not a prime number!\n";
        }
    }
    else if(number > bound){ //if num is between 10^4 ~ 10^8
        bool prime = true;
        for(int i=2 ; i<int(sqrt(number))+1 ; i++){
            if (primetable[i]){
                if(number %i == 0){
                    prime = false;
                    break;
                }
            }
        }
        if (prime == true){
            cout << "Yes, this is a prime number!\n";
            fcout << "Yup, " << number << " is a prime number!\n";
        }
        else if (prime != true){
            cout << "Nah, this is not a prime number!\n";
            fcout << "Nah, " << number << " is not a prime number!\n";
        }
    }
    return 0;
}

int main(){
    cout << "Plz input a number within 0 to 10^8 to see whether it's a prime number:";
    int number;
    cin >> number;
    prime_or_not(number);

    return 0;
}