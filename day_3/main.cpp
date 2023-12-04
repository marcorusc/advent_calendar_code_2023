#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "utility.h"
#include "Engine_coordinate.h"

using namespace std;

int main(){

    list<int> in_bag = {12, 13, 14}; // honestely here I wanted to add a cin so it would have been possible to manually inputting the number of red, green and blue cubes...

    vector<Engine_coordinate> list_of_engine_coordinate ;
    set<Engine_coordinate> uniqueEngineCoordinates;
    string line;
    ifstream input_file;
    input_file.open("input_file.txt");

    if(input_file.is_open()){

        int iterator_line = 0;

        while(getline(input_file, line)){

            vector<vector<int>> vector_of_entries = search_for_coordinate(line);

            for (vector<int> entry : vector_of_entries){
                Engine_coordinate coordinate(entry, iterator_line);
                list_of_engine_coordinate.push_back(coordinate);
            }
            iterator_line++;
        }

    for (auto coordinate : list_of_engine_coordinate){
        cout << coordinate.value << endl;
        for (auto pos_coor : coordinate.positions){
            cout << "x: " << pos_coor[0] << "  " << "y: " << pos_coor[1] << endl;
        }
        cout << coordinate.len << endl;
    }
    }

    input_file.close();

    input_file.open("input_file.txt");

    string new_line;

    int result2;

    if(input_file.is_open()){
        
        
        cout << "Input file is open" << endl;

        vector<int> position ;
        vector<vector<int>> moore_neigh;
        vector<Engine_coordinate> gears;
        int ratio;
        position.assign(2,0);
        int iterator_line = 0;

        while(getline(input_file, new_line)){

            regex regexp2(R"(\*)"); //regex for the second solution

            smatch n;
            
            int pos = 0;

            while (regex_search(new_line, n, regexp2)) {

                int current_pos = n.position();
                pos += current_pos;
                position[0] = pos;
                position[1] = iterator_line;

                cout << n.str() << endl;

                get_moore_neigh(position, moore_neigh);

                for (auto coordinate : list_of_engine_coordinate){

                    if(compare_moore_coordinates(moore_neigh, coordinate.positions)){
                        uniqueEngineCoordinates.insert(coordinate);
                        gears.push_back(coordinate);
                    }

                }
                if(gears.size() == 2){
                    ratio = gears[0].value * gears[1].value;
                    result2 += ratio;
                }
                gears.clear();
                // Update the search string to continue searching
                new_line = n.suffix().str();
                pos = pos + 1;

            }
             iterator_line++;
        }

    }

    int result = 0;
    for (auto coordinate : uniqueEngineCoordinates){
        //cout << coordinate.value << endl;
        //cout << coordinate.positions[0][0] << endl;
        //cout << coordinate.len << endl;
        result += coordinate.value;
    }

    cout << "Final first result is: " << result;
    cout << "Final second result is: " << result2;
    return 0;
}