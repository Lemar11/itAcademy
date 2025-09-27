#include <iostream>
#include <vector>
#include <random>


void merge_sort(std::vector<int>& array, int start, int end)
{

	if(start >= end)
		return;
	int mid = ((end - start) / 2) + start;

	merge_sort(array, start, mid);
	merge_sort(array, mid + 1 , end);

//I know that there is standart std::sort :)
///////////////////// MERGE //////////////// this is not the optimized implementation of merge in terms of additional memory space // but for our purpouses it's enough :)
	std::vector<int> tmp;

	tmp.reserve(end - start + 1);

	for(int i = start; i <= end; ++i)
	{
		tmp.push_back(array[i]);
	}

	int k = start;

	//tmp indexes
	int si = 0;
	int ei = mid - start;
	int sj = ei + 1;
	int ej = end - start;

	while(si <= ei && sj <= ej)
	{
		if(tmp[si] > tmp[sj])
		{
			array[k] = tmp[sj];	
			++sj;
		}
		else if(tmp[si] < tmp[sj])
		{
			array[k] = tmp[si];
			++si;
		}
		else
		{
			array[k] = tmp[si];
			array[k+1] = tmp[sj];
			++si;
			++k;
			++sj;
		}
		++k;
	}

	while(si <= ei)
	{
		array[k] = tmp[si];
		++k;
		++si;
	}
	
	while(sj <= ej)
	{
		array[k] = tmp[sj];
		++k;
		++sj;
	}
}




int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dist(0,100);
	
	const uint32_t vsize = 10;
	std::vector<int> array;
	array.reserve(vsize);
	

	for(int i{}; i < vsize - 1; ++i)
	{
		array.push_back(dist(gen));
		std::cout << array[i] << std::endl;
	}

	std::cout << ">>>>>>>> SORTED >>>>>>>>>" << std::endl;
	merge_sort(array, 0, array.size()-1);
	for(auto elem : array)
	{
		std::cout << elem << std::endl;
	}
	return 0;

}
