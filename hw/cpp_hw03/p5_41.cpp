#include <iostream>
#include <fstream> // file stream  
using namespace std;

int gcd(int x, int y){// to find the gcd
    if (y == 0){ // if the smaller one is 0, means we find gcd
        cout << "The greatest common divisor of them: " << x << "\n";
        ofstream fcout; 
        fcout.open( "Greatest_Common_Divisor.txt", ios::out | ios::app);//open the file

        if ( !fcout ){ // overloaded ! operator{
            cerr << "File could not be opened" << endl;
            exit( 1 );
        } // end if

        fcout << "The greatest common divisor of those input: " << x << endl;//output to the file
        fcout.close();//close the file
    }
    else{//if y != 0, do the followings, accroding to the way question ask
        gcd(y, x % y);//recursive
    }
    
    return 0;
}

int main(){ //this is a main func
    int x, y; //declare two variables
    cout << "Plz input two positive integers to find the gcd of them\n";
    cin >> x >> y; //to input
    if (x > y){ //compare and swap
        int temp = x;
        x = y;
        y = temp;
    }

    ofstream fcout; 
    fcout.open( "Greatest_Common_Divisor.txt", ios::trunc);//clean up the file if exist
    fcout.close();//close it

    if ( !fcout ){ // overloaded ! operator{
        cerr << "File could not be opened" << endl;
        exit( 1 );
    } // end if

    fcout.open( "Greatest_Common_Divisor.txt", ios::out | ios::app);//open the file
    fcout << "The num you input is: " << x << " and " << y << "\n";
    fcout.close();//close the file

    gcd(x, y);//call the func
}