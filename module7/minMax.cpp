#include <iostream>
#include <memory>

int arrSum(std::weak_ptr<int> ptr, size_t size)
{
	auto shrd_ptr = ptr.lock(); //strong count++
	if(!shrd_ptr || size == 0)
		std::runtime_error ("unavailable object or size is zero");

	int* rawP = shrd_ptr.get();
	int sum{};
	for(int i{}; i < size; ++i)
	{
		sum += rawP[i];
	}
	return sum;
}


std::pair<int, int> GetminMax(std::weak_ptr<int> ptr, size_t size)  // weak count++
{
	auto shrd_ptr = ptr.lock(); //strong count++
	if(!shrd_ptr || size == 0)
		std::runtime_error ("unavailable object or size is zero");

	int* rawP = shrd_ptr.get(); // getting the raw pointer because shared is not providing [] operator pre c++20
	int min = rawP[0];
	int max = min;
	for(int i{1}; i < size; ++i)
	{	
		if(rawP[i] < min)
			min = rawP[i];
		if(rawP[i] > max)
			max = rawP[i];
	}

	return std::pair<int,int>{min,max}; // weakcount-- : strongcount--
}



int main()
{
	size_t N {8};
	std::shared_ptr<int> s_ptr {new int[N], std::default_delete<int[]>()}; // shared is not implemented for arrays that is why we are transfering custom deleter object (before c++20
	
	size_t count{};
	while(std::cin >> s_ptr.get()[count++] && count < N) {}    // filling an array


	std::weak_ptr<int> w_ptr = s_ptr; // here the strong count is still one - w_ptr is just looking to that object (not owning)
	std::pair<int, int> minmax;
	if(w_ptr.lock()) // I think this additional checking is not nesessary // if there is not empty - shared_ptr has an bool() operator overloaded it can be used in if statements 
	{
		std::cout << "Sum of array elements: " << arrSum(w_ptr, N) << std::endl;
		minmax = GetminMax(w_ptr, N); // weak counter is 2 inside 
		std::cout << "min: " << minmax.first << std::endl;
		std::cout << "max: " << minmax.second << std::endl;
	}	
	//strong counter 1 : weak counter 1
	return 0;
}
