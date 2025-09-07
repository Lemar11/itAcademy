#include <iostream>
#include <cstdint>
#include <bitset>







int main()
{
	uint32_t input {};

	std::cin >> input;
	
	std::cout << "input number: " << std::right << std::bitset<32>(input) << std::endl;

	if(input % 2 == 0)
		input <<= 2;
	else
		input >>= 2;

	std::cout << "output number: "<< std::right << std::bitset<32>(input) << std::endl;



}
