#include <iostream>
#include <cmath>
#include <limits>
#include <cstdint>

#include "config.h"
#include "factorial.h"

myType factorial(myType val)
{
	if(val <= 1)
		return 1;

	myType prev_res = factorial(val - 1);
	return prev_res > std::numeric_limits<myType>::max() / val ? 0 : prev_res * val; //checking for overflow - we need (prev_res * n < MAX_INT
																				     //so prev_res should be less than <  MAX_INT / n(current)
}
