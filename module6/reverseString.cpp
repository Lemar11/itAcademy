#include <iostream>





const char* reverseString(char* str)
{
	int size{};
	while(str[size] != '\0') //know about strlen() but for educational purpouses I am always implementing small functions 
		++size;
	if(size == 0)
	{
		std::cout << "empty input" << std::endl;
		return "\0";
	}
	--size;

	for(int i = 0; i <= size/2; ++i)
	{
		char tmp = str[i];
		str[i] = str[size - i];
		str[size - i] = tmp;

	}
	return str;
}

int main()
{
	char name[]  = "";
	
	std::cout << reverseString(name);

}
