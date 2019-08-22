
/**
*	@function pages
*	@date	2019/08/21
*	@author	 �ѵ���
*/

#pragma once
#include "libraries.h"

/**
*	@brief txt������ �о map ������ 2���� ���� ������ ��ȯ�ϴ� �Լ� 
*	@pre	����
*	@post	map ������ ����� 2���� ���� ���� ����
*	@param �о���� ���� ������ �̸��� input
*	@return	map������ ����� 2���� ���͸� ����
*/
vector<vector <char>> deconde_map(string filename);

/**
*	@brief 2���� ���ͷ� ����� ���� ������ ȭ�鿡 ���
*	@pre ����
*	@post	����
*	@param ȭ�鿡 ����ϰ� ���� �� ���͸� input���� �ִ´�.
*	@return	����
*/
void print2DV(vector<vector<char>> input);