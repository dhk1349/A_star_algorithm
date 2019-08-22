
/**
*	@block class header
*	@date	2019/08/21
*	@author	 한동훈
*/


#pragma once
#include "libraries.h"

class block {
public:
	//////////////constructor//////////////
	/*
	* default constructor
	*/
	block();

	/*
	* constructor
	*/
	block(vector<vector<int>>input);

	/*
	* desstructor
	*/
	~block() {}
	///////////////Functions///////////////
		/**
*	@brief   현재까지의 이동거리를 설정한다. 
*	@pre	 초기의 elength_so_far은 -1로 설정되어있다.
*	@post	 기존의 length_so_far이 -1면 input으로 변경. 기존의 length_so_far보다 input 값이 작으면 변경.
*	@param  double형의 input
*	@return	값이 변경되었으면 1을, 아니면 0을 리턴
*/
	int Set_len_so_far(double input); //return 1 if value changed, return. return 0 if value has not changed.
	
		/**
*	@brief 현재 블록 이전에 있던 블록이 어디인지 포인터 형으로 가리킨다.
*	@pre	open_block으로 block이 push 되기 전까지는 nullptr을 가지리고 시작점도 nullptr을 가리킨다.
*	@post	prev_block의 위치가 포인터 형으로 저장된다.
*	@param prev_block 변수에 저장할 포인터 주소
*	@return	없음
*/
	void Set_prev_block(block* prev_block);
	
	/**
*	@brief 해당 블록의 주소를 벡터 형태로 리턴해준다. 
*	@pre	없음
*	@post	없음
*	@param 없음
*	@return	해당 블록의 주소를 1X2 벡터로 반환해준다. 
*/
	vector<int> Get_addr()const;
	
	/**
*	@brief 해당 블록 이전의 블록의 포인터 주소 정보를 제공한다. 
*	@pre	없음
*	@post	없음
*	@param 없음
*	@return	해당 블록이 있기 전에 있던 블록의 포인터 주소를 리턴한다. 
*/
	block* Get_prev_block()const;
	
	/**
*	@brief 도착지까지의 직선 거리(Heuristic length) 값을 반환한다.
*	@pre	없음
*	@post	없음
*	@param 없음
*	@return	H_len 변수를 반환한다.
*/
	double Get_H_len()const;
	
	/**
*	@brief 현재까지 움직인 거리를 반환한다.
*	@pre	없음
*	@post	없음
*	@param 없음
*	@return	현재까지 해당 블록까지 이동한 거리(len_so_far)을 리턴한다.
*/
	double Get_len_so_far()const;
	
	/**
*	@brief 현재까지 이동거리와 Heuristic length의 합 정보를 제공한다.
*	@pre	없음
*	@post	없음
*	@param 없음
*	@return	현재까지 이동거리와 heuristic length의 합을 리턴한다.
*/
	double Get_TTL() const;
	/////////Operator Overloading/////////
	//bool operator>(const block& post_block);
	//bool operator<(const block& post_block);
	//bool operator==(const block& post_block);
	
		/**
*	@brief 해당 블록에 대한 정보를 출력한다.
*	@pre	없음
*	@post	없음
*	@param 없음
*	@return	없음
*/
	void print_block();
private:
	vector<int> addr; //block's  address in 2D vector
	block* prev; //block object right before this block
	double H_length; //straight length to destination. H stands for heuristic
	double length_so_far; //moved length from starting point which has to be minimal
};

