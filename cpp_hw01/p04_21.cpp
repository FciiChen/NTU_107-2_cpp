#include <iostream>

using namespace std;
int main(){
    cout << "There are four kinds of workers:\n";
    cout << "1. manager ; 2. hourly workers ; 3. commission worker ; 4.pieceworkers\n\n";
    cout << "Plz input (1 ~ 4) to calculate the salary of workers: ";

    int choice;
    cin >> choice; // the case you choose
    double to_paid; // cash to pay

    cout << "\n"; // for layout

    switch ( choice )
    {
        case 1: { // the part of manager. They have fixed weekly salary.
            cout << "This is the calculation of salary of manager.\n";
            cout << "Plz input the weekly salary he/she can receive: ";
            cin >> to_paid;
            
            cout << "the weekly salary of manager: " << to_paid << "\n\n";
            break;
        }

        case 2: { // the part of hourly workers. Their salary is counted by hours.
            cout << "This is the calculation of salary of hourly workers.\n";
            
            cout << "Plz input the hours he/she had worked: ";
            double hours;
            cin >> hours;
            
            cout << "Plz input the hourly wage: ";
            double hourly_wage;
            cin >> hourly_wage;

            to_paid = hours <= 40 ? hours * hourly_wage : 40 * hourly_wage + (hours - 40) * 1.5 * hourly_wage;
            cout << "the weekly salary of hourly worker: " << to_paid << "\n\n";
            break;
        }

        case 3: { // the part of commission worker. they have at less 250 and bonus : 0.057 * gross_weekly_sales
            cout << "This is the calculation of salary of commission workers.\n";
            cout << "Plz input the gross weekly sales: ";
            double gross_weekly_sales;
            cin >> gross_weekly_sales;

            cout << "the weekly salary of commission worker: " << 250 + 0.057 * gross_weekly_sales << "\n\n";
            break;
        }

        case 4: { // the part of pieceworkers. they salary depends on how many the sold.
            cout << "This is the calculation of salary of pieceworkers.\n";
            cout << "Plz input the amount of products he/she had produced: ";
            double amount;
            cin >> amount;
            cout << "Plz input the money earned each products he/she had produced: ";
            double money;
            cin >> money;

            cout << "the weekly salary of pieceworker: " << money * amount << "\n\n"; 
            break;
        }
    
        default: // else number break!
            cout << "Plz input a vaild number!\n";
            break;
    }

    return 0;
}