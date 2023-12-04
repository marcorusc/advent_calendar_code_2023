#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <regex>

using namespace std;

vector<vector<int>> search_for_coordinate(string line);
vector<vector<int>> get_moore_neigh(vector<int> position, vector<vector<int>>& moores);
bool compare_moore_coordinates(vector<vector<int>>, vector<vector<int>>);