
#include <iostream>
#include <cstring>
using namespace std;
int number = 100;

class BankAccount {
	public:
		void deposit(int x){
			balance += x;
		}
		void withdraw(int y){
			balance -= y;
		}
		BankAccount(){
			string nm = "Anonymous";
			string ph = "555-555-5555";
			BankAccount(nm,ph);
		}
		BankAccount(string n, string p){
			rate = 5.0;
			name = n;
			phone = p;
			acct_numb = number++;
			balance = 0;
		}
		void print(){
			cout << "Account: " << acct_numb << endl;
			cout << "User: " << name << endl;
			cout << "Phone: " << phone << endl;
			cout << "Balance: " << balance << endl;
			cout << "Rate: " << rate << endl;
		}
	private:
		string name;
		string acct_numb;
		string phone;
		int balance;
		float rate;
};

class Savings: public BankAccount {
	public:
		Savings():BankAccount(){
			minimum_balance = 100;
			withdraw_limit = 100;
		}
		Savings(string n, string p):BankAccount(n,p){
			minimum_balance = 100;
			withdraw_limit = 100;
		}
		void withdraw(int y){
			if(y < withdraw_limit){
				// balance -= y;
				if(balance <minimum_balance){
					cout << "Warning: You are below your minimum balance." << endl;
				}
			} else {
				cout << "You are only allowed to withdraw " << withdraw_limit <<
					" from this account. Transaction terminated." << endl;
			}
		}
		
	private:
		int minimum_balance;
		int withdraw_limit;
};

class Checking: public BankAccount {
	public:
		Checking():BankAccount(){
			overdraft_fee = 25;
		}
	private:
		int overdraft_fee;
};

int main(){
	// Now create menus...
	// string name, phone
	// Ask for name and ask for phone;
	// Create checking account type
	string phone = "405-555-5656";
	Savings chk_acct("Bob", phone);
	Savings chk_acct2;
	
	chk_acct.print();
	chk_acct2.print();
	// Print balance
	// cout << "Your balance is " << chk_acct.balance << endl;
	// withdraws
	// chk_account.withdraw(200);
	return 0;
}