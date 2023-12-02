#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "game.h"

using namespace std;

int main(){

    list<int> in_bag = {12, 13, 14}; // honestely here I wanted to add a cin so it would have been possible to manually inputting the number of red, green and blue cubes...

    
    string line;
    ifstream input_file;
    input_file.open("input_file.txt");

    if(input_file.is_open()){

        int result_1 = 0;

        int result_2 = 0;

        while(getline(input_file, line)){

            game myGame(line, in_bag);

            result_2 += myGame.power;

            if(myGame.playable){
                result_1 += myGame.ID;
            }
        }

        cout << "Final first result is: " << result_1 << endl;

        cout << "Final second result is: " << result_2 << endl;

    }


    return 0;
}