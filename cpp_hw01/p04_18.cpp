#include <iostream>
#include <iomanip> 
#include <math.h> 
using namespace std;

int main(){
    cout << "the binary_decimal of 1 to 256 is :\n"; //binary_decimal
    for(int i = 1 ; i <=256 ; i++){
        int power = 0;
        int now_num = i;

        while(1){ //to get the highest power of the num, for example, 129 is bigger that 2^7, so it's highest power is 7
            if(i / int(pow(2, power+1)) != 0){
                power += 1;
            }
            else{
                break;
            }
        }

        for (int j = 1 ; j <= 8-power ; j++){ //to add 0 for the reason of layout 
            cout << 0;
        }
        for (int j = power ; j >= 0 ; j--){ //to print out the binary_demical
            cout << now_num / int(pow(2, j));
            if (now_num >= pow(2, j)){
                now_num -= pow(2, j);
            }
        }

        cout << " "; //for layout
        if (i % 10 == 0){
            cout << "\n";
        }
    }
    cout << "\n\n";


    cout << "the octal_decimal of 1 to 256 is :\n"; //octal_decimal
    for(int i = 1 ; i <=256 ; i++){
        cout << setw(3) << oct << i <<" ";

        if (i % 8 == 0){ //for  layout 
            cout << "\n";
        }
    }
    cout << "\n\n";


    cout << "the hexa_decimal of 1 to 256 is :\n"; //hexa_decimal
    for(int i = 1 ; i <=256 ; i++){
        cout << setw(3) << hex << i <<" ";

        if (i % 16 == 0){ //for  layout 
            cout << "\n";
        }
    }
    cout << "\n\n";
    
    return 0;
}