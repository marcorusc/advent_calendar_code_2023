#include "Game_card.h"

Game_card::Game_card(int ID, vector<int> win_numbers, vector<int> numbers)
{
    set_ID(ID);
    set_win_numbers(win_numbers);
    set_numbers(numbers);

    set_total_win_numbers();

    set_points();
}

void Game_card::set_ID(int id_number)
{
    ID = id_number;
    return ;
}

void Game_card::set_win_numbers(vector<int> entry)
{
    win_numbers = entry;
    return ;
}

void Game_card::set_numbers(vector<int> entry)
{
    numbers = entry;
    return ;
}

void Game_card::set_points()
{
    if(total_win_numbers.size() == 0){
        return ;
    }
    points = 1;
    int win_len = total_win_numbers.size() - 1;
    for(int i = 0; i < win_len; i++){
        points *= 2;
    }

}

void Game_card::set_total_win_numbers()
{
    for(int number : numbers){
        for(int win_number : win_numbers){
            if(number == win_number){
                total_win_numbers.push_back(number);
            }
        }
    }

    return ;
}
