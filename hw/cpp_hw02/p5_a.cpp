#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int gen_suit(){
    srand(time(0));
    int colour = rand()%4 + 1;
    return colour;
}

int gen_value(){
    srand(time(0));
    int number = rand()%13 + 1;
    return number;
}

int  guess_suit (int suit_target){
    int guess_suit;
    cout << "Plz input 1~4 (Club, Diamond, Heart, Spade) to guess the suit:";
    cin >> guess_suit;

    int guess_counter = 1;

    while(guess_suit != suit_target){
        cout << "No, please try again!\n";
        guess_counter++;

        cout << "Plz input 1~4 (Club, Diamond, Heart, Spade) to guess the suit:";
        cin >> guess_suit;
    }
    cout << "Yes, that’s right!\n\n";
    return guess_counter;
}

int  guess_value (int value_target){
    int guess_value;
    cout << "Plz input 1~13 (A~k) to guess the number:";
    cin >> guess_value;

    int guess_counter = 1;

    while(guess_value != value_target){
        
        if (guess_value > value_target){
            cout << "No, the answer is smaller!\n";
        }
        else if (guess_value < value_target){
            cout << "No, the answer is larger!\n";
        }
        
        guess_counter++;

        cout << "Plz input 1~13 (A~k) to guess the number:";
        cin >> guess_value;
    }
    cout << "Yes, that’s right!\n\n";
    return guess_counter;
}

int main(){
    int p_suit = gen_suit();
    int p_value = gen_value();

    int suit_times = guess_suit(p_suit);
    int value_times = guess_value(p_value);
    string suit;
    string value;

    switch(p_suit){
        case 1:{
            suit = "Club";
            break;
        }
        case 2:{
            suit = "Diamond";
            break;
        }
        case 3:{
            suit = "Heart";
            break;
        }
        case 4:{
            suit = "Spade";
            break;
        }
        default:{
            break;
        }
    } 
    
    switch(p_value){
        case 1:{
            value = "A";
            break;
        }
        case 2:{
            value = "2";
            break;
        }
        case 3:{
            value = "3";
            break;
        }
        case 4:{
            value = "4";
            break;
        }
        case 5:{
            value = "5";
            break;
        }
        case 6:{
            value = "6";
            break;
        }
        case 7:{
            value = "7";
            break;
        }
        case 8:{
            value = "8";
            break;
        }
        case 9:{
            value = "9";
            break;
        }
        case 10:{
            value = "10";
            break;
        }
        case 11:{
            value = "J";
            break;
        }
        case 12:{
            value = "Q";
            break;
        }
        case 13:{
            value = "K";
            break;
        }
        default:{
            break;
        }
    } 
    
    printf("The answer is: %s %s\nYou guessed\n%d times in suit, and\n%d times in value.\n", suit.c_str(), value.c_str(), suit_times, value_times);
    
    return 0;
}