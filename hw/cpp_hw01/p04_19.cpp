#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double pi = 0;
    for (int i = 1 ; i <= 1999 ; i += 2){ // i is the denominator
        pi += pow(-1, (i-1)/2 ) * 4 / double(i); 
        //(i-1)/2 would start form 0 to 999, which would make pow(-1, (i-1)/2 ) be positive or negative
        printf("the approximate value of the first %d terms of pi is:\n%f\n", (i-1)/2 + 1, pi);
    }

    return 0;
}