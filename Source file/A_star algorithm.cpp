#include "libraries.h"
#include "block_class.h"
#include "functions.h"

int main()
{
	vector<vector<char>> map;
	map=deconde_map("map.txt");

	print2DV(map);

	block_controller My_controller(map);
	My_controller.run();
	/*
	int input1=0;
	int input2 = 0;
	while (input1 != -1) {
		cout << "Type location: ";
		cin >> input1;
		cin >> input2;
		My_controller.get_h_info(input1, input2);
	}
	*/
	My_controller.print_map();
	int input1 = 0;
	int input2 = 0;
	while (input1 != -1) {
		cout << "Block to print: ";
		cin >> input1;
		cin >> input2;
		My_controller.get_block_container()[input1][input2]->print_block();
	}
	return 1;
}



