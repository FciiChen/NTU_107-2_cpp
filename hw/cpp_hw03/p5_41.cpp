#include <iostream>
#include <fstream> // file stream  
using namespace std;

int gcd(int x, int y){
    if (y == 0){
        cout << "The greatest common divisor of them: " << x << "\n";
        ofstream fcout( "Greatest_Common_Divisor.txt", ios::out );

        if ( !fcout ){ // overloaded ! operator{
            cerr << "File could not be opened" << endl;
            exit( 1 );
        } // end if

        fcout << "The greatest common divisor of those input: " << x << endl;
    }
    else{
        gcd(y, x % y);
    }
    return 0;
}

int main(){
    int x, y;
    cout << "Plz input two positive integer to find the gcd of them\n";
    cin >> x >> y;
    if (x > y){
        int temp = x;
        x = y;
        y = temp;
    }
    
    gcd(x, y);
}