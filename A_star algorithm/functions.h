
/**
*	@function pages
*	@date	2019/08/21
*	@author	 한동훈
*/

#pragma once
#include "libraries.h"

/**
*	@brief txt파일을 읽어서 map 파일을 2차원 벡터 정보로 변환하는 함수 
*	@pre	없음
*	@post	map 정보가 저장된 2차원 벡터 정보 형성
*	@param 읽어오고 싶은 파일의 이름이 input
*	@return	map정보가 저장된 2차원 벡터를 리턴
*/
vector<vector <char>> deconde_map(string filename);

/**
*	@brief 2차원 벡터로 저장된 지도 정보를 화면에 출력
*	@pre 없음
*	@post	없음
*	@param 화면에 출력하고 싶은 맵 벡터를 input으로 넣는다.
*	@return	없음
*/
void print2DV(vector<vector<char>> input);