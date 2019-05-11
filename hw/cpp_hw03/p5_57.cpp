#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void CAI();

int main(){
    ofstream fcout;
    fcout.open( "CAI.txt", ios::trunc);
    fcout.close();
    CAI();

    return 0;
}

void CAI(){

    srand(time(0));
    int a = 1 + rand()%9;
    int b = 1 + rand()%9;
    while (1){
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
        if (c == -1){
            cout << "You've left the program. The question hasn't been answered!\n";
            fcout << "You've left the program. The question hasn't been answered!";
            fcout.close();
            exit(1);
        }

        fcout << "Your answer is " << c << "\n";
        if (c == a*b){
            int choice = 1 + rand()%4;
            switch (choice){
                case 1:{
                    cout << "Very good!\n\n";
                    fcout << "Very good!\n\n";
                    break;
                }
                case 2:{
                    cout << "Excellent!\n\n";
                    fcout << "Excellent!\n\n";
                    break;
                }
                case 3:{
                    cout << "Nice work!\n\n";
                    fcout << "Nice work!\n\n";
                    break;
                }
                case 4:{
                    cout << "Keep up the good work!\n\n";
                    fcout << "Keep up the good work!\n\n";
                    break;
                }
                default:
                    break;
            }
            fcout.close();
            CAI();
        }
        else
        {
            int choice = 1 + rand()%4;
            switch (choice){
                case 1:{
                    cout << "No, Please try again.\n\n";
                    fcout << "No, Please try again.\n\n";
                    break;
                }
                case 2:{
                    cout << "Wrong, Try once more.\n\n";
                    fcout << "Wrong, Try once more.\n\n";
                    break;
                }
                case 3:{
                    cout << "Don't give up!\n\n";
                    fcout << "Don't give up!\n\n";
                    break;
                }
                case 4:{
                    cout << "NO. Keep trying.\n\n";
                    fcout << "NO. Keep trying.\n\n";
                    break;
                }
                default:
                    break;
            }
            fcout.close();
        }
        
    }
}