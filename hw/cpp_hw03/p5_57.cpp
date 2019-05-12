#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

void CAI();//declare

int main(){//main func
    ofstream fcout;
    fcout.open( "CAI.txt", ios::trunc);//if the file is exist, we make it empty
    fcout.close();//close the file
    CAI();//call the CAI func

    return 0;
}

void CAI(){//the func to make the question 
    srand(time(0));
    int a = 1 + rand()%9;//randomly form num one
    int b = 1 + rand()%9;//randomly form num two
    while (1){//repeatly run
        ofstream fcout;
        fcout.open( "CAI.txt", ios::out | ios::app);

        if ( !fcout ){ // overloaded ! operator{
            cerr << "fcout could not be opened" << endl;
            exit( 1 );
        } // end if
        
        srand(time(0));
        printf("How much is %d times %d?\n",a,b);
        fcout << "How much is " << a << " times " << b << "?\n";

        int c;
        cout << "Plz input your answer (or input -1 to leave):";
        cin >> c;
        if (c == -1){//if you wanna leave input -1
            cout << "You've left the program. The question hasn't been answered!\n";
            fcout << "You've left the program. The question hasn't been answered!";//output to the end of the file
            fcout.close();//close the file
            exit(1);
        }

        fcout << "Your answer is " << c << "\n";//output to the end of the file
        if (c == a*b){//if the answer is right
            int choice = 1 + rand()%4;//randomly output
            switch (choice){//we have four kinda output of the right answer
                case 1:{
                    cout << "Very good!\n\n";
                    fcout << "Very good!\n\n";//output to the end of the file
                    break;
                }
                case 2:{
                    cout << "Excellent!\n\n";
                    fcout << "Excellent!\n\n";//output to the end of the file
                    break;
                }
                case 3:{
                    cout << "Nice work!\n\n";
                    fcout << "Nice work!\n\n";//output to the end of the file
                    break;
                }
                case 4:{
                    cout << "Keep up the good work!\n\n";
                    fcout << "Keep up the good work!\n\n";//output to the end of the file
                    break;
                }
                default:{
                    break;
                }
            }
            fcout.close();
            CAI();//call the func if you answer right
        }
        else{//if the answer is wrong
            int choice = 1 + rand()%4;//randomly output
            switch (choice){//we have four kinda output of the wrong answer
                case 1:{
                    cout << "No, Please try again.\n\n";
                    fcout << "No, Please try again.\n\n";//output to the end of the file
                    break;
                }
                case 2:{
                    cout << "Wrong, Try once more.\n\n";
                    fcout << "Wrong, Try once more.\n\n";//output to the end of the file
                    break;
                }
                case 3:{
                    cout << "Don't give up!\n\n";
                    fcout << "Don't give up!\n\n";//output to the end of the file
                    break;
                }
                case 4:{
                    cout << "NO. Keep trying.\n\n";
                    fcout << "NO. Keep trying.\n\n";//output to the end of the file
                    break;
                }
                default:{
                    break;
                }
            }
            fcout.close();//close the file
        }
        
    }
}
