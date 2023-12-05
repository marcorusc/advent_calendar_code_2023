#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <regex>
#include <istream>

using namespace std;

void search_for_coordinate(string line, int &ID, vector<int> &win_numbers, vector<int> &numbers);
vector<vector<int>> get_moore_neigh(vector<int> position, vector<vector<int>>& moores);
bool compare_moore_coordinates(vector<vector<int>>, vector<vector<int>>);