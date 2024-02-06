#include <iostream>

const double OUTOFPOCKETCAP{ 75.0 };

/*
 * cap_outofpocket takes two parameters (whose types are both
 * double) and returns a double. It calculates the capped out-
 * of-pocket fee for an office visit with a bill valued at _bill_
 * and an insurance cap of _max_.
 */
double cap_outofpocket(double bill, double max) {
	if (bill >= max) {
		// If the _bill_ costs more than the _max_ amount
		// that the customer can pay, simply "return" that
		// maximum amount. 
		return max;

		// The first return statement encountered ends the function's
		// execution.
	}

	// If we get here, we know that _bill_ was < _max_. No need for an
	// else: if _bill_ was >= _max_ then we would have entered the if
	// above and the execution of the function would have terminated 
	// at the return statement!
	return bill;
}

/*
 * This program will calculate (and cap) the cost the patient
 * pays to the doctor for their current visit.
 */
int main() {
	double office_fee{ 25.0 };
	double total_fee{ office_fee };
	double medicine_fee{ 0.0 };
	double test_fee{ 0.0 };

	std::cout << "Enter patient's medicine fee: ";
	std::cin >> medicine_fee;

	std::cout << "Enter patient's test fee: ";
	std::cin >> test_fee;

	total_fee += medicine_fee + test_fee;

	total_fee = cap_outofpocket(total_fee, OUTOFPOCKETCAP);

	std::cout << "Total Bill: $" << total_fee << ".\n";

	return 0;
}
