#include "functions.h"

vector<vector <char>> deconde_map(string filename) {
	vector<vector<char >> map_vector;
	ifstream infile(filename);
	string line;

	vector<char> temp;
	while (getline(infile, line)) {
		temp.push_back('o');
		for (string::iterator iter = line.begin();iter!=line.end();iter++) {
			temp.push_back(*iter);
		}
		temp.push_back('o');
		map_vector.push_back(temp);
		temp.clear();
	}
	
	for (int i=0; i < map_vector[0].size(); i++) {
		temp.push_back('o');
	}
	map_vector.push_back(temp);
	map_vector.insert(map_vector.begin(), temp);
	return map_vector;
}

void print2DV(vector<vector<char>> input) {
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].size(); j++) {
			cout << input[i][j];
		}
		cout << endl;
	}
}