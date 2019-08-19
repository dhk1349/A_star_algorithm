#include "libraries.h"
#include "block_class.h"
#include "functions.h"

int main()
{
	vector<vector<char>> map;
	map=deconde_map("map.txt");

	print2DV(map);

	block_controller My_controller(map);

	return 1;
}



