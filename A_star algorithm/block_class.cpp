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

int block::Set_len_so_far(double input) {
	if (length_so_far == -1) {
		length_so_far = input;
		return 1;
	}
	else {
		if (length_so_far > input) {//if newly added path's LSF is shorter, change existing value to new value.
			length_so_far = input;
			return 1;
		}
	}
	return 0;
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

double block::Get_len_so_far() const{
	return length_so_far;
}

double block::Get_TTL() const {
	return length_so_far + H_length;
}
/*
bool block::operator>(const block& post_block) {
	if (this->Get_H_len() + this->Get_len_so_far() > post_block.Get_H_len() + post_block.Get_len_so_far())
		return true;
	return false;
}
bool block::operator<(const block& post_block) {
	if (this->Get_H_len() + this->Get_len_so_far() < post_block.Get_H_len() + post_block.Get_len_so_far())
		return true;
	return false; 
}
bool block::operator==(const block& post_block) {
	if (this->Get_H_len() + this->Get_len_so_far() == post_block.Get_H_len() + post_block.Get_len_so_far())
		return true;
	return false;
}
*/
void block::print_block() {
	cout <<"Address: "<< addr[0] << ", " << addr[1] << endl;
	cout <<"Heuristic length: "<< H_length << endl;
	cout << "Length so far: " << length_so_far << endl;
	cout << "Total length: " << H_length + length_so_far << endl << endl;
}
