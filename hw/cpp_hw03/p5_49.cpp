#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
#include <fstream>
#include <unistd.h>
using namespace std;

void chatter(){ //for chatter
    ofstream fcout;
    fcout.open( "CAI.txt", ios::out | ios::app);

    srand(time(0));

    int chat = 1 + rand() % 3;
    if (chat == 1){
        cout << "\n[system chatter] Oh, you are going for broke, huh?\n\n";
        fcout << "\n[system chatter] Oh, you are going for broke, huh?\n\n"; 
    }
    else if(chat == 2){
        cout << "\n[system chatter] Aw cmon, take a chance!\n\n";
        fcout << "\n[system chatter] Aw cmon, take a chance!\n\n";
    }
    else{
        cout << "\n[system chatter] You are up big. Now is the time to cash in your chips!\n\n";
        fcout << "\n[system chatter] You are up big. Now is the time to cash in your chips!\n\n";
    }
    fcout.close();
}

int rollDice(){// rolls dice, calculates and displays sum
   // pick random die values
    ofstream fcout;
    fcout.open( "CAI.txt", ios::out | ios::app);

    sleep(2);
    chatter();
    sleep(2);

    int die1 = 1 + rand() % 6; // first die roll
    int die2 = 1 + rand() % 6; // second die roll
   
    int sum = die1 + die2; // compute sum of die values

   // display results of this roll
    cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;
    fcout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;
    
    fcout.close();
    return sum; // end function rollDice
    
} // end function rollDice


int craps_game(){
    ofstream fcout;
    fcout.open( "CAI.txt", ios::out | ios::app);
   // enumeration with constants that represent the game status 
    enum Status { CONTINUE, WON, LOST }; // all caps in constants

    int myPoint; // point if no win or loss on first roll
    Status gameStatus; // can contain CONTINUE, WON or LOST

   // randomize random number generator using current time
    srand( time( 0 ) );


    int sumOfDice = rollDice(); // first roll of the dice

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
            cout << "Now redraw dices!\n";
            fcout << "Point is " << myPoint << endl;
            fcout << "Now redraw dices!\n";
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
    fcout.open( "CAI.txt", ios::trunc); // clean the now existed file
    fcout.close();
    fcout.open( "CAI.txt", ios::out | ios::app); //write from the end of the file

    int bankbalance = 1000;//as the question ask
    int wager;
    cout << "Plz enter the wager: ";
    cin >> wager;//input the wager
    fcout << "The wager you entered is: " << wager << "\n";

    while(bankbalance < wager){
        cout << "The wager you entered is larger than your bankbalance, Plz reenter!\n";
        fcout << "The wager you entered is larger than your bankbalance, Plz reenter!\n";
        cin >> wager;
        fcout << "The wager you entered is: " << wager << "\n";
    }
    cout << "\nwager Accepted!\n";
    fcout << "\nwager Accepted!\n";
    cout << "Game starts\n";
    fcout << "Game starts\n";

    fcout.close();

    int game_fate = craps_game();

    fcout.open( "CAI.txt", ios::out | ios::app); //write from the end of the file

    if (game_fate == 1){
        bankbalance += wager;
        cout << "\nYou win. The new bankbalance is: " << bankbalance << "\n";
        fcout << "\nYou win. The new bankbalance is: " << bankbalance << "\n";
    }
    else{
        bankbalance -= wager;
        cout << "\nYou lose. The new bankbalance is: " << bankbalance << "\n";
        fcout << "\nYou lose. The new bankbalance is: " << bankbalance << "\n";
        if (bankbalance == 0){
            cout << "\nSorry. You busted!\n";
            fcout << "\nSorry. You busted!\n";
        }
    }
    fcout.close();
}
