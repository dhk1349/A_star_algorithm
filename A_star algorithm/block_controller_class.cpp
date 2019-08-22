
#include "block_controller_class.h"


/////////////////////////////////Block Controller class implemetation/////////////////////////////////
block_controller::block_controller(vector<vector<char>>inputmap) {
	map = inputmap;
	scan_map(); //beg_end_location initialized
	initialize_block_map();
}

void block_controller::scan_map() {//finds starting point and ending point
	vector<int> beg;
	vector<int> end;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 'S') {
				beg.push_back(i);
				beg.push_back(j);
			}
			else if (map[i][j] == 'F') {
				end.push_back(i);
				end.push_back(j);
			}
		}
		if (end.size() == 2)
			break;
	}
	Beg_End_location.push_back(beg);
	Beg_End_location.push_back(end);
	cout << "Starting Address\n";
	cout << Beg_End_location[0][0] << ", " << Beg_End_location[0][1] << endl;
	cout << "Destination Address\n";
	cout << Beg_End_location[1][0] << ", " << Beg_End_location[1][1] << endl;
}
void block_controller::initialize_block_map() {
	vector<block*> row;
	vector<vector<int>> temp;
	vector<int>temp2;
	vector<int> dest;
	dest.push_back(Beg_End_location[1][0]);
	dest.push_back(Beg_End_location[1][1]);
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			temp2.push_back(i);
			temp2.push_back(j);
			temp.push_back(temp2);
			temp.push_back(dest);
			block* element = new block(temp);
			row.push_back(element);
			temp.clear();
			temp2.clear();
		}
		block_container.push_back(row);
		row.clear();

	}
	cout << map.size() << ", " << map[0].size() << endl;

	cout << block_container.size() << ", " << block_container[0].size() << endl;

	cout << "Finished initializeing block_map from map\n";
}

void block_controller::run() {
	cout << "adding " << Beg_End_location[0][0] << ", " << Beg_End_location[0][1] << endl;
	block_container[Beg_End_location[0][0]][Beg_End_location[0][1]]->Set_len_so_far(0);
	Closed_block.push(block_container[Beg_End_location[0][0]][Beg_End_location[0][1]]);//adding starting point block to closed block
	int test;
	int cnt = 0;
	bool exit = false;
	while (!exit) {
		closed_to_open();
		test = cnt % 9;
		exit = open_to_closed(test);
		cnt++;
	}
	iterative_trace_back(Open_block.top());
}

void block_controller::closed_to_open() {
	block* temp = Closed_block.top(); 
	vector<vector<int>> temp2 = get_movable_space(temp);
	int length_revision;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (temp2[i][j] == 1) {//최단거리 갱신되면 이전 주소가 수정되도록 코그 수정
				length_revision = block_container[temp->Get_addr()[0] + i - 1][temp->Get_addr()[1] + j - 1]->Set_len_so_far(temp->Get_len_so_far() + sqrt(pow(temp->Get_addr()[0] - (temp->Get_addr()[0] + i - 1), 2) + pow(temp->Get_addr()[1] - (temp->Get_addr()[1] + j - 1), 2))); //set LSF based on prev block
				if (length_revision == 1)block_container[temp->Get_addr()[0] + i - 1][temp->Get_addr()[1] + j - 1]->Set_prev_block(temp); //set prev block
				if (map[temp->Get_addr()[0] + i - 1][temp->Get_addr()[1] + j - 1] == '.' || map[temp->Get_addr()[0] + i - 1][temp->Get_addr()[1] + j - 1] == 'F') {
					Open_block.push(block_container[temp->Get_addr()[0] + i - 1][temp->Get_addr()[1] + j - 1]);
					map[temp->Get_addr()[0] + i - 1][temp->Get_addr()[1] + j - 1] = 'X';  //mark for open block
				}
			}
		}
	}
}

bool block_controller::open_to_closed(int i) {
	block* temp = Open_block.top(); //pick
	map[temp->Get_addr()[0]][temp->Get_addr()[1]] = 'C';
	Closed_block.push(Open_block.top());
	if (Open_block.top()->Get_H_len() == 0) {
		return true;
	}

	else {
		Open_block.pop();
	}
	return false;
}

block* block_controller::trace_back(block* input) {//After reaching destination, trace back to starting point to find out route.

	return input->Get_prev_block();
}

void block_controller::iterative_trace_back(block* input) {
	block* temp = input;
	map[temp->Get_addr()[0]][temp->Get_addr()[1]] = 'F';
	while (temp->Get_prev_block() != nullptr) {
		temp = trace_back(temp);
		map[temp->Get_addr()[0]][temp->Get_addr()[1]] = 'F';
	}
}

void block_controller::get_h_info(int a, int b) {
	cout << block_container[a][b]->Get_H_len() << endl;
}


vector<vector<int>> block_controller::get_movable_space(block* input) {//x, y is current location
	int index[3] = { -1,0,1, };
	vector<int> addr = input->Get_addr();
	vector<vector<int>> movable_space(3, vector<int>(3, 1)); //initialize 3X3vector filled with 0.
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (map[addr[0] + index[i]][addr[1] + index[j]] == 'o') {
				movable_space[i][j] = 0;//if block is empty, save 1 to vector space
			}
		}
	}
	movable_space[1][1] = 0;
	//considering walls
	if (movable_space[0][1] == 0 && movable_space[1][0] == 0) {
		movable_space[0][0] = 0;
	}
	if (movable_space[2][1] == 0 && movable_space[1][0] == 0) {
		movable_space[2][0] = 0;
	}
	if (movable_space[2][1] == 0 && movable_space[1][2] == 0) {
		movable_space[2][2] = 0;
	}
	if (movable_space[0][1] == 0 && movable_space[1][2] == 0) {
		movable_space[0][2] = 0;
	}
	return movable_space;
}

void block_controller::print_map() {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

vector<vector<block*>> block_controller::get_block_container() const {
	return block_container;
}