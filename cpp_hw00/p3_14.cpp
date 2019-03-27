#include <iostream>
using namespace std;

int main(){
	while(1){
		int account; 
		cout << "Enter account number (or -1 to quit): ";
		cin >> account;
		if (account == -1){
			break;
		}
		double beginning_num, total_charge, total_credit;
		double limit;
		
		cout << "Enter beginning balance: ";
		cin >> beginning_num;
		cout << "Enter total charges: ";
		cin >> total_charge;
		cout << "Enter toal credits: ";
		cin >> total_credit;
		cout << "Enter credit limit: ";
		cin >> limit;
		
		beginning_num += total_charge;
		beginning_num -= total_credit;
		float final_balance = beginning_num;

		if (final_balance > limit){
			printf ("New balance is %.2f\n", final_balance);
			printf ("Account:\t%d\n", account);
			printf ("Credit limit:\t%.2f\n", limit);
			printf ("Balance:\t%.2f\n", final_balance);
			
			cout << "Credit Limit Exceeded." << "\n\n";
		}
		else {
			printf ("New balance is %.2f\n\n", final_balance);
		}
	}
}