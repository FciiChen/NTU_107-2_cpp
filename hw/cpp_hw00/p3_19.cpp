#include <iostream>
using namespace std;

int main(){
    int counter = 2; //we set up teo num first
    float num_1, num_2; //first two number
    cin >> num_1 >> num_2;
    if (num_1 <= num_2 ){ //if num_2 >= num_1, swap(num_1,num_2), so finally num_1 >= num_2
        int temp = num_1;
        num_1 = num_2;
        num_2 = temp;
    }

    float first = num_1; //biggest number
    float second = num_2; //second number

    while(counter < 10){ //the loop would keep run 8 times
        float new_num; //everytime we key in a new number
        cin >> new_num;
        if (new_num >= first){ //if c is the biggest, we set the first to be c, and the second to be the former first value
            second = first;
            first = new_num;
        }
        else if (first >= new_num && new_num >= second){ //if c is between first and second, we set second to be c
            second = new_num;
        } 

        counter += 1; //eveerytime we finish the loop, counter += 1
    }

    cout << "The biggest num is " << first << ", and The second one is " <<second << "\n";
}
