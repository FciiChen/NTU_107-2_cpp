#include <iostream>
#include <fstream>
using namespace std;


void Towers(int disk, char src, char dest, char aux){//the fun of hanoi: disk is number of disks to be moved, src is where the disk from, aux is the holding area, dest is the destination
    ofstream fcout;
    fcout.open("Hanoi_Tower.txt", ios::out | ios::app);//clean the file

    if( disk == 1){//if there one disk remained
        cout << "Move No." <<  disk <<  " from peg " << src << " to peg " <<  dest << endl;
        fcout << "Move No." <<  disk <<  " from peg " << src << " to peg " <<  dest << endl;//output to the file
    }
    else{//if there are more than one disk
        Towers( disk - 1, src, aux, dest);//Move the smaller one to the aux peg first

        cout << "Move No." << disk << " from peg " << src << " to peg " << dest << endl;//Move the biggest one to the destiantion
        fcout << "Move No." << disk << " from peg " << src << " to peg " << dest << endl;//output to the file

        Towers(  disk - 1, aux, dest, src);//Move the smaller one to the destination
    }
}

int main(){//the main func
    ofstream fcout;
    fcout.open("Hanoi_Tower.txt", ios::trunc);//clean the file if exist
    fcout.close();//close the file

    fcout.open("Hanoi_Tower.txt", ios::out | ios::app);//write the data to the end of the file
    int n;//the num of the disk
    cout << "How many disk(The num must be >= 1): ";
    cin >> n;
    if (n == 1){//for the output determination
        fcout << "There is " << n << " disk\n";
    }
    else{
        fcout << "There are " << n << " disks\n";
    }
    fcout.close();//close the file

    Towers(n, '1', '3', '2');//call the func
    
    return 0;
}