#include <iostream>
#include <string>

using namespace std;

void check_string(string *command, int *step){ // seperate the 5,x to be command : 5 and x steps if the command is 5,x
    string command_to_process = *command; // to make sure command would not be change, we declare a variable to recod it
    int length = sizeof(command_to_process) / sizeof( command_to_process[0] ); // to record the length of command
    int comma_pos = -1; // the position of the comma is -1 by default
    for (int i=0 ; i < length ; i++){ // to find the pos of comma if there's one
        if( command_to_process[i] == ','){
            comma_pos = i;
        }
    }

    if (comma_pos == -1){ // if there aren;t any comma, do nothing
        ;
    }
    else{ // if there is a comma
        string step_command; // the command of "5"
        for (int i=0 ; i<comma_pos ; i++){
            step_command += command_to_process[i];
        }
        *command = step_command; // make *command change to be "5"

        string step_str; // the remaining number after the comma is the step 
        for (int i = comma_pos+1 ; i<length ; i++){
            step_str += command_to_process[i];
        }
        int step_num = stoi(step_str); // change it into int data-type
        *step = step_num; // make *step change to be step_num
    }
    
}

void command_set(string command, bool *pen, int *turn, bool a[20][20], int step, int *x_pos, int *y_pos){ // a func to process the command
    if (command == "1"){ // to make the pen up, i.e. don't draw
        *pen = false;
    }
    else if(command == "2"){ // to make the pen down, i.e. draw
        *pen = true;
    }

    else if(command == "3"){ // to set the status of turn (direction) : turn right
        *turn + 1 > 3 ? *turn = *turn % 4 : *turn += 1; 
    }
    else if(command == "4"){ // to set the status of turn (direction) : turn left
        *turn - 1 < 0 ? *turn = *turn -1 + 4 : *turn -= 1;
    }
    else if(command == "5"){ // to move
        int turn_status = *turn; // the status of turn (direction)
        if (turn_status == 0){ // direction : rightward
            if (*x_pos + step > 19){ // avoid user going out of range of the map
                cout << "this command is invailed because you'll be out of the range of the map\n";
            }
            else{ // if in the map
                if (*pen){ // if pen is down
                    for (int i=0 ; i<= step; i++){ // to mark the trace
                        a[*y_pos][*x_pos+i] = true; //mark the trace which is left by going right
                    }
                
                }
                *x_pos += step; //go right "step" step
            }
        }
        else if (turn_status == 1){ // direction : downtward
            if (*y_pos + step > 19){ // avoid user going out of range of the map
                cout << "this command is invailed because you'll be out of the range of the map\n";
            }
            else{ // if in the map
                if (*pen){ // if pen is down
                    for (int i=0 ; i<= step; i++){ // to mark the trace
                        a[*y_pos+i][*x_pos] = true; //mark the trace which is left by going down
                    }
                }
                *y_pos += step; //go down "step" step
            }
        }
        else if (turn_status == 2){ // direction : lefttward
            if (*x_pos - step < 0){ // avoid user going out of range of the map
                cout << "this command is invailed because you'll be out of the range of the map\n";
            }
            else{ // if in the map
                if (*pen){ // if pen is down
                    for (int i=0 ; i<= step; i++){ // to mark the trace
                        a[*y_pos][*x_pos-i] = true; //mark the trace which is left by going left
                    }
                }
                *x_pos -= step; //go left "step" step
            }
        }
        else if (turn_status == 3){ // direction : upward
            if (*y_pos - step < 0){ // avoid user going out of range of the map
                cout << "this command is invailed because you'll be out of the range of the map\n";
            }
            else{ // if in the map
                if (*pen){ // if pen is down
                    for (int i=0 ; i<= step; i++){ // to mark the trace
                        a[*y_pos-i][*x_pos] = true; //mark the trace which is left by going up
                    }
                }
                *y_pos -= step; //go up "step" step
            }
        }
    }

    else if(command == "6"){ // print the map
        for (int i=0 ; i<20 ; i++){
            for (int j=0 ; j<20 ; j++){
                a[i][j] == false ? cout << " " : cout << "*"; // if true print "*", else print space
            }
            cout << "\n";
        }
    }

    else{ // other command will be rejected
        cout << "invailed input. Plz reinput!\n";
    }

    
}

int main(){
    bool a[20][20] = {false}; // the map
    bool pen = false; // the status of pen
    int turn = 0; // the status of turn. 0 is rightward, 1 is downward, 2 is leftward, 3 is upward 
    int step; // the num of step
    int x_pos = 0, y_pos = 0; // now position
    string command; // command input

    while(cin >> command){
        if (command == "9"){ // if command == 9, end the program
            break;
        }
        check_string(&command, &step); // to check whether the command is 5,x and x is the num of step.
        command_set(command, &pen, &turn, a, step, &x_pos, &y_pos); 
    }
}