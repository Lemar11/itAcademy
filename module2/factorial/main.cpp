#include <iostream>
#include <cstdint>

#include "config.h"
#include "factorial.h"


int main()
{
	myType input{};//defined in factorial.h 
	std::cout << "Enter number to compute factorial ------- or -------- 0 to exit" << std::endl;
	while(std::cin >> input && input != myType{})
	{
		auto result  = factorial(input);
		result == 0 ? std::cout << "overflow" << '\n': std::cout << "result: " << result << std::endl;
		std::cout << "Enter number to compute factorial ------- or ------- 0 to exit" << std::endl;
	}
	return 0;


}
