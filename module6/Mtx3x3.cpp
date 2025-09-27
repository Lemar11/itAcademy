#include <iostream>






int main()
{
	int (*m3)[3] = new int[3][3];
	
	for(int i{}; i < 3; ++i)
	{
		for(int j{}; j < 3; ++j)
		{	
			m3[i][j] = i * j;
			std::cout << m3[i][j] << " ";
		}
		std::cout << '\n';
	}
	
	delete[] m3;

	return 0;
}
