#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include "Game_card.h"

class Game_processor
{
private:
    /* data */
public:
    Game_processor(vector<Game_card> new_game_cards);
    
    vector<Game_card> game_cards_original;
    vector<Game_card> game_cards_end_game;

    void process_game();
    void process_card(Game_card card);

};


