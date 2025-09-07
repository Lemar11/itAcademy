#include <iostream>
#include <cstdlib>
#include <ctime>

#include "players.h"



int main()
{
	std::srand(std::time(nullptr));
	int count1{};
	int count2{};
 	int i {1};
	while(count1 < 50 && count2 < 50 && i < 100)
	{
		count1 += player1();
		count2 += player2();
		++i;
	}

	if(count1 > 50)
		std::cout << "WINNER!!! " << "player_01: " << count1 << '\n';
	else if(count2 > 50)
		std::cout << "WINNER!!! " << "player_02: " << count2 << '\n';
	else
		std::cout << "DRAW" << '\n';
}
