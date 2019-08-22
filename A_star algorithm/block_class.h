
/**
*	@block class header
*	@date	2019/08/21
*	@author	 �ѵ���
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
*	@brief   ��������� �̵��Ÿ��� �����Ѵ�. 
*	@pre	 �ʱ��� elength_so_far�� -1�� �����Ǿ��ִ�.
*	@post	 ������ length_so_far�� -1�� input���� ����. ������ length_so_far���� input ���� ������ ����.
*	@param  double���� input
*	@return	���� ����Ǿ����� 1��, �ƴϸ� 0�� ����
*/
	int Set_len_so_far(double input); //return 1 if value changed, return. return 0 if value has not changed.
	
		/**
*	@brief ���� ��� ������ �ִ� ����� ������� ������ ������ ����Ų��.
*	@pre	open_block���� block�� push �Ǳ� �������� nullptr�� �������� �������� nullptr�� ����Ų��.
*	@post	prev_block�� ��ġ�� ������ ������ ����ȴ�.
*	@param prev_block ������ ������ ������ �ּ�
*	@return	����
*/
	void Set_prev_block(block* prev_block);
	
	/**
*	@brief �ش� ����� �ּҸ� ���� ���·� �������ش�. 
*	@pre	����
*	@post	����
*	@param ����
*	@return	�ش� ����� �ּҸ� 1X2 ���ͷ� ��ȯ���ش�. 
*/
	vector<int> Get_addr()const;
	
	/**
*	@brief �ش� ��� ������ ����� ������ �ּ� ������ �����Ѵ�. 
*	@pre	����
*	@post	����
*	@param ����
*	@return	�ش� ����� �ֱ� ���� �ִ� ����� ������ �ּҸ� �����Ѵ�. 
*/
	block* Get_prev_block()const;
	
	/**
*	@brief ������������ ���� �Ÿ�(Heuristic length) ���� ��ȯ�Ѵ�.
*	@pre	����
*	@post	����
*	@param ����
*	@return	H_len ������ ��ȯ�Ѵ�.
*/
	double Get_H_len()const;
	
	/**
*	@brief ������� ������ �Ÿ��� ��ȯ�Ѵ�.
*	@pre	����
*	@post	����
*	@param ����
*	@return	������� �ش� ��ϱ��� �̵��� �Ÿ�(len_so_far)�� �����Ѵ�.
*/
	double Get_len_so_far()const;
	
	/**
*	@brief ������� �̵��Ÿ��� Heuristic length�� �� ������ �����Ѵ�.
*	@pre	����
*	@post	����
*	@param ����
*	@return	������� �̵��Ÿ��� heuristic length�� ���� �����Ѵ�.
*/
	double Get_TTL() const;
	/////////Operator Overloading/////////
	//bool operator>(const block& post_block);
	//bool operator<(const block& post_block);
	//bool operator==(const block& post_block);
	
		/**
*	@brief �ش� ��Ͽ� ���� ������ ����Ѵ�.
*	@pre	����
*	@post	����
*	@param ����
*	@return	����
*/
	void print_block();
private:
	vector<int> addr; //block's  address in 2D vector
	block* prev; //block object right before this block
	double H_length; //straight length to destination. H stands for heuristic
	double length_so_far; //moved length from starting point which has to be minimal
};

