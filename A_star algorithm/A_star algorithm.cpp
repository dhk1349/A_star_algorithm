
/**
*	@mainpage
*	@date	2019/08/21
*	@author	 한동훈
*/

#include "libraries.h"
#include "block_class.h"
#include "block_controller_class.h"
#include "functions.h"

/**
*  main function for data structures course.
*/
int main(int argc, char ** argv)
{
	vector<vector<char>> map;
	map=deconde_map("map.txt");

	print2DV(map);

	block_controller My_controller(map);
	My_controller.run();

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
