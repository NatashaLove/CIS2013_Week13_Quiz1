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
		}
		int withdraw () {
			int withd;
			cout <<"How much money do you want to withdraw? " << endl;
			cin >> withd;
			cout << endl;
			balance-=withd;
		}
};

class Saving : public BankAccount {
	public:
	
	int min_balance=99;
	int wth_lmt = 100;
	
};

class Checking : public BankAccount {
	public:
	
	int overdraft_fee=10;
	
	
};

int main () {
	
	cout << endl;
	cout << "			  *************************************************" << endl;
	cout << endl;
	cout << "					Welcome to our Bank! " << endl;
	cout << endl;
	cout << " " << endl;
	cout << "You can open a new bank account.  "<< endl;
	cout << "Let's open Saving account first :" <<endl;
	
	Saving new_s;
	
	cout << " " << endl;
	cout << "Select an action with your Saving account: " << endl;
	cout << " " << endl;
	cout << "Make a deposit (d) "<< endl;
	cout << "Withdraw money (w) " << endl;
	cout << "Print total balance (p) " << endl;
	
	cout << "		*****		" << endl; 
	
		
	return 0;
}