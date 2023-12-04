#include "game.h"
#include <regex>
using namespace std;


game::game(string round, list<int> in_bag)
{
    set_ID(round);
    set_n_set(round);
    set_r_cubes(round);
    set_g_cubes(round);
    set_b_cubes(round);
    set_is_playable(in_bag);
    find_min_bag();
    set_power_of_the_universe_of_friggin_game(); //I really want to see who notice this crap lol
}

void game::set_r_cubes(string round){

    regex regexp("\\d+ red+");

    smatch m;

    while (regex_search(round, m, regexp)) {

        for (auto x : m) {
            string match = x.str();
            smatch n;
            regex regexp2("\\d+");
            regex_search(match, n, regexp); 

            for (auto x : m) 
                r_cubes.push_back(stoi(x.str()));
        
        }
        // Update the search string to continue searching
        round = m.suffix().str();
    }

}

void game::set_b_cubes(string round){

    regex regexp("\\d+ blue+");

    smatch m;

    while (regex_search(round, m, regexp)) {

        for (auto x : m) {
            string match = x.str();
            smatch n;
            regex regexp2("\\d+");
            regex_search(match, n, regexp); 

            for (auto x : m) 
                b_cubes.push_back(stoi(x.str()));
        
        }
        // Update the search string to continue searching
        round = m.suffix().str();
    }

}

void game::set_g_cubes(string round){

    regex regexp("\\d+ green+");

    smatch m;

    while (regex_search(round, m, regexp)) {

        for (auto x : m) {
            string match = x.str();
            smatch n;
            regex regexp2("\\d+");
            regex_search(match, n, regexp); 

            for (auto x : m) 
                g_cubes.push_back(stoi(x.str()));
        
        }
        // Update the search string to continue searching
        round = m.suffix().str();
    }

}

void game::set_ID(string round){

    regex regexp("\\d+");  
    smatch m;

    regex_search(round, m, regexp);

    for (auto x : m) {
        ID = stoi(x.str());
    }
    
}

void game::set_n_set(string round){

    regex regexp(";+");

    smatch m;

    regex_search(round, m, regexp);

    int set_number = 0;

    while (regex_search(round, m, regexp)) {

        set_number += 1;
        // Update the search string to continue searching
        round = m.suffix().str();
    }

    n_set = set_number + 1;
    
}

void game::set_is_playable(list<int> in_bag){

    auto it = std::next(in_bag.begin(), 0);
    int red_cubes = *it;
    it = std::next(in_bag.begin(), 1);
    int green_cubes = *it;
    it = std::next(in_bag.begin(), 2);
    int blue_cubes = *it;

    for (const auto& element : r_cubes){
        if (element > red_cubes){
            playable = false;
            return ;
        }
    }

    for (const auto& element : g_cubes){
        if (element > green_cubes){
            playable = false;
            return ;
        }
    }

    for (const auto& element : b_cubes){
        if (element > blue_cubes){
            playable = false;
            return ;
        }
    }

    playable = true;

    return ;

}

void game::find_min_bag()
{
    int min_red = 0;
    int min_green = 0;
    int min_blue = 0;

    for (const auto& element : r_cubes){
        if (element > min_red){
            min_red = element;
        }
    }

    for (const auto& element : g_cubes){
        if (element > min_green){
            min_green = element;
        }
    }

    for (const auto& element : b_cubes){
        if (element > min_blue){
            min_blue = element;
        }
    }

    min_bag = {min_red, min_green, min_blue};

}

void game::set_power_of_the_universe_of_friggin_game()
{

    auto it = std::next(min_bag.begin(), 0);
    int red_cubes = *it;
    it = std::next(min_bag.begin(), 1);
    int green_cubes = *it;
    it = std::next(min_bag.begin(), 2);
    int blue_cubes = *it;

    power = red_cubes * green_cubes * blue_cubes;

}
