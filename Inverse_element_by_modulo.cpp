#include "Header.h"

int main() {
	std::cout << "Hello! What you what to calculate today?\n";
	std::cout << "Enter '0', to use Euclidean Algorithm\nEnter '1', to use Extended Euclidean Algorithm\n";
	
	Finding_inverse_by_modulo_Info();
	long long int number_to_inverse(0), modulo_number(0);
	std::cout << "Enter number to inverse:\t";
	std::cin >> number_to_inverse;
	std::cout << "Enter modulo number:\t";
	std::cin >> modulo_number;
	std::cout << Finding_inverse_by_modulo(number_to_inverse, modulo_number);
	return 0;
}