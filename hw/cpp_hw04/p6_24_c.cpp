#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void clearBoard( int workBoard[8][8] ){  // to  initialise the board
    for (int row = 0 ; row < 8 ; row++){
       for (int col = 0; col < 8 ; col++ ){
           workBoard[ row ][ col ] = 0;
       }
   }
}

void printBoard( int workBoard[8][8] ){ // to print the board
    int row, col;

    printf( "   0  1  2  3  4  5  6  7\n" ); // the tittle of column

    for ( row = 0; row < 8; row++ ){ // the tittle of row
        printf( "%d", row );

        for ( col = 0; col < 8; col++ ){ // the board contained
            printf( "%3d", workBoard[ row ][ col ] );
        }
        cout << "\n";
    }
    cout << "\n";
}

int validMove( int row, int column, int workBoard[8][8] ){ // to see wheather that step is vailded
   //this test stops as soon as it becomes false 
    return ( row >= 0 && row <= 7 && column >= 0 && column <= 7 && workBoard[ row ][ column ] == 0 );
}

int main()
{ 
    int board[ 8 ][ 8 ];
    int access[ 8 ][ 8 ] = { 2, 3, 4, 4, 4, 4, 3, 2, 
                            3, 4, 6, 6, 6, 6, 4, 3,
					        4, 6, 8, 8, 8, 8, 6, 4,
                            4, 6, 8, 8, 8, 8, 6, 4,
                            4, 6, 8, 8, 8, 8, 6, 4,
                            4, 6, 8, 8, 8, 8, 6, 4,
                            3, 4, 6, 6, 6, 6, 4, 3,
                            2, 3, 4, 4, 4, 4, 3, 2 }; //initialise the accessibility

    int horizontal[ 8 ] = { 2, 1, -1, -2, -2, -1, 1, 2 }; //declare every kinda movement
    int vertical[ 8 ] = { -1, -2, -2, -1, 1, 2, 2, 1 }; //declare every kinda movement
    
    srand( time(0) );
    
    clearBoard( board );   // initialize array board 
    int currentRow = rand() % 8; // now row
    int currentColumn = rand() % 8; // now column

    int moveNumber = 1;
    board[ currentRow ][ currentColumn ] = moveNumber;// the first pos

    while (1){ 
        int minAccess = 9; // impossible access number 
        int accessNumber = minAccess;
        int minRow, minColumn; // row with minimum access number

        for (int movetype = 0; movetype <= 7; movetype++ ){ //test all the type of path
            int testRow = currentRow + vertical[ movetype ]; // test step : row
            int testColumn = currentColumn + horizontal[ movetype ]; // test step : column

            if ( validMove( testRow, testColumn, board ) ){ // if that pos is vailed

                if ( access[ testRow ][ testColumn ] < accessNumber ){ 
                    accessNumber = access[ testRow ][ testColumn ];
                    minRow = testRow; 
                    minColumn = testColumn; 
                }

                access[ testRow ][ testColumn ]--; 
                /* this is the key point. 
                every time we test a path, it means there's another space 
                that would have one accessibility which is due to the now space.
                thus, when we are going to left the now space, whether or not we choose that path,
                we should still minus 1 acess form it.
                */
            }
        }

        if ( accessNumber == minAccess ){ // this means there's nowhere to go
            break;
        }    
        else{ 
            currentRow = minRow; // update the pos
            currentColumn = minColumn; // update the pos
            moveNumber++; // movenumber plus one
            board[ currentRow ][ currentColumn ] = moveNumber; //record the number and make that space marked
        }
    }

    printf( "The tour ended with %d moves.\n", moveNumber ); 

    if ( moveNumber == 64 ){ // we go through whole the board
        cout << "This was a full tour!\n\n";
    }
    else{ // we didn't go through whole the board
        cout << "This was not a full tour.\n\n";
    }

    cout << "The board for this test is:\n\n";

    printBoard(board); //print the board

    return 0;
}
