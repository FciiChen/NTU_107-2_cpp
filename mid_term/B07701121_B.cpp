#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
#include <iomanip>

using namespace std;

int main(){
    int die1;
    int die2;
    int die3;

    int frequency3 = 0;
    int frequency5 = 0;
    int frequency8 = 0;
    int frequency11 = 0; 
    int frequency18 = 0; 
   
    srand( time(0) ); 
    for(int roll = 1; roll <= 1000000; roll++ ){
        
        die1 = 1 + rand() % 6; // first die roll
        die2 = 1 + rand() % 6; // second die roll
        die3 = 1 + rand() % 6; // third die roll
        int sum = die1 + die2 + die3; //sum up

        switch ( sum ){
            case 3:          
                frequency3++; // increment the 1s counter
                break;
            case 5:          
                frequency5++; // increment the 5s counter
                break;
            case 8:          
                frequency8++; // increment the 8s counter
                break;
            case 11:          
                frequency11++; // increment the 11s counter
                break;
            case 18:          
                frequency18++; // increment the 18s counter
                break;
        
            default: // invalid value
                break;
        }
    }

    cout << "Points" << fixed << setw( 13 ) << "Frequency" << fixed << setw( 14 ) << setprecision(2) << "Percentage" << endl; // output headers 
    cout << setw(6) <<"3" << setw( 13 ) << frequency3  << setw( 14 ) << double(frequency3)/10000
        << "\n" <<setw(6)<< "5" << setw( 13 ) << frequency5 << setw( 14 ) << double(frequency5)/10000
        << "\n" <<setw(6)<< "8" << setw( 13 ) << frequency8 << setw( 14 ) << double(frequency8)/10000
        << "\n" <<setw(6)<< "11" << setw( 13 ) << frequency11 << setw( 14 ) << double(frequency11)/10000
        << "\n" <<setw(6)<< "18" << setw( 13 ) << frequency18 << setw( 14 ) << double(frequency18)/10000 << endl;

   return 0;
} 
