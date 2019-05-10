#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int CAI(){

    srand(time(0));
    int a = 1 + rand()%9;
    int b = 1 + rand()%9;
    while (1){
        srand(time(0));
        printf("How much is %d times %d?\n",a,b);
        int c;
        cin >> c;
        if (c == a*b){
            int choice = 1 + rand()%4;
            switch (choice){
                case 1:{
                    cout << "Very good!\n\n";
                    break;
                }
                case 2:{
                    cout << "Excellent!\n\n";
                    break;
                }
                case 3:{
                    cout << "Nice work!\n\n";
                    break;
                }
                case 4:{
                    cout << "Keep up the good work!\n\n";
                    break;
                }
                default:
                    break;
            }
            CAI();
        }
        else
        {
            int choice = 1 + rand()%4;
            switch (choice){
                case 1:{
                    cout << "No, Please try again.\n\n";
                    break;
                }
                case 2:{
                    cout << "Wrong, Try once more.\n\n";
                    break;
                }
                case 3:{
                    cout << "Don't give up!\n\n";
                    break;
                }
                case 4:{
                    cout << "NO. Keep trying.\n\n";
                    break;
                }
                default:
                    break;
            }
        }
        
    }
}

int main(){
    CAI();


    return 0;
}
