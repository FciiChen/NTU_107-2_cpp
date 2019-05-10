// function template
#include <iostream>
#include <fstream> // file stream  
using namespace std;

template <class T>

T Maximun (T a, T b) {
    T result;
    result = (a>b) ? a : b;
    return result;
}

int main () {
    int int_a, int_b;
    cout << "Plz input two integers\n";
    cin >> int_a >> int_b;
    
    double double_a, double_b;
    cout << "Plz input two floating-point numbers\n";
    cin >> double_a >> double_b;

    char char_a, char_b;
    cout << "Plz input two chars\n";
    cin >> char_a >> char_b;

    ofstream fcout( "template_func_whichbigger.txt", ios::out );

    if ( !fcout ){ // overloaded ! operator{
        cerr << "File could not be opened" << endl;
        exit( 1 );
    } // end if

    cout << "The Maximun of two integers is: " << Maximun(int_a, int_b) << "\n";
    cout << "The Maximun of two floating_point numbers is: " << Maximun(double_a, double_b) << "\n";
    cout << "The Maximun of two chars is: " << Maximun(char_a, char_b) << "\n";

    fcout << "The Maximun of two integers is: " << int_a << " and " << int_b;
    fcout << " is: " << Maximun(int_a, int_b) << "\n";
    fcout << "The Maximun of two floating_point numbers is: " << double_a <<  " and " << double_b;
    fcout << " is: " << Maximun(double_a, double_b) << "\n";
    fcout << "The Maximun of two chars is: " << char_a <<  " and " << char_b;
    fcout << " is: " << Maximun(char_a, char_b) << "\n";
    
  return 0;
}