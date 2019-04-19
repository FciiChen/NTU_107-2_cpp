#include <iostream>
using namespace std;

int main(){
    cout << "Plz input 12 numbers to get the max and second num:\n";

    int a[12];
    for (int i = 0 ; i < 12 ; i++){ //input the 12 variables
        cin >> a[i];
    }

    for (int i = 0 ; i < 12 ; i++){ //bubble sort
        for (int j = i+1 ; j < 12 ; j++){
            if (a[i] < a[j]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }      
        }
    }
/*
    for (int i = 0 ; i < 12 ; i++){
        cout << a[i] << " ";
    }
*/
    cout << "The Max one is " << a[0] << "\n";
    cout << "The Second one is " << a[1] << "\n";
    
}