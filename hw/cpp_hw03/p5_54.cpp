// function template
#include <iostream>
#include <fstream> // file stream  
using namespace std;

template <class T>//template

T Maximun (T a, T b) {//the func returns the bigger one of two argument of kinda int, double, char
    T result;
    result = (a>b) ? a : b;//result is the bigger one
    return result;
}

int main () {
    int int_a, int_b;
    cout << "Plz input two integers\n";
    cin >> int_a >> int_b;//input part
    
    double double_a, double_b;
    cout << "Plz input two floating-point numbers\n";
    cin >> double_a >> double_b;//input part

    char char_a, char_b;
    cout << "Plz input two chars\n";
    cin >> char_a >> char_b;//input part

    ofstream fcout;
    fcout.open( "Template_which_bigger.txt", ios::trunc);//clean up the file
    fcout.close();
    

    if ( !fcout ){ // overloaded ! operator{
        cerr << "File could not be opened" << endl;
        exit( 1 );
    } // end if

    cout << "The Maximum of two integers is: " << Maximun(int_a, int_b) << "\n";
    cout << "The Maximum of two floating_point numbers is: " << Maximun(double_a, double_b) << "\n";
    cout << "The Maximum of two chars is: " << Maximun(char_a, char_b) << "\n";

    fcout.open( "Template_which_bigger.txt", ios::out | ios::app);//open the file

    fcout << "The Maximum of two integers " << int_a << " and " << int_b;//output to the end of the file
    fcout << " is: " << Maximun(int_a, int_b) << "\n";//output to the end of the file
    fcout << "The Maximum of two floating_point numbers " << double_a <<  " and " << double_b;//output to the end of the file
    fcout << " is: " << Maximun(double_a, double_b) << "\n";//output to the end of the file
    fcout << "The Maximum of two chars " << char_a <<  " and " << char_b;//output to the end of the file
    fcout << " is: " << Maximun(char_a, char_b) << "\n";//output to the end of the file
    
    fcout.close();
  return 0;
}