#include <iostream>
using namespace std;

int main(){
    double factorial = 1; 
    
    int desire_terms; //the terms you want
    cout << "Give the desire terms you want so as to approach to 'e': ";
    cin >> desire_terms;
    desire_terms -= 1; //because the first term is 1/0!

    double e_ans = 0; 
    int num; //the upper bound of the factorial in denominator, which would be change every loop

    while(desire_terms >= 0){ //the terms you want so as to approach "e"
        num = desire_terms; //the upper bound of the factorial in denominator
        factorial = 1;

        while(num > 0){
            factorial *= num;
            num -= 1;
        }

        e_ans += 1/factorial; //plus the term
        desire_terms -= 1;
    }

    printf("e is approximately %f\n", e_ans);

    return 0;
}