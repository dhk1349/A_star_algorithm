#pragma once
#include "libraries.h"

class block {
public:
	//void Set_addr(); this shouldn't be in the public 
	void Set_len_so_far();
	void Cal_h_len();
	vector<int> Get_addr();
	block* Get_prev_block();
	bool operator>(const block& post_block); //compares moved length so far
	bool operator<(const block& post_block);
	bool operator==(const block& post_block);
private:
	vector<int> addr; //block's  address in 2D vector
	block* prev; //block object right before this block
	double H_length; //straight length to destination. H stands for heuristic
	double length_so_far; //moved length from starting point which has to be minimal
};

class block_controller {
public:
	void run();
	void scan_map(); //finds starting point and ending point
	void closed_to_open();
	void open_to_closed();
	void trace_back();//After reaching destination, trace back to starting point to find out route.
	//need to care about obstacles
	//
private:
	vector<vector<char>> map;
	vector<vector<int>> Beg_End_location; //stores starting location and ending location
	vector<block> block_container;
	priority_queue <block> Open_block;
	priority_queue <block> Closed_block; //initial Closed_block should have starting point.
};