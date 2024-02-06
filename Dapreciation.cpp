#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
  int model_year{0};
  std::cout << "What is the model year of the car? ";
  std::cin >> model_year;
  return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
  int accidents{0};
  std::cout << "How many accidents has the car been in? ";
  std::cin >> accidents;
  return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
  double msrp{0.0};
  std::cout << "How much did you pay for the car? ";
  std::cin >> msrp;
  return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 *
 * returns: whether the car has premium option as entered by the user (`bool`).
 */
bool car_has_premium_options() {
  std::string has_options_string{""};
  std::cout << "Does your car have premium options (yes/no)? ";
  std::cin >> has_options_string;
  if (has_options_string == "yes") {
    return true;
  } else {
    return false;
  }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
  std::cout << std::fixed << std::setprecision(2)
            << "dappreciation will list your car for $" << resale_price
            << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
  std::cout << "Unfortunately your car is ineligible for the dappreciation "
               "platform.\n";
}



/* This program will ask for inputs from the user
(model year of the car, number of car accidents,
* if the car has premium options, 
* and the Manufacturer's suggested retail price or what they paid for the car. 
* After getting the input from the user, it will use that information to choose
* from different values depending if a condition is met.
* [Example] if the car age is greater than 0 years and less or equal to 4 
* the new value of the MSRP will be 85% of it's original value.
* after selecting which conditions are met, the program will calculate the final resale percentage
* and finally the final resale value multiplying that percentage by the original price the user paid for the car.
*/
int main() {
    int car_year = car_model_year();

    int num_of_accidents = car_accidents();

    bool Premium_options = car_has_premium_options();

    double MSRP1 = car_msrp();

    int car_age = (2023 - car_year);

    double baseline_resale_numberpercentage{0.0};

    double wreck_penalty_number{0.0};


    //Age of vehicle price reduction
    const double between_0_and_4yrs{ 0.85 };
    const double between_5_and_8yrs{ 0.63 };
    const double between_9_and_10{ 0.45 };

    // Wreck penalty accidents 
    const double no_accidents{ 0.0 };
    const double one_accident{ 0.02 };
    const double two_accidents{ 0.10 };
    const double three_accidents{ 0.20 };

 



 

    if (car_age >= 0 && car_age <= 4) {
        baseline_resale_numberpercentage = between_0_and_4yrs;
    }
        else if (car_age > 4 && car_age <= 8) {

            baseline_resale_numberpercentage = between_5_and_8yrs;

        }
        else if (car_age > 8  && car_age <= 10) {

            baseline_resale_numberpercentage = between_9_and_10;
        }
        else {
            print_ineligible_message();

            return 0;


        }


    if (num_of_accidents == 0) {

        wreck_penalty_number = no_accidents;

    } else if (num_of_accidents == 1) {

        wreck_penalty_number = one_accident;

    } else if (num_of_accidents == 2) {

        wreck_penalty_number = two_accidents;

    } else if (num_of_accidents == 3) {

        wreck_penalty_number = three_accidents;

    }

     double  final_resale_percentage = (baseline_resale_numberpercentage) - (wreck_penalty_number);


    if (Premium_options) {
        final_resale_percentage += 0.05;
    }

     double Final_resale_value = final_resale_percentage * MSRP1;

     print_eligible_message(Final_resale_value);

  
      return 0;
 }
