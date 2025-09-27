#include <iostream>
#include <memory>


void printarr(const int* arr, size_t N)
{
	std::cout << "printing array: " << '\n';
	std::cout << '\t';
	for(size_t i{}; i < N; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void printarr(int* start,int* end)
{
	std::cout << "printing array: " << '\n';
	std::cout << '\t';
	for(size_t i{}; start != end; ++start)
		std::cout << *start << " ";
	std::cout << std::endl;
}

int getMax(const int* arr, size_t N)
{
	int max {arr[0]};
	for(size_t i {1}; i < N; ++i)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

int getMin(const int* arr, size_t N)
{
	int min {arr[0]};
	for(size_t i{1}; i < N; ++i)
	{
		if(arr[i] < min)
			min = arr[i];
	}
	return min;
}
int main()
{
	const size_t size = 10;
	std::unique_ptr<int[]> ptr {new int[size]};
	size_t count{};
	while(std::cin >> ptr[count++] && count < 10){} 

	printarr(ptr.get(), size); // maybe this is dangerous I'm not sure :) any way we can take as an argument std::unique_ptr<int>& by reference
	//printarr(ptr.get(),ptr.get()+size);
	std::cout << "max: " << getMax(ptr.get(), size) << std::endl;
	std::cout << "min: " << getMin(ptr.get(), size) << std::endl;
	return 0;
}
