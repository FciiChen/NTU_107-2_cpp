#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
#include <fstream>
#include <unistd.h>
using namespace std;

void chatter(){ //for chatter
    ofstream fcout;
    fcout.open( "wager.txt", ios::out | ios::app);//output to the end of the file

    srand(time(0));

    int chat = 1 + rand() % 3;//randomly output the chatter
    if (chat == 1){
        cout << "\n[system chatter] Oh, you are going for broke, huh?\n\n";
        fcout << "\n[system chatter] Oh, you are going for broke, huh?\n\n"; //let the program wait as if it's really working!
    }
    else if(chat == 2){
        cout << "\n[system chatter] Aw cmon, take a chance!\n\n";
        fcout << "\n[system chatter] Aw cmon, take a chance!\n\n";//let the program wait as if it's really working!
    }
    else{
        cout << "\n[system chatter] You are up big. Now is the time to cash in your chips!\n\n";
        fcout << "\n[system chatter] You are up big. Now is the time to cash in your chips!\n\n";//let the program wait as if it's really working!
    }
    fcout.close();
}

int rollDice(){// rolls dice, calculates and displays sum
   // pick random die values

    sleep(2);//let the program wait as if it's really working!
    chatter();//call the chatter func as if someone is chattering
    sleep(2);//let the program wait as if it's really working!

    int die1 = 1 + rand() % 6; // first die roll
    int die2 = 1 + rand() % 6; // second die roll
   
    int sum = die1 + die2; // compute sum of die values

    ofstream fcout;
    fcout.open( "wager.txt", ios::out | ios::app);

   // display results of this roll
    cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;
    fcout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;//output to the end of the file
    
    fcout.close();//close the file
    return sum; // end function rollDice
    
} // end function rollDice


int craps_game(){
    
   // enumeration with constants that represent the game status 
    enum Status { CONTINUE, WON, LOST }; // all caps in constants

    int myPoint; // point if no win or loss on first roll
    Status gameStatus; // can contain CONTINUE, WON or LOST

   // randomize random number generator using current time
    srand( time( 0 ) );


    int sumOfDice = rollDice(); // first roll of the dice

    ofstream fcout;
    fcout.open( "wager.txt", ios::out | ios::app);
   // determine game status and point (if needed) based on first roll
    switch ( sumOfDice ) {
        case 7: // win with 7 on first roll
        case 11: // win with 11 on first roll           
            gameStatus = WON;
            break;
        case 2: // lose with 2 on first roll
        case 3: // lose with 3 on first roll
        case 12: // lose with 12 on first roll             
            gameStatus = LOST;
            break;
        default: // did not win or lose, so remember point
            gameStatus = CONTINUE; // game is not over
            myPoint = sumOfDice; // remember the point
            cout << "Point is " << myPoint << endl;
            fcout << "Point is " << myPoint << endl;//output to the end of the file
            cout << "Not win or lose. Now roll dices again. And the rule change"<< endl;
            fcout << "Not win or lose. Now roll dices again. And the rule change"<< endl;
            break; // optional at end of switch  
    } // end switch 

    // while game is not complete
    while ( gameStatus == CONTINUE ){// not WON or LOST 
        sumOfDice = rollDice(); // roll dice again

      // determine game status
        if ( sumOfDice == myPoint ) // win by making point
            gameStatus = WON;
        else if( sumOfDice == 7 ) // lose by rolling 7 before point
            gameStatus = LOST;
    } // end while 

    fcout.close();
   // display won or lost message
    if ( gameStatus == WON )
        return 1;
    else
        return 0;

} // end main

int main(){

    ofstream fcout;
    fcout.open( "wager.txt", ios::trunc); // clean the now existed file
    fcout.close();//ensure to close the file
    fcout.open( "wager.txt", ios::out | ios::app); //write from the end of the file

    int bankbalance = 1000;//as the question ask
    int wager;//declare the wager
    cout << "Plz enter the wager: ";
    cin >> wager;//input the wager
    fcout << "The wager you entered is: " << wager << "\n";//output to the end of the file

    while(bankbalance < wager){//if wager > bankbalance, we let the user input until he/she inputs right
        cout << "The wager you entered is larger than your bankbalance, Plz reenter!\n";
        fcout << "The wager you entered is larger than your bankbalance, Plz reenter!\n";//output to the end of the file
        cin >> wager;//input
        fcout << "The wager you entered is: " << wager << "\n";//output to the end of the file
    }
    cout << "\nwager Accepted!\n";
    fcout << "\nwager Accepted!\n";//output to the end of the file
    cout << "Game starts\n";
    fcout << "Game starts\n";//output to the end of the file

    fcout.close();//close the file

    int game_fate = craps_game();//call the func

    fcout.open( "wager.txt", ios::out | ios::app); //write from the end of the file

    if (game_fate == 1){// the user win the game
        bankbalance += wager;//get wager
        cout << "\nYou win. The new bankbalance is: " << bankbalance << "\n";
        fcout << "\nYou win. The new bankbalance is: " << bankbalance << "\n";//output to the end of the file
    }
    else{//the user lose
        bankbalance -= wager;//lose wager
        cout << "\nYou lose. The new bankbalance is: " << bankbalance << "\n";
        fcout << "\nYou lose. The new bankbalance is: " << bankbalance << "\n";//output to the end of the file
        if (bankbalance == 0){
            cout << "\nSorry. You busted!\n";
            fcout << "\nSorry. You busted!\n";//output to the end of the file
        }
    }
    fcout.close();//close the file
}
