#include <iostream>
using namespace std;

int main(){

    for(int i = 1 ; i <= 5  ; i ++){ //漸增的有五行
        
        for (int j = 1 ; j <= 5-i ; j ++){
            cout << " ";
        }
        for (int j = 1 ; j <= 1 + 2*(i-1) ; j ++){
            cout << "*";
        }
        cout << "\n";
    }

    for(int i = 1 ; i <= 4  ; i ++){ //漸減的有四行
        
        for (int j = 1 ; j <= i ; j ++){
            cout << " ";
        }
        for (int j = 1 ; j <= 7 - 2*(i-1) ; j ++){
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}