#include <iostream>
#include <iomanip>

/////////// compile time table of multiple generation ///////////

const int rows = 81;
const int cols = 3;

// wraping around struct in order to return from the function by value
struct Table {

	int data[rows][cols];

};

constexpr Table TableGen()
{	
	Table tmpTable{};
	for(int i = 0, k = 1; i < 81; ++i)
	{
			tmpTable.data[i][0] = k;
			tmpTable.data[i][1] = (i % 9) + 1;
			tmpTable.data[i][2] = k * ((i % 9) + 1);
			if((i+1) % 9 == 0)
				k += 1;
	}
	return tmpTable;
}

/// intialasing at global scope
constexpr Table MultTable = TableGen();

///print function for mul table
void PrintTable(const Table& multable)
{
	for(int i = 0; i < 81; ++i)
	{
		char shift = (i/9)*10;
		std::cout << std::setw(shift) << multable.data[i][0] << " * " << multable.data[i][1] << " = " << multable.data[i][2] << std::endl;
	}
}

int main()
{

	PrintTable(MultTable);

}
