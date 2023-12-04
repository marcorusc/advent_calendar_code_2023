#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <regex>

using namespace std;

class Engine_coordinate
{
private:
    /* data */
public:
    Engine_coordinate(vector<int> data, int line_number);
    ~Engine_coordinate();

    bool operator<(const Engine_coordinate& other) const {
        // Compare based on x-coordinate first
        if (positions[0][0] < other.positions[0][0]) {
            return true;
        }
        // If x-coordinates are equal, compare based on y-coordinate
        else if (positions[0][0] == other.positions[0][0] && positions[0][1] < other.positions[0][1]) {
            return true;
        }
        // If both x and y are equal, consider the objects equal
        return false;
    }

    int value; // value of the coordinate
    int len; //length of the number (ex: 223 has len = 3), usefull to find the position in the grid of each coordinate
    vector<vector<int>> positions; // vector storing the positions of each number of the coordinate

    void set_value(int);
    void set_positions(int x, int y, int l);
    void set_len(int entry_len);

};
