#include <iostream>
#include <iomanip>




int main()
{
	for(int i = 1, k = 1; ; ++i)
	{
		if(i > 10)
		{
			k++;
			i = 1; 
		}
		if(k > 9)
			break;
		char shift = ((k - 1)%2)*10;
		std::cout << std::setw(shift) << k << " * " << i  << " = " << i * k << std::endl;
	}
}
