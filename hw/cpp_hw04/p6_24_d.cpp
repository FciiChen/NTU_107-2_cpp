#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

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
    int board[ 8 ][ 8 ] = {0};
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
    

    cout << "\nPlz input (1) the Row and (2) the column you wanna start at (both between 0 ~ 7): ";
    int currentRow, currentColumn; // now row and column
    cin >> currentRow >> currentColumn;

    int moveNumber = 1;
    board[ currentRow ][ currentColumn ] = moveNumber;// the first pos

    while (1){ 
        int minAccess = 9; // impossible access number 
        int accessNumber = minAccess;
        int minRow, minColumn; // row with minimum access number
        int best_nextnext_access = 9;

        for (int movetype = 0; movetype <= 7; movetype++ ){ //test all the type of path
            int testRow = currentRow + vertical[ movetype ]; // test step : row
            int testColumn = currentColumn + horizontal[ movetype ]; // test step : column

            if ( validMove( testRow, testColumn, board ) ){ // if that pos is vailed

                int temp = board[ testRow ][ testColumn ]; 
                board[ testRow ][ testColumn ] = -1; 
                /* we assume that the now pos is ocuppied 
                so that when we want to see the next next step
                we won't count the now-testing pos
                at the same time we record it and resume it at the end of for
                */

                if ( access[ testRow ][ testColumn ] < accessNumber ){ //if the access is smaller
                    accessNumber = access[ testRow ][ testColumn ];
                    minRow = testRow; 
                    minColumn = testColumn;
                    for (int movetype_nextnext = 0; movetype_nextnext <= 7; movetype_nextnext++ ){ //test all the type of path
                        int testRow_nextnext = testRow + vertical[ movetype_nextnext ]; // test next next step : row
                        int testColumn_nextnext = testColumn + horizontal[ movetype_nextnext ]; // test next next step : column
                        
                        if ( validMove( testRow_nextnext, testColumn_nextnext, board ) ){ // if that pos is vailed

                            if ( access[ testRow_nextnext ][ testColumn_nextnext ] < best_nextnext_access ){  // if the next next step's access is smaller
                                best_nextnext_access = access[ testRow_nextnext ][ testColumn_nextnext ];  // record it to wait for the compare from other equal-accessed pathes
                            }
                        }
                    }

                }
                else if  ( access[ testRow ][ testColumn ] == accessNumber ){  // if the access is the ssame
                    for (int movetype_nextnext = 0; movetype_nextnext <= 7; movetype_nextnext++ ){ //test all the type of path
                        int testRow_nextnext = testRow + vertical[ movetype_nextnext ]; // test next next step : row
                        int testColumn_nextnext = testColumn + horizontal[ movetype_nextnext ]; // test next next step : column
                        
                        if ( validMove( testRow_nextnext, testColumn_nextnext, board ) ){ // if that pos is vailed

                            if ( access[ testRow_nextnext ][ testColumn_nextnext ] < best_nextnext_access ){  //to see wether it's smaller than the best next_next_access
                                best_nextnext_access = access[ testRow_nextnext ][ testColumn_nextnext ];  //record the best_nextnext_access
                                minRow = testRow; 
                                minColumn = testColumn;
                            }
                        }
                    }
                }

                board[ testRow ][ testColumn ] = temp;  // resume the board
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
