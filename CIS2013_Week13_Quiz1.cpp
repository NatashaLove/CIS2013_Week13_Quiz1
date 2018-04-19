#include <iostream>
#include <cstring>

using namespace std;
// the class will remember all data changes in the main
class BankAccount {
		//private:
		//int wheels;
		
		private:
		
		string name;
		int acct_number=0;
		string phone;
				
		public:
		
		int balance =0;
		int rate;
		int withd=0;
		
		BankAccount () {
			setName ();
			setPhone (); // construct - returns the function after creating an object
			getAcct_number ();
						
		}

		
		void setName () {
			cout << "What's the name of the account? "<< endl;
			cin >> name;
		}
		
		
		void setPhone ()		{
			cout << "What is the phone number of " << name << " ? "<< endl;
			cin >> phone;
		}
		
				
		void getAcct_number ()		{
			
			acct_number+=1;
			cout << "Your account number is " << acct_number <<  endl;
			
		}
		
		int getBalance () {
			return balance; 
		}
		
		int deposit () {
			int depos;
			cout << "How much money do you want to deposit? " << endl;
			cin >> depos;
			cout << endl;
			balance+=depos;
			cout << "Balance on your account is " << balance << endl;
		}
		int withdraw () {
			
			cout <<"How much money do you want to withdraw? " << endl;
			cin >> withd;
			cout << endl;
			balance-=withd;
			cout << "Balance on your account is " << balance << endl;
		}
		void print () {
			cout << "The total balance of your account is " << getBalance () << endl;
		}
};

class Saving : public BankAccount {
	public:
	
	int min_balance=99;
	int wth_lmt = 100;
	
	// void warning () {
		// if (balance < min_balance) {
			// cout << "Warning!!! Your balance is below minimum! " << endl;
		// }
	// }
	// void stop_wthdr () {
		// if (withd > wth_lmt) {
			
		// }
	// }
	
};

class Checking : public BankAccount {
	public:
	
	int overdraft_fee=10;
	
	
};

int main () {
	
	char d, w, p, E; 
	char choice;
	int ans;
	
	cout << endl;
	cout << "			  *************************************************" << endl;
	cout << endl;
	cout << "					Welcome to our Bank! " << endl;
	cout << endl;
	cout << " " << endl;
	cout << "You can open a new bank account.  "<< endl;
	cout << "Let's open Saving account first :" <<endl;
	
	Saving new_s;
	
	do {
	cout << " " << endl;
	cout << "Select an action with your Saving account: " << endl;
	cout << " " << endl;
	cout << "Make a deposit (d) "<< endl;
	cout << "Withdraw money (w) " << endl;
	cout << "Print total balance (p) " << endl;
	cout << "Log out of the account (E) " << endl;
	
	cout << " " << endl;
	cout << "Your choice is : ";
	cin >> choice;
		switch (choice)
		{
		case 'd' :
		new_s.deposit ();
		break;
		case 'w' :
		new_s.withdraw ();
		break;
		case 'p' :
		new_s.print ();
		break;
		case 'E' :
		exit (1);
		break;
				
		default : 
		cout << "Illegal value.";
		}
	if (new_s.balance < new_s.min_balance) {
			cout << "Warning!!! Your balance is below minimum! " << endl;
		}
	if (new_s.withd > new_s.wth_lmt) {
		new_s.balance+=new_s.withd;
		new_s.withd = 0;
		cout << "Warning!!! You can't withdraw more than " << new_s.min_balance << " ! " << endl;
	}	
	
	cout << "		*****		" << endl; 
	cout << "Continue with this account? (y=1/n=0) " << endl;
	cin >> ans;
	if (ans!=1)
		break;
	}
	while (ans=1);
	
	cout << "Let's open Checking account now :" <<endl;
	
	Checking new_c;
	
	do {
		cout << " " << endl;
		cout << "Select an action with your Checking account: " << endl;
		cout << " " << endl;
		cout << "Make a deposit (d) "<< endl;
		cout << "Withdraw money (w) " << endl;
		cout << "Print total balance (p) " << endl;
		cout << "Log out of the account (E) " << endl;
		
		cout << " " << endl;
		cout << "Your choice is : ";
		cin >> choice;
		
		switch (choice)
		{
			case 'd' :
			new_c.deposit ();
			break;
			case 'w' :
			new_c.withdraw ();
			break;
			case 'p' :
			new_c.print ();
			break;
			case 'E' :
			exit (1);
			break;
					
			default : 
			cout << "Illegal value.";
		}
		
		if (new_c.balance < 0) {
			cout << "Warning!!! Your balance is below 0! " << endl;
			cout << " Your fee is " << new_c.overdraft_fee << endl;
			cout << " Your balance now is "<< new_c.balance << endl;
		}
	
		cout << "		*****		" << endl; 
		cout << "Continue with this account? (y=1/n=0) " << endl;
		cin >> ans;
		if (ans==0)
			break;
	}
	while (ans=1);
	
		
	return 0;
}