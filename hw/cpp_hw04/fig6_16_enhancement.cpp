#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

double standard_deviation_calculation(int data[50]){ // program to calculate standard_deviation
    double sum = 0;
    for (int i = 0 ; i < 50 ; i++){ // to sum up
        sum += data[i];
    }
    double average = sum/50; // to calculate the average
    
    double ans = 0; // the standard_deviation
    for (int i = 0 ; i < 50 ; i++){ 
        ans += pow(data[i] - average, 2);
    }
    ans /= 50;
    ans = sqrt(ans);
    return ans;
}

int main(){
    const int arraysize = 50;
    int data[arraysize];
    int insert;

    ifstream fin;
    fin.open("data1.txt", ios::in); //to input the data
    for (int i = 0 ; i < 20 ; i++){
        fin >> data[i];
    }
    fin.close();

    fin.open("data2.txt", ios::in); //to input the data
    for (int i = 20 ; i < arraysize ; i++){
        fin >> data[i];
    }
    fin.close();


    cout << "Unsorted array\n\n";

    for (int i = 0 ; i < arraysize ; i++){ // output
        cout << setw(5) << data[i] ;
    }

    for (int next = 1 ; next < arraysize ; next++){ // the insertion sort
        insert = data[next]; // store the value in the current element

        int moveitem = next; // initialise thelocation to lace element
        
        while(moveitem > 0 && data[moveitem - 1] < insert){ //search the location to put the current element
            data[moveitem] = data[moveitem - 1]; // shift element one slot o the right
            moveitem --;
        }
        data[moveitem] = insert; // place inserted element into the array
    }

    double sum = 0;
    for (int i = 0 ; i < 50 ; i++){ // to sum up
        sum += data[i];
    }
    double average = sum/50; 
    double standard_deviation = standard_deviation_calculation(data);
    double median = (data[24] + data[25])/2 ;


    cout << "\n\nSorted array\n\n";
    for (int i = 0 ; i < arraysize ; i++){ // output
        cout << setw(5) << data[i];
    }
    cout << "\n\n";
    cout << "the average is " << average << "\n";
    cout << "the standard_deviation is " << standard_deviation << "\n";
    cout << "the median is " << median << "\n";

    //================================= out put to the file =====================================

    ofstream fout;
    fout.open("data.txt", ios::trunc); // clean up the file if exists
    fout.close();
    fout.open("data.txt", ios::app | ios::out); // open the file and write

    fout << "Sorted array\n\n";
    for (int i = 0 ; i < arraysize ; i++){
        fout << setw(5) << data[i];
    }
    fout << "\n\n";
    fout << "the average is " << average << "\n";
    fout << "the standard_deviation is " << standard_deviation << "\n";
    fout << "the median is " << median << "\n";
}