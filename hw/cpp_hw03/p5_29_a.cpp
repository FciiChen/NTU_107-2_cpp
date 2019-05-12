#include <iostream>//we need this
#include <math.h>
#include <fstream>
using namespace std;

bool primetable[10000];//for the prime table

int prime_or_not(int number){ //a func to determine whether a num is prime
    ofstream fcout( "prime_number_a.txt", ios::out );//for output to the file

    if ( !fcout ){ // overloaded ! operator{
        cerr << "File could not be opened" << endl;
        exit( 1 );
    } // end if

    int bound = 10000;//the up bound

    for (int i=0 ; i<bound ; i++){ //to form a table to record the num between 0 to 10^4
        primetable[i] = true;//assume that all the num is prime
    }

    primetable[0] = false;//0 is not a prime 
    primetable[1] = false;//1 is mot a prime
    for (int i=2 ; i<bound ; i++){
        if (primetable[i]){//if someone is a prime its multiple
            for (int j=i*i ; j<bound ; j += i){
                primetable[j] = false;
            }
        }
    }

    if(number <= bound){ //if the num is in the table which means it's between 0 to 10^4
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
        for(int i=2 ; i<int(sqrt(number))+1 ; i++){//the table can record the num from 0 to 10000.It means if we want to see whether a num is prime the available interval can be the double of 10^4
            if (primetable[i]){
                if(number %i == 0){
                    prime = false;
                    break;//to break
                }
            }
        }
        if (prime == true){//if it's a prime do the folloings
            cout << "Yes, this is a prime number!\n";
            fcout << "Yup, " << number << " is a prime number!\n";
        }
        else if (prime != true){//if not do this
            cout << "Nah, this is not a prime number!\n";
            fcout << "Nah, " << number << " is not a prime number!\n";
        }
    }
    return 0;//we need return
}

int main(){
    cout << "Plz input a number within 0 to 10^8 to see whether it's a prime number:";//output
    int number;
    cin >> number;//input
    prime_or_not(number);//call the func

    return 0;
}