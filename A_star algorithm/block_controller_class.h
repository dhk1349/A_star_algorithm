
/**
*	@block controller class header
*	@date	2019/08/21
*	@author	 한동훈
*/

#pragma once
#include "block_class.h"
#include "libraries.h"

/*
 * Class for making priority queue (minimal) with block object.
 */
class MyCompare {
public:
	template<typename T>
	bool operator()(T* a, T* b) {
		return (a->Get_H_len() > b->Get_H_len());
	}
};



class block_controller {
public:
	/*
	* constructor
	*/
	block_controller() {}
	/*
	* constructor
	*/
	block_controller(vector<vector<char>>inputmap);
	/*
	* destructor
	*/
	~block_controller() {}

	/**
*	@brief map 변수를 통해서 시작점과 끝점의 위치 정보를 beg_end_location에 2X2벡터로 저장하고, 이를 화면에 출력해준다.
*	@pre	없음
*	@post	지도의 시작점과 끝점의 위치 정보가 beg_end_location 변수에 저장된다.
*	@param 없음
*	@return	없음
*/
	void scan_map(); //finds starting point and ending point

		/**
*	@brief map과 동일한 크기를 가지는 각 원소가 block object인 벡터를 만든다.
*	@pre	없음
*	@post	map과 동일한 크기의 block map이 block container 변수에 저장된다.
*	@param 없음
*	@return	없음
*/
	void initialize_block_map();

	/**
*	@brief closed_block 변수에 시작점 블록을 push하고, 도착점까지의 길찾기를 한다. 해당 오브젝트의 실행 함수.
*	@pre	없음
*	@post	시작점부터 끝점까지의 경로를 찾는다.
*	@param 없음
*	@return	없음
*/
	void run();

	/**
*	@brief closed_block의 최상위 원소를 가지고 이동 가능한 block을 open_block에 push하는 함수
*	@pre	없음
*	@post	open_block에 새롭게 이동가능한 블록이  push 된다.
*	@param 없음
*	@return	없음
*/
	void closed_to_open();

	/**
*	@brief open_block에서 H_len이 가장 작은 블록을 pop해서 closed_block에 push한다.
*	@pre	없음
*	@post	open_block에서 heuristic length가 가장 작은 값이 closed_block으로 push된다.
*	@param 없어도 상관 없지만 대략적인 이동 경로를 추적하기 위해 넣은 변수. loop의 현 횟수를 넣으면 1-9 사이 숫자로 맵에 표시된다.
*	@return	push하는 closed block element가 목적지이면 true, 아니면 false.
*/
	bool open_to_closed(int i);

	/**
*	@brief 현재 블록의 이전 위치를 반환해주는 함수
*	@pre	없음
*	@post	없음
*	@param 이전 위치를 알고 싶은 블록의 포인터 변수
*	@return	현재 블록이 거친 이전 블록의 포인터 주소를 리턴
*/
	block* trace_back(block* input);//After reaching destination, trace back to starting point to find out route.

		/**
*	@brief trace_back함수를 시작점에 도착할 때까지 실행하며 그 이동 경로를 map변수에 표시하는 함수.
*	@pre	없음
*	@post	map변수 상에서 되돌아간 경로가 F로 표기된다.
*	@param 되돌아가기를 시작하고 싶은 블록 지점
*	@return	없음
*/
	void iterative_trace_back(block* input);

	/**
*	@brief block_container 변수 정보를 제공하는 함수
*	@pre	없음
*	@post	없음
*	@param 없음
*	@return	block_container 변수 정보를 리턴한다.
*/
	vector<vector<block*>>get_block_container() const;

	/**
*	@brief 지도 상에서 (a, b) 위치에 있는 블록의 Heuristic length 정보를 제공
*	@pre	없음
*	@post	없음
*	@param H_len이 궁금한 블록의 좌표
*	@return	map에서 (a, b)에 위치한 블록의 h_len 변수를 리턴
*/
	void get_h_info(int a, int b);

	/**
*	@brief 현재 블록 위치에서 이동가능한 위치를 3X3 벡터에 저장하여 제공한다. (1, 1)이 현재 위치이며, 이동 가능한 곳은 1 불가능한 곳은 0으로 표시된다.
*	@pre	없음
*	@post	없음
*	@param 이동가능한 위치를 알고싶은 블록의 포인터 변수
*	@return	input으로 받은 블복 포인터에서 이동하능한 곳을 3X3 벡터에 저장하여 리턴
*/
	vector<vector<int>> get_movable_space(block* input);

	/**
*	@brief map 변수를 화면 상에 출력
*	@pre	없음
*	@post	없음
*	@param 없음
*	@return	없음
*/
	void print_map();

private:
	vector<vector<char>> map;
	vector<vector<int>> Beg_End_location; //stores starting location and ending location
	vector<vector<block*>> block_container;
	priority_queue <block*, vector<block*>, MyCompare> Open_block;
	stack <block*> Closed_block; //initial Closed_block should have starting point.
};


