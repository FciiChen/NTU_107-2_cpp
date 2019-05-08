#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int a, b, c; //the sides of triangle
    cin >> a >> b >> c;
    int side[3] = {a, b, c};

    for (int i = 0 ; i<3 ; i++){ //use bubble sort to make the array queue from small to big
        for (int j = i+1 ; j<3 ; j++){
            if (side[i] >= side[j]){
                int temp = side[j];
                side[j] = side[i];
                side[i] = temp;
            }
        }
    }

    if (pow(side[0], 2) + pow(side[1], 2) == pow(side[2], 2)){ //by Pythagorean theorem, we check wether it's a right triangle
        cout << "Yes, they can be the sides of the right triangle.\n";
    }
    else{
        cout << "No, They can't be the sides of the right triangle.\n";
    }

    return 0;
}