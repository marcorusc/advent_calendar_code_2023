#include "utility.h"

void search_for_coordinate(string line, int &ID, vector<int> &win_numbers, vector<int> &numbers)
{
    regex regexp(R"(Card\s+(\d+)\s*:\s*([\d\s]+)\s*\|\s*([\d\s]+))"); // holy crap the amount of tentatives to find the correct regex. Never again.

    win_numbers.clear();
    numbers.clear(); // toccah pulire deh!

    smatch m;

    if (regex_search(line, m, regexp)) {

        string gameId = m[1];
        
        ID = stoi(gameId);

        string numbersAfterColon = m[2];


        istringstream issColon(numbersAfterColon);

        int num;
        while (issColon >> num) {
            win_numbers.push_back(num);
        }

        string numbersAfterPipe = m[3];


        istringstream issPipe(numbersAfterPipe);

        while (issPipe >> num) {
            numbers.push_back(num);
        }

    } else {
        cout << "No match found." << endl;
    }

    return ;
}

vector<vector<int>> get_moore_neigh(vector<int> position, vector<vector<int>>& moores)
{
    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    moores.clear();

    // Calculate neighbors' positions and add to the vector
    for (int i = 0; i < 8; ++i) {
        int nx = position[0] + dx[i];
        int ny = position[1] + dy[i];

        // Check if the neighbor is within the bounds
        if (nx >= 0 && nx <= 139 && ny >= 0 && ny <= 139) { //those values hsould be the sizes of my grid... accordin to vstudio
            moores.push_back({nx, ny});
        }
    }
    return moores;
}

bool compare_moore_coordinates(vector<vector<int>> positions, vector<vector<int>> moores)
{
    for(auto coord_a : positions){
        for (auto coord_b : moores){
            if(coord_a[0] == coord_b[0] && coord_a[1] == coord_b[1]){
                return true;
            }
        }
    }

    return false;
}
