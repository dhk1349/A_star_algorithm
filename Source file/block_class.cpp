#include "block_class.h"
/////////////////////////////////////Block class implemetation/////////////////////////////////////
block::block() {
	addr.push_back(-1);
	addr.push_back(-1);
	H_length = -1;
	length_so_far = -1;
	prev = nullptr;
}

block::block(vector<vector<int>>input) {//block's location and destination location
	addr.push_back(input[0][0]);
	addr.push_back(input[0][1]);
	H_length = sqrt(pow(input[0][0]-input[1][0],2) + pow(input[0][1] - input[1][1], 2));
	length_so_far = -1;
	prev = nullptr;
}

void block::Set_len_so_far(double input) {
	if(length_so_far>input) //if newly added path's LSF is shorter, change existing value to new value.
		length_so_far = input;
}

void block::Set_prev_block(block* prev_block) {
	prev=prev_block;
}

vector<int> block::Get_addr()const {
	return addr;
}

block* block::Get_prev_block()const {
	return prev;
}

double block::Get_H_len()const {
	return H_length;
}

bool block::operator>(const block& post_block) { 
	if(this->Get_H_len() > post_block.Get_H_len())
		return true; 
	return false;
} 
bool block::operator<(const block& post_block) {
	if (this->Get_H_len() < post_block.Get_H_len())
		return true;
	return false; 
}
bool block::operator==(const block& post_block) {
	if (this->Get_H_len() == post_block.Get_H_len())
		return true;
	return false;
}


/////////////////////////////////Block Controller class implemetation/////////////////////////////////
block_controller::block_controller(vector<vector<char>>inputmap) {
	map = inputmap;
	scan_map(); //beg_end_location initialized
	initialize_block_map();
}

void block_controller::scan_map() {//finds starting point and ending point
	vector<int> beg;
	vector<int> end;
	for (int i = 0;i<map.size();i++) {
		for (int j = 0;j<map[i].size();j++) {
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
	cout << beg[0] << ", " << beg[1] << endl;
	cout << "Destination Address\n";
	cout << end[0] << ", " << end[1] << endl;
} 
void block_controller::initialize_block_map() {
	vector<block> row;
	vector<vector<int>> temp;
	vector<int>temp2;
	vector<int> dest;
	dest.push_back(Beg_End_location[1][0]);
	dest.push_back(Beg_End_location[1][1]);
	for (int i = 0;i<map.size();i++) {
		for (int j = 0;j<map[i].size();j++) {
			temp2.push_back(i);
			temp2.push_back(j);
			temp.push_back(temp2);
			temp.push_back(dest);
			block element(temp);
			row.push_back(element); //이 부분이 제대 될 지 잘 모르겠음
	//		cout << "creating block element for ("<< i<<", "<<j<<")"<<endl;
		}
		block_container.push_back(row);
		row.clear();
		temp.clear();
		temp2.clear();
	}
	cout << map.size() << ", " << map[0].size()<<endl;
	//49,70 맞아??4869 ->50 71
	cout << block_container.size() << ", " << block_container[0].size() << endl;

	cout << "Finished initializeing block_map from map\n";
}

void block_controller::run() {

}

void block_controller::closed_to_open() {

}

void block_controller::open_to_closed() {

}

void block_controller::trace_back() {}//After reaching destination, trace back to starting point to find out route.