#include<iostream>


int main() {
 std::cout << "Enter the first year: ";
 int firstyr{ 0 };
 std::cin >> firstyr;  

 std::cout << "Enter the number of patients we saw that year: ";
 int patient1yr{ 0 };
 std::cin >> patient1yr;

 std::cout << "Enter the second year: ";
 int secondyr{ 0 };
 std::cin >> secondyr;
 
 

 std::cout << "Enter the number of patients we saw that year: ";
 int patient2yr{ 0 };
 std::cin >> patient2yr;


 double charity_ratio{ 1071.87 };

 double charity_1yr = charity_ratio * patient1yr;
 double charity_2yr = charity_ratio * patient2yr;

 std::cout << "In year " << firstyr << "," << " our hospital issued " << charity_1yr << " dollars of charity charges." "\n";
 std::cout << "In year " << secondyr << "," << " our hospital issued " << charity_2yr << " dollars of charity charges." "\n";

 double patient_inc_dec = ((static_cast<double>(patient2yr) - static_cast<double>(patient1yr)) / static_cast<double> (patient1yr));
 double percentage_patient = patient_inc_dec * 100;

 std::cout << "Between " << firstyr << " and " << secondyr << ", there was a " << percentage_patient << "% increase in patients seen at our hospital." << "\n";



 return 0;
}
