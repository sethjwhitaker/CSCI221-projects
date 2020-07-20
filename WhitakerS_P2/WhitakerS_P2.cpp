/*
 * Author: Seth Whitaker
 * Version: 02/12/20
 */

#include <iostream>
using namespace std;

// Account Class
class CDAccount {
public:
	CDAccount();															// Default constructor
	CDAccount(double new_balance, double new_interest_rate, int new_term);	// Specific constructor
	double get_initial_balance() const;										// Get initial balance
	double get_balance_at_maturity() const;									// Get balance at maturity
	double get_interest_rate() const;										// Get interest rate
	int get_term() const;													// Get term length
	void input(istream& in);												// Input new values for balance, interest rate, and term length
	void output(ostream& out);												// Output balance, interest rate, and term length

private:
	// Balance
	int dollar;				// Dollar component of balance
	int cent;				// Cent component of balance

	double interest_rate;	// Interest rate stored as a fraction
	int term;				// Term length in months

	// Takes a double value balance, sparates it, and assigns it to dollars and cents
	void set_balance(double balance);

};

void menu1();						// Test Menu 1

void menu2(CDAccount account);		// Test Menu 2

void inputPrompt();					// Input Prompt for testing input method of CDAccount



int main() {

	menu1();	// Open the first test menu

	return 0;

}

// This is a function that outputs a menu to the user
// and the user inputs their choice.
// This menu tests the default and specific constructors of the CDAccount class.
// After constructing the account object, it then opens the second menu, where you can test 
// each method of the object individually.
void menu1() {

	// Loop in case user wants to test another constructor
	char repeat = 'y';										
	while (repeat == 'y' || repeat == 'Y') {

		// Output menu
		cout << "\n--------------------------------------";
		cout << "\n\t\tMENU";
		cout << "\n--------------------------------------";
		cout << "\n  1. Test Default Constructor";
		cout << "\n  2. Test Specific Constructor";
		cout << "\n  0. Quit";
		cout << "\n--------------------------------------";
		cout << endl;

		int choice;									// Get user's choice
		cin >> choice;

		switch (choice) {							


		// Test Default Constructor
		case 1: {

			CDAccount testAccount = CDAccount();	// Create test account

			menu2(testAccount);						// Open up the second menu

		}
			break;

		// Test Specific Constructor
		case 2: {

			inputPrompt();							// Prompt user for input

			double balance, interest;				// Variables for user input
			int term;

			cin >> balance >> interest >> term;		// Get user input

			
			CDAccount testAccount = CDAccount(balance, interest, term); // Create test account with data from user

			menu2(testAccount);						// Open up the second menu

		}
			break;

		default:
			break;

		}

		// Ask user if they want to repeat the function
		cout << "\nWould you like to create another account object? (Y/N): ";
		cin >> repeat;

	}


}

// This is a function that outputs a menu to the user
// and the user inputs their choice.
// This menu tests the methods of the account instance created in the first menu.
void menu2(CDAccount account) {

	// Loop in case user wants to test another method
	char repeat = 'y';
	while (repeat == 'y' || repeat == 'Y') {

		// Output menu
		cout << "\n--------------------------------------";
		cout << "\n\t\tMENU";
		cout << "\n--------------------------------------";
		cout << "\n  1. Get Initial Balance";
		cout << "\n  2. Get Balance at Maturity";
		cout << "\n  3. Get Interest Rate";
		cout << "\n  4. Get Term Length";
		cout << "\n  5. Test Input Function";
		cout << "\n  6. Test Output Function";
		cout << "\n  0. Quit";
		cout << "\n--------------------------------------";
		cout << endl;

		// Get user's choice
		int choice;									
		cin >> choice;

		switch (choice) {

		// Test get_initial_balance()
		case 1:
			cout << "\nInitial Balance: $" << account.get_initial_balance();
			break;

		// Test get_balance_at_maturity()
		case 2:
			cout << "\nBalance at Maturity: $" << account.get_balance_at_maturity();
			break;

		// Test get_interest_rate()
		case 3:
			cout << "Interest Rate: " << account.get_interest_rate() << "%";
			break;

		// Test get_term()
		case 4: 
			cout << "Term Length: " << account.get_term() << " months";
			break;

		// Test input()
		case 5:
			inputPrompt();			// Prompt user to input data
			account.input(cin);
			break;

		// Test output()
		case 6:
			account.output(cout);
			break;

		default:
			break;

		}

		// Ask user if they want to repeat the function
		cout << "\nWould you like to test another method of this account object? (Y/N): ";
		cin >> repeat;

	}

}


// This is an input prompt made specifically for testing the input method of CDAccount.
// The input method has a very specific input format, and since it does not accept an
// output stream argument, so this function informs the user of the input format.
void inputPrompt() {

	cout << "\nEnter initial balance, interest rate, and term length in this order:";
	cout << "\n1. Balance";
	cout << "\n2. Interest Rate (percentage)";
	cout << "\n3. Term Length (months)";
	cout << "\n";

}

// Default constructor sets everything to 0
CDAccount::CDAccount() {

	dollar = 0;
	cent = 0;
	interest_rate = 0;
	term = 0;

}

// Specific constructor takes data from the user, converts it to the proper format,
// and assigns it to each of the member variables
CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term) {

	set_balance(new_balance);					// Convert double to dollars and cents
	interest_rate = new_interest_rate / 100.00;	// Convert percent to fraction
	term = new_term;

}

// Returns the initial balance in double format.
double CDAccount::get_initial_balance() const {

	return dollar + cent / 100.00; // convert dollars and cents to double

}

// Returns the balance after the loan matures
double CDAccount::get_balance_at_maturity() const {

	double balance = dollar + cent / 100.00;			// Convert dollars and cents to double

	balance += balance * interest_rate * term / 12.00;	// Add the interest multiplied by the term length

	return balance;

}

// Returns the interest rate as a percentage
double CDAccount::get_interest_rate() const {

	return interest_rate * 100.00;

}

// Returns the term length
int CDAccount::get_term() const {

	return term;

}

// Accepts new values for the balance, interest rate, and term length from user
void CDAccount::input(istream& in) {

	double new_balance, new_interest_rate;				// Varaibles for storing user input
	int new_term;

	in >> new_balance >> new_interest_rate >> new_term;	// Get user input

														// Assign input to member variables
	set_balance(new_balance);							// Convert double to dollars and cents
	interest_rate = new_interest_rate / 100.00;			// Convert percent to fraction
	term = new_term;

}

// Outputs initial balance, balance at maturity, interest rate, and term length
// to the output stream given
void CDAccount::output(ostream& out) {

	// Output data
	out << "\nYour initial balance is: $" << get_initial_balance();
	out << "\nYour balance at maturity is: $" << get_balance_at_maturity();
	out << "\nYour interest rate is: " << get_interest_rate() << "%";
	out << "\nYour term length is: " << get_term() << " months";

}

// Converts double to dollars and cents, and assigns result to member variables
void CDAccount::set_balance(double balance) {

	dollar = static_cast<int>(balance);				// Casting as an int truncates the decimal values
	cent = static_cast<int>(balance * 100) % 100;	// Multiplying by 100 before casting preserves 2 decimal values

}

/***OUTPUT***

--------------------------------------
				MENU
--------------------------------------
  1. Test Default Constructor
  2. Test Specific Constructor
  0. Quit
--------------------------------------
1

--------------------------------------
				MENU
--------------------------------------
  1. Get Initial Balance
  2. Get Balance at Maturity
  3. Get Interest Rate
  4. Get Term Length
  5. Test Input Function
  6. Test Output Function
  0. Quit
--------------------------------------
6

Your initial balance is: $0
Your balance at maturity is: $0
Your interest rate is: 0%
Your term length is: 0 months
Would you like to test another method of this account object? (Y/N): n

Would you like to create another account object? (Y/N): y

--------------------------------------
				MENU
--------------------------------------
  1. Test Default Constructor
  2. Test Specific Constructor
  0. Quit
--------------------------------------
2

Enter initial balance, interest rate, and term length in this order:
1. Balance
2. Interest Rate (percentage)
3. Term Length (months)
9999.00
8.7
36

--------------------------------------
				MENU
--------------------------------------
  1. Get Initial Balance
  2. Get Balance at Maturity
  3. Get Interest Rate
  4. Get Term Length
  5. Test Input Function
  6. Test Output Function
  0. Quit
--------------------------------------
6

Your initial balance is: $9999
Your balance at maturity is: $12608.7
Your interest rate is: 8.7%
Your term length is: 36 months
Would you like to test another method of this account object? (Y/N): y

--------------------------------------
				MENU
--------------------------------------
  1. Get Initial Balance
  2. Get Balance at Maturity
  3. Get Interest Rate
  4. Get Term Length
  5. Test Input Function
  6. Test Output Function
  0. Quit
--------------------------------------
3
Interest Rate: 8.7%
Would you like to test another method of this account object? (Y/N): y

--------------------------------------
				MENU
--------------------------------------
  1. Get Initial Balance
  2. Get Balance at Maturity
  3. Get Interest Rate
  4. Get Term Length
  5. Test Input Function
  6. Test Output Function
  0. Quit
--------------------------------------
1

Initial Balance: $9999
Would you like to test another method of this account object? (Y/N): y

--------------------------------------
				MENU
--------------------------------------
  1. Get Initial Balance
  2. Get Balance at Maturity
  3. Get Interest Rate
  4. Get Term Length
  5. Test Input Function
  6. Test Output Function
  0. Quit
--------------------------------------
2

Balance at Maturity: $12608.7
Would you like to test another method of this account object? (Y/N): y

--------------------------------------
				MENU
--------------------------------------
  1. Get Initial Balance
  2. Get Balance at Maturity
  3. Get Interest Rate
  4. Get Term Length
  5. Test Input Function
  6. Test Output Function
  0. Quit
--------------------------------------
4
Term Length: 36 months
Would you like to test another method of this account object? (Y/N): y

--------------------------------------
				MENU
--------------------------------------
  1. Get Initial Balance
  2. Get Balance at Maturity
  3. Get Interest Rate
  4. Get Term Length
  5. Test Input Function
  6. Test Output Function
  0. Quit
--------------------------------------
5

Enter initial balance, interest rate, and term length in this order:
1. Balance
2. Interest Rate (percentage)
3. Term Length (months)
1
99.99
100

Would you like to test another method of this account object? (Y/N): y

--------------------------------------
				MENU
--------------------------------------
  1. Get Initial Balance
  2. Get Balance at Maturity
  3. Get Interest Rate
  4. Get Term Length
  5. Test Input Function
  6. Test Output Function
  0. Quit
--------------------------------------
6

Your initial balance is: $1
Your balance at maturity is: $9.3325
Your interest rate is: 99.99%
Your term length is: 100 months
Would you like to test another method of this account object? (Y/N): y

--------------------------------------
				MENU
--------------------------------------
  1. Get Initial Balance
  2. Get Balance at Maturity
  3. Get Interest Rate
  4. Get Term Length
  5. Test Input Function
  6. Test Output Function
  0. Quit
--------------------------------------
0

Would you like to test another method of this account object? (Y/N): n

Would you like to create another account object? (Y/N): n

******\WhitakerS_P2.exe (process 16248) exited with code 0.
*/