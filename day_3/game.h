#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>

using namespace std;

class game
{
private:
    /* data */
public:

    int ID;
    int n_set;
    list<int> r_cubes;
    list<int> b_cubes;
    list<int> g_cubes;
    list<int> min_bag;
    int power;
    bool playable;

    game(string round, list<int> in_bag);
    void set_ID(string round);
    void set_n_set(string round);
    void set_r_cubes(string round);
    void set_b_cubes(string round);
    void set_g_cubes(string round);
    void set_is_playable(list<int> in_bag);
    void find_min_bag();
    void set_power_of_the_universe_of_friggin_game();
};
