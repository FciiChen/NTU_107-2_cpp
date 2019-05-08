#include <iostream>
using namespace std;

int main(){
    int factorial = 1;

    for (int i = 1 ; i <= 5 ; i++){ //times from 1 to 5
        factorial *= i;
        printf("%d! is equal to %d\n", i, factorial);//everytime we times, we print the result
    }
    
}
