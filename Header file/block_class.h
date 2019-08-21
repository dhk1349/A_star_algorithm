#pragma once
#include "libraries.h"

class block {
public:
	//////////////constructor//////////////
	block(); 
	block(vector<vector<int>>input);
	///////////////Functions///////////////
	int Set_len_so_far(double input); //return 1 if value changed, return. return 0 if value has not changed.
	void Set_prev_block(block* prev_block);
	vector<int> Get_addr()const;
	block* Get_prev_block()const;
	double Get_H_len()const;
	double Get_len_so_far()const;
	double Get_TTL() const;
	/////////Operator Overloading/////////
	bool operator>(const block& post_block);
	bool operator<(const block& post_block);
	bool operator==(const block& post_block);
	

	void print_block();
private:
	vector<int> addr; //block's  address in 2D vector
	block* prev; //block object right before this block
	double H_length; //straight length to destination. H stands for heuristic
	double length_so_far; //moved length from starting point which has to be minimal
};
//Defining compare method for mean minial priority queue
class MyCompare {
public:
	template<typename T>
	bool operator()(T* a, T* b) {
		return (a->Get_H_len() >= b->Get_H_len());
		//return (a->Get_TTL() >= b->Get_TTL());
		//return (*a) < (*b);
	}
};

class block_controller {
public:
	block_controller(vector<vector<char>>inputmap);
	void scan_map(); //finds starting point and ending point
	void initialize_block_map();
	void run();
	void closed_to_open();
	void open_to_closed(int i);
	void trace_back();//After reaching destination, trace back to starting point to find out route.
	vector<vector<block*>>get_block_container() const;
	//need to care about obstacles
	void get_h_info(int a, int b);
	vector<vector<int>> get_movable_space(block* input);
	void print_map();

private:
	vector<vector<char>> map;
	vector<vector<int>> Beg_End_location; //stores starting location and ending location
	vector<vector<block*>> block_container;
	priority_queue <block*,vector<block*>, MyCompare> Open_block;
	stack <block*> Closed_block; //initial Closed_block should have starting point.
};
