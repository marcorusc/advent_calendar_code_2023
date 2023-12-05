#include "Game_processor.h"

Game_processor::Game_processor(vector<Game_card> new_game_cards)
{
    game_cards_original = new_game_cards;
    return ;
}

void Game_processor::process_game()
{
    for (auto it = game_cards_original.begin(); it != game_cards_original.end(); it++){
        game_cards_end_game.push_back(*it);
        process_card(*it);
    }
}

void Game_processor::process_card(Game_card card)
{
    int number_of_copies = card.total_win_numbers.size();
    if(number_of_copies == 0){
        return ;
    }
    int ID = card.ID;
    int index_to_copy;
    for(int i = 1; i <= number_of_copies; i++){
        index_to_copy = (ID-1) + i;
        game_cards_end_game.push_back(game_cards_original[index_to_copy]);
        process_card(game_cards_original[index_to_copy]);
    }
    return ;
}
