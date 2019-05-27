#include <iostream>
using namespace std;

int main(){
    int a[10];

    for (int i = 0 ; i < 10 ; i++){ //input the numbers
        cin >> a[i];
    }

    for (int i = 0 ; i < 9 ; i++){ //implement of bubble sort
        for (int j = 0 ; j < 9 ; j++){
            if (a[j] > a[j+1]){ //if one is larger than the next one swap them 
                int temp = a[j+1]; //classic swap code
                a[j+1] = a[j];
                a[j] = temp;    
            }
        }
    }

    for (int i = 0 ; i < 10 ; i++){ //output
        cout << a[i] << endl;
    }

}