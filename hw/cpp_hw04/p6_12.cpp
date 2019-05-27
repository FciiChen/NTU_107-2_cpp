#include <iostream>
using namespace std;

int main(){
    int a[10];

    for (int i = 0 ; i < 10 ; i++){ //input the number
        cin >> a[i];
    }

    bool swap_status; //a variable to record the status of swapping

    for (int i = 0 ; i < 9 ; i++){ //improvement version of implement of bubble sort
        swap_status = false; // set it false by default
        for (int j = 0 ; j < 9-i ; j++){
            if (a[j] > a[j+1]){ //if one is larger than the next one swap them 
                int temp = a[j+1]; //classic swap code
                a[j+1] = a[j];
                a[j] = temp;
                swap_status = true; // any swap would active it
            }
        }
        if (! swap_status){ // if there's a loop that doesn't swap, we break the loop because we know the sorting is end
            break;
        }
    }

    for (int i = 0 ; i < 10 ; i++){ //output
        cout << a[i] << endl;
    }

}