#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <regex>

using namespace std;

class Game_card
{
private:
    /* data */
public:
    Game_card(int ID, vector<int> win_numbers, vector<int> numbers);

    int ID; // Id of the game card
    vector<int> win_numbers; // winning numbers
    vector<int> numbers; // numbers of the game
    int points = 0; // point of the card game
    vector<int> total_win_numbers; // numbers in win_numbers

    void set_ID(int);
    void set_win_numbers(vector<int> entry);
    void set_numbers(vector<int> entry);
    void set_points();
    void set_total_win_numbers();

};
