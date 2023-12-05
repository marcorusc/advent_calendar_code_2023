#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "utility.h"
#include "Game_processor.h"

using namespace std;

int main(){
    string line;

    ifstream input_file;

    vector<Game_card> list_of_cards;

    input_file.open("input_file.txt");

    if (input_file.is_open()){

        int ID;
        vector<int> win_numbers;
        vector<int> numbers;

        while(getline(input_file, line)){

            cout << line << endl;

            search_for_coordinate(line, ID, win_numbers, numbers);

            Game_card card(ID, win_numbers, numbers);

            list_of_cards.push_back(card);

        }
    }

    int result = 0;

    for(auto game : list_of_cards){
        result += game.points;
    }

    cout << "The first final result is: " << result << endl;

    Game_processor processor(list_of_cards);

    processor.process_game();

    cout << "The second final result is :" << processor.game_cards_end_game.size() << endl;

    return 0;
}