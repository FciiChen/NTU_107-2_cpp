#include <iostream>

using namespace std;

void insertion_sort(int a[], int n){
    for(int i = 1; i <= n; i++){

        int j = i-1, now_sort = a[i];//now_sort for the num sorted now, j is the last index 
        
        while(j >= 0 && a[j] > now_sort){
            a[j+1] = a[j];
            j -= 1;
        }
        a[++j] = now_sort; 
    }
}

int main(){
    int num;
    cin >> num;
    int a[num];
    for(int i = 0 ; i < num ; i++){
        cin >> a[i];
    }

    insertion_sort(a,num);
    for(int i = 0 ; i < num ; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}