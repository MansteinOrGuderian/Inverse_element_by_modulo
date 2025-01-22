#include "Header.h"

int main() {
	std::cout << "Calculating a^{-1} mod b\n";
	Finding_inverse_by_modulo_Info();
	long long int number_to_inverse(0), modulo_number(0);
	std::cout << "Enter number to inverse:\t";
	std::cin >> number_to_inverse;
	std::cout << "Enter modulo number:\t";
	std::cin >> modulo_number;
	std::cout << Finding_inverse_by_modulo(number_to_inverse, modulo_number);
	return 0;
}