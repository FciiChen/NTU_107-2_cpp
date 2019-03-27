#include <iostream>
using namespace std;

int main(){
    int N = 1; //to count the loop
    printf("N\t10*N\t100*N\t1000*N\t\n\n"); //the first row

    while(N < 6){ //second to sixth row
        printf("%d\t%d\t%d\t%d\t\n", N, 10*N, 100*N, 1000*N);
        N += 1; //everytime we change the row, N+1
    }
}