#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	double min_rate = 0, max_rate = 100; // Set Maximum and minimum rate
	double mid_rate;

	double loan_amt;
	cout << "Enter in the loan amount: ";
	cin >> loan_amt;

	double N;
	cout << "Enter in the term: ";
	cin >> N;

	double actual_payment;
	cout << "Enter in the monthly payment: ";
	cin >> actual_payment;

	while (min_rate < (max_rate - 0.0001) )
	{
		mid_rate = (min_rate + max_rate) / 2; // Divide by 2
		double J = mid_rate / 1200; // Convert to monthly decimal
		// calculate payment from interest, term and loan_amt
		double guessed_pmt = loan_amt *   (J / (1 - pow((1 + J), -N) ));
		if (guessed_pmt > actual_payment)
		{
			max_rate = mid_rate; // current rate is new maximum
		}
		else
		{
			min_rate = mid_rate; // current rate is new minimum
		}
	}
	cout <<  "\nThe Rate is " << mid_rate << "\n";
	cout << "Press any key to continue...";
	
	int clearnum = cin.rdbuf()->in_avail() + 1;
	cin.clear();
	cin.ignore(clearnum);
}