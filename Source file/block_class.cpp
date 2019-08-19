#include "block_class.h"
/////////////////////////////////////Block class implemetation/////////////////////////////////////
void block::Set_len_so_far() {}
void block::Cal_h_len() {}
//vector<int> block::Get_addr(){}
//block* block::Get_prev_block() {}
bool block::operator>(const block& post_block) { return true; } //compares moved length so far
bool block::operator<(const block& post_block) { return true; }
bool block::operator==(const block& post_block) { return true; }


/////////////////////////////////Block Controller class implemetation/////////////////////////////////
void block_controller::run() {}
void block_controller::scan_map() {} //finds starting point and ending point
void block_controller::closed_to_open() {}
void block_controller::open_to_closed() {}
void block_controller::trace_back() {}//After reaching destination, trace back to starting point to find out route.