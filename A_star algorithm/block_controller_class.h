
/**
*	@block controller class header
*	@date	2019/08/21
*	@author	 �ѵ���
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
*	@brief map ������ ���ؼ� �������� ������ ��ġ ������ beg_end_location�� 2X2���ͷ� �����ϰ�, �̸� ȭ�鿡 ������ش�.
*	@pre	����
*	@post	������ �������� ������ ��ġ ������ beg_end_location ������ ����ȴ�.
*	@param ����
*	@return	����
*/
	void scan_map(); //finds starting point and ending point

		/**
*	@brief map�� ������ ũ�⸦ ������ �� ���Ұ� block object�� ���͸� �����.
*	@pre	����
*	@post	map�� ������ ũ���� block map�� block container ������ ����ȴ�.
*	@param ����
*	@return	����
*/
	void initialize_block_map();

	/**
*	@brief closed_block ������ ������ ����� push�ϰ�, ������������ ��ã�⸦ �Ѵ�. �ش� ������Ʈ�� ���� �Լ�.
*	@pre	����
*	@post	���������� ���������� ��θ� ã�´�.
*	@param ����
*	@return	����
*/
	void run();

	/**
*	@brief closed_block�� �ֻ��� ���Ҹ� ������ �̵� ������ block�� open_block�� push�ϴ� �Լ�
*	@pre	����
*	@post	open_block�� ���Ӱ� �̵������� �����  push �ȴ�.
*	@param ����
*	@return	����
*/
	void closed_to_open();

	/**
*	@brief open_block���� H_len�� ���� ���� ����� pop�ؼ� closed_block�� push�Ѵ�.
*	@pre	����
*	@post	open_block���� heuristic length�� ���� ���� ���� closed_block���� push�ȴ�.
*	@param ��� ��� ������ �뷫���� �̵� ��θ� �����ϱ� ���� ���� ����. loop�� �� Ƚ���� ������ 1-9 ���� ���ڷ� �ʿ� ǥ�õȴ�.
*	@return	push�ϴ� closed block element�� �������̸� true, �ƴϸ� false.
*/
	bool open_to_closed(int i);

	/**
*	@brief ���� ����� ���� ��ġ�� ��ȯ���ִ� �Լ�
*	@pre	����
*	@post	����
*	@param ���� ��ġ�� �˰� ���� ����� ������ ����
*	@return	���� ����� ��ģ ���� ����� ������ �ּҸ� ����
*/
	block* trace_back(block* input);//After reaching destination, trace back to starting point to find out route.

		/**
*	@brief trace_back�Լ��� �������� ������ ������ �����ϸ� �� �̵� ��θ� map������ ǥ���ϴ� �Լ�.
*	@pre	����
*	@post	map���� �󿡼� �ǵ��ư� ��ΰ� F�� ǥ��ȴ�.
*	@param �ǵ��ư��⸦ �����ϰ� ���� ��� ����
*	@return	����
*/
	void iterative_trace_back(block* input);

	/**
*	@brief block_container ���� ������ �����ϴ� �Լ�
*	@pre	����
*	@post	����
*	@param ����
*	@return	block_container ���� ������ �����Ѵ�.
*/
	vector<vector<block*>>get_block_container() const;

	/**
*	@brief ���� �󿡼� (a, b) ��ġ�� �ִ� ����� Heuristic length ������ ����
*	@pre	����
*	@post	����
*	@param H_len�� �ñ��� ����� ��ǥ
*	@return	map���� (a, b)�� ��ġ�� ����� h_len ������ ����
*/
	void get_h_info(int a, int b);

	/**
*	@brief ���� ��� ��ġ���� �̵������� ��ġ�� 3X3 ���Ϳ� �����Ͽ� �����Ѵ�. (1, 1)�� ���� ��ġ�̸�, �̵� ������ ���� 1 �Ұ����� ���� 0���� ǥ�õȴ�.
*	@pre	����
*	@post	����
*	@param �̵������� ��ġ�� �˰���� ����� ������ ����
*	@return	input���� ���� �� �����Ϳ��� �̵��ϴ��� ���� 3X3 ���Ϳ� �����Ͽ� ����
*/
	vector<vector<int>> get_movable_space(block* input);

	/**
*	@brief map ������ ȭ�� �� ���
*	@pre	����
*	@post	����
*	@param ����
*	@return	����
*/
	void print_map();

private:
	vector<vector<char>> map;
	vector<vector<int>> Beg_End_location; //stores starting location and ending location
	vector<vector<block*>> block_container;
	priority_queue <block*, vector<block*>, MyCompare> Open_block;
	stack <block*> Closed_block; //initial Closed_block should have starting point.
};


