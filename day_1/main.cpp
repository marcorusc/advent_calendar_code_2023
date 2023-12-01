#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(){

    string line;
    ifstream input_file;
    input_file.open("input_file.txt");

    map<string, int> map_number{{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

    if(input_file.is_open()){

        int result = 0;

        while(getline(input_file, line)){

            //cout << line << '\n';

            string coord1, coord2;

            int pos1 = line.find_first_of("1234567890");
            coord1 = (1, line.at(pos1));
            
            int pos2 = line.find_last_of("1234567890");
            coord2 = (1, line.at(pos2));

            int found = line.length();
            for (const auto& [key, value] : map_number){
                int pos_string1 = line.find(key);

                if (pos_string1 != string::npos && pos_string1 < pos1 && pos_string1 < found){
                    coord1 = to_string(value);
                    found = pos_string1;
                }
            } 

            found = 0;
            for (const auto& [key, value] : map_number){
                int pos_string2 = line.rfind(key);

                if (pos_string2 != string::npos && pos_string2 > pos2 && pos_string2 > found){
                    coord2 = to_string(value);
                    found = pos_string2;
                    }
            }  

            string coordinate = coord1 + coord2;
            int coord_int = stoi(coordinate);
            result += coord_int;

        }

        input_file.close();

        cout << result << endl;

    }

    return 0;
}