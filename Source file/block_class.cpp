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
	if (length_so_far == -1) {
		length_so_far = input;
	}
	else {
	if(length_so_far>input) //if newly added path's LSF is shorter, change existing value to new value.
		length_so_far = input;
	}
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

void block::print_block() {
	cout <<"Address: "<< addr[0] << ", " << addr[1] << endl;
	cout <<"Heuristic length: "<< H_length << endl;
	cout << "Length so far: " << length_so_far << endl;
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
	cout << Beg_End_location[0][0] << ", " << Beg_End_location[0][1] << endl;
	cout << "Destination Address\n";
	cout << Beg_End_location[1][0] << ", " << Beg_End_location[1][1] << endl;
}
void block_controller::initialize_block_map() {
	vector<block*> row;
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
			block* element=new block(temp);
			row.push_back(element); 
			temp.clear();
			temp2.clear();
		}
		block_container.push_back(row);
		row.clear();
		
	}
	cout << map.size() << ", " << map[0].size()<<endl;
	
	cout << block_container.size() << ", " << block_container[0].size() << endl;

	cout << "Finished initializeing block_map from map\n";
	/*
	for (int i = 0; i < block_container.size(); i++) {
		for (int j = 0;j<block_container[0].size();j++) {
			cout << block_container[i][j]->Get_H_len() << " ";
		}
		cout << endl;
	}
	*/
}

void block_controller::run() {
	cout << "adding " << Beg_End_location[0][0] << ", " << Beg_End_location[0][1] << endl;
	block_container[Beg_End_location[0][0]][Beg_End_location[0][1]]->Set_len_so_far(0) ;
	Closed_block.push(block_container[Beg_End_location[0][0]][Beg_End_location[0][1]]);//adding starting point block to closed block
	closed_to_open();
}

void block_controller::closed_to_open() {
	block* temp=Closed_block.top();
	cout << "1st block " << temp->Get_addr()[0] << ", " << temp->Get_addr()[1] << endl;
	vector<vector<int>> temp2=get_movable_space(temp);
	for (int i = 0;i<3;i++) {
		for (int j = 0;j<3;j++) {
			if (temp2[i][j] == 1) {
				block_container[temp->Get_addr()[0] + i - 1][temp->Get_addr()[1] + j - 1]->Set_prev_block(temp); //set prev block
				block_container[temp->Get_addr()[0] + i - 1][temp->Get_addr()[1] + j - 1]->Set_len_so_far(temp->Get_len_so_far()+sqrt(pow(temp->Get_addr()[0]-(temp->Get_addr()[0] + i - 1),2)+pow(temp->Get_addr()[1]-(temp->Get_addr()[1] + j - 1),2))); //set LSF based on prev block
				Open_block.push(block_container[temp->Get_addr()[0] + i - 1][temp->Get_addr()[1] + j - 1]);
				map[temp->Get_addr()[0] + i - 1][temp->Get_addr()[1] + j - 1] = 'X';  //mark for open block
			}
		}
	}
}

void block_controller::open_to_closed() {

}

void block_controller::trace_back() {}//After reaching destination, trace back to starting point to find out route.

void block_controller::get_h_info(int a, int b) {
	cout<<block_container[a][b]->Get_H_len()<<endl;
}


vector<vector<int>> block_controller::get_movable_space(block* input) {//x, y is current location
	//look 8 surrounding spaces
	//양옆이 있나 먼저 확인하고 없으면 두번 째 조건은 필요없음
	int index[3] = { -1,0,1, };
	vector<int> addr = input->Get_addr();
	vector<vector<int>> movable_space(3, vector<int>(3, 0)); //initialize 3X3vector filled with 0.
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (map[addr[0] + index[i]][addr[1] + index[j]] == '.') {
				movable_space[i][j] = 1;//if block is empty, save 1 to vector space
			}
		}
	}
	movable_space[1][1] = 0;
	/*
	 * Need Addtional Code for diagonal wall.
	 */
	return movable_space;
}

void block_controller::print_map() {
	for (int i = 0;i<map.size();i++) {
		for (int j = 0;j<map[i].size();j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

vector<vector<block*>> block_controller::get_block_container() const{
	return block_container;
}