#include <iostream>
#include <string>
#include <vector>
#include <memory>

template<typename T>
std::string typeName()
{
	return typeid(T).name();
}


void print(int value)
{
	std::cout << "Type: " << typeName<int>() << " >>>> ";
	std::cout << "Value: " << value << std::endl;
}

void print(double value)
{
	std::cout << "Type: " << typeName<double>() << " >>>> ";
	std::cout << "Value: " << value << std::endl;
}

void print(std::string value)
{
	std::cout << "Type: " << typeName<std::string>() << " >>>> ";
	std::cout << "Value: " << value << std::endl;
}

void print(const char* value)
{
	std::cout << "Type: " << typeName<const char*>() << " >>>> ";
	std::cout << "Value: " << value << std::endl;
}

void print(int* value, size_t size) // (int (&value)[N]) with template N will be deduced at compile time if array is static
{
	if(!value || size == 0)
		return;
	std::cout << "Type: " << typeName<int*>() << " >>>> ";
	std::cout << "Value: ";
	for(int i{}; i < size; ++i)
		std::cout << value[i] << " ";
	std::cout << std::endl;
}

void print(std::vector<int> value) 
{
	if(value.size() == 0)
		return;
	std::cout << "Type: " << typeName<std::vector<int>>() << " >>>> ";
	std::cout << "Value: ";
	for(int i{}; i < value.size(); ++i)
		std::cout << value[i] << " ";
	std::cout << std::endl;
}

void print(std::shared_ptr<int> ptr) 
{
	if(!ptr)
		return;
	std::cout << "Type: " << typeName<std::shared_ptr<int>>() << " >>>> ";
	std::cout << "Value: " << *ptr << std::endl;
}

void print(std::unique_ptr<double>& uptr) 
{
	if(!uptr)
		return;
	std::cout << "Type: " << typeName<std::unique_ptr<double>>() << " >>>> ";
	std::cout << "Value: " << *uptr << std::endl;
}

int main()
{
	int x;
	double y;
	std::string name {"Levon"};
	const char* str = "Mart";
	int arr[5] {1,2,3,4,5};
	std::vector<int> v{6,7,8,9,10,11};
	auto sptr = std::make_shared<int>(11);
	auto uptr = std::make_unique<double>(11.1);
	print(x);
	print(y);
	print(name);
	print(str);
	print(arr, 5);
	print(v);
	print(sptr);
	print(uptr);


	return 0;
}

