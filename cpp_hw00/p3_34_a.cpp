#include <iostream>
using namespace std;

int main(){
    int factorial; //the factorial you wnat
    cin >> factorial; 
    long long int ans = 1; // the first term is 1, which is also 1/0!
    
    while(factorial > 0){
        ans *= factorial;
        factorial -= 1;
    }

    cout << ans << "\n";

    return 0;
}