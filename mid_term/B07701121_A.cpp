#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    double x1,x2,x3,y1,y2,y3;
    double side[3]; //part of input

    cout << "Enter the coordinates of 1 st point in floating_point numbers(x1, y1):";
    cin >> x1 >> y1;
    
    cout << "Enter the coordinates of 2 st point in floating_point numbers(x2, y2):";
    cin >> x2 >> y2;
    
    cout << "Enter the coordinates of 3 st point in floating_point numbers(x3, y3):";
    cin >> x3 >> y3;

    side[0] = sqrt( pow(x1-x2,2) + pow(y1-y2,2) );//side0
    side[1] = sqrt( pow(x1-x3,2) + pow(y1-y3,2) );//side1
    side[2] = sqrt( pow(x3-x2,2) + pow(y3-y2,2) );//side2

    
    for (int i = 0 ; i<3 ; i++){ //to sort
        for (int j = i+1; j < 3 ; j++){
            if(side[i] < side[j]){
                double temp = side[i]; //swap
                side[i] = side[j];
                side[j] = temp;
            }
        }
    }
    //cout << side[0] << side[1] << side[2];
    string output; //substring
    double delta = pow(side[0], 2) - pow(side[1], 2) - pow(side[2], 2);//delta to decide which kind of triangle it's.
    //cout << delta;
    if (0 < delta){
        output = "obtuse triangle";
    }
    else if (0 > delta)
    {
        output = "acute triangle";
    }
    else{
        output = "right triangle";
    }
    
    //cout << side[0] << side[1] << side[2];
    
    cout << "The side lengths are\n";
    for (int i=0; i<3; i++){
        cout << setw(15) << right << scientific << setprecision(2)  << side[i]  <<"\n"; 
    }
    cout << "\nIt\'s a " + output + ".\n"; 
    


    return 0;
}