#pragma once
#include <iostream>
#include <vector>

void Finding_inverse_by_modulo_Info() { // Not info actual yet
	std::cout << "----- Operating Principle -----\nFirstly, find gcd(number,modulo) using common Euclidean Algorithm\n";
	std::cout << "----- Euclidean Algorithm -----\n";
	std::cout << "Input: /forall a,b > 0\nOutput: gcd(a, b)\nInitial values:\nr_0 = a, r_1 = b\n";
	std::cout << "r_0 = r_1 * q_1 + r_2\nr_1 = r_2 * q_2 + r_3\n...\nr_{i-1} = r_i * q_i + r_{i+1}\n";
	std::cout << "...\nr_{n-2} = r_{n-1} * q_{n-1} + r_n\nr_{n-1} = r_n * q_n\ngcd(a, b) = r_n\n\n";
	std::cout << "Calculating a^{-1}, using q_{i} with minus, except q_{1}:\n";
	std::cout << "  |   | -q_{1} | -q_{2} | ... | -q_{i-1} | -q_i | -q_{i+1} | ... | -q_n\n";
	std::cout << "0 | 1 |  t_{1} |  t_{2} | ... | t_{i-1} | t_i | t_{i+1} | ... | a^{-1} | modulo\n";
	std::cout << "Where:\nt_{i+1} = -q_{i} * t_i + t_{i-1},	t_{i-1} = t_i,	t_i = t_{i+1}\n"; 
	// not sure with indexes, see example better 
	std::cout << "Example: t_1 = -q_{1} * 1 + 0, t_2 = -q_{2} * t_1 + 1, etc.\n\n";
}

long long int Finding_inverse_by_modulo(long long int& number_to_inverse, long long int& modulo_number) {
	if (number_to_inverse == 0 || modulo_number == 0)// gcd(0, 0) = 0, gcd (0, n) = n, gcd (n, 0) = n
		return 0; // In this cases inverse don't exist
	if (number_to_inverse > modulo_number)
		number_to_inverse = number_to_inverse % modulo_number;
	long long int r_i_minus_one = number_to_inverse, r_i = modulo_number, q(0), r_i_plus_one(1);
	std::vector<long long int> r_i_minus_one_vector, r_i_vector, q_vector, minus_q_vector, r_i_plus_one_vector;
	while (r_i_plus_one != 0) { // common Euclidean Algorithm
		q = r_i_minus_one / r_i;
		r_i_plus_one = r_i_minus_one % r_i;
		q_vector.push_back(q), minus_q_vector.push_back(-q), r_i_plus_one_vector.push_back(r_i_plus_one);
		r_i_minus_one_vector.push_back(r_i_minus_one), r_i_vector.push_back(r_i);
		r_i_minus_one = r_i;
		r_i = r_i_plus_one;
	}
	for (long long int i = 0; i < q_vector.size(); i++)
		std::cout << r_i_minus_one_vector[i] << " = " << r_i_vector[i] << " * " << q_vector[i] << " + " << r_i_plus_one_vector[i] << '\n';
	if (r_i_vector.back() != 1) { // gcd(a, b) != 1, a^{-1} don't exist
		std::cout << "Doesn't exict a^{-1} mod b\n" << number_to_inverse << "^{-1} mod " << modulo_number << '\n';
		return 0; // error code
	}
	else {
		std::cout << "Exict a^{-1} mod b\n" << number_to_inverse << "^{-1} mod " << modulo_number << '\n';
		minus_q_vector.erase(minus_q_vector.begin()); // first element in vector always 0, so we delete it
		long long int temp_i_minus_one = 0, temp_i = 1, temp_i_plus_one;
		std::vector<long long int> temp_vector;
		temp_vector.push_back(0), temp_vector.push_back(1);
		for (long long int i = 0; i < minus_q_vector.size(); i++) {
			temp_i_plus_one = minus_q_vector[i] * temp_i + temp_i_minus_one;
			temp_i_minus_one = temp_i;
			temp_i = temp_i_plus_one;
			temp_vector.push_back(temp_i_plus_one);
		}
		for (long long int i = 0; i < minus_q_vector.size(); i++) {
			if (i == 0)
				std::cout << " |  |";
			std::cout << minus_q_vector[i] << ((i != minus_q_vector.size() - 1) ? '|' : '\n');
		}
		for (long long int i = 0; i < temp_vector.size(); i++)
			std::cout << temp_vector[i] << ((i != temp_vector.size() - 1) ? '|' : '\n');
		return temp_vector[(temp_vector.size()-2)]; // need penultimate element, because last element is modulo
	}
}