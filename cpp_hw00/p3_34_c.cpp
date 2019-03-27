#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double factorial = 1; 
    
    int e_power; // the power of e 
    cout << "Give the desire power 'x' of the 'e', wihch is 'e^x': ";
    cin >> e_power;

    int desire_terms; //the terms you want
    cout << "Give the desire terms you want so as to approach to 'e^x': ";
    cin >> desire_terms;
    desire_terms -= 1; //because the first term is 1/0!

    double e_pow_ans = 0; 
    int num; //the upper bound of the factorial in denominator, which would be change every loop

    while(desire_terms >= 0){
        num = desire_terms; //the upper bound of the factorial in denominator
        int power = desire_terms; // the power of e you want
        factorial = 1;

        while(num > 0){
            factorial *= num;
            num -= 1;
        }
        
        e_pow_ans += pow(e_power, power)/factorial; //plus the term
        desire_terms -= 1;
    }

    printf("e^%d is approximately %f\n",e_power , e_pow_ans);

    return 0;
}