#include <iostream>
#include <memory>




int main(int Args,char** argv)
{

	size_t init_size {32};
	std::shared_ptr<int> s_ptr = {new int[32], std::default_delete<int[]>()}; // before c++20 the only way to init array with shared_ptr is this 

	
	std::cout << "Enter numbers or CTRL+D(linux) to finish" << std::endl; ///CTRL+D will set eof bit 
	size_t i{};
	int value{};
	while(std::cin >> value && i != init_size)
	{
		s_ptr.get()[i++] = value;
	}



	return 0;
}
