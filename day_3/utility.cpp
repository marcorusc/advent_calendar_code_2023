#include "utility.h"

vector<vector<int>> search_for_coordinate(string line)
{
    regex regexp("\\d+");

    smatch m;

    vector<vector<int>> engine_init;

    int pos = 0;

    vector<int> entry ;

    while (regex_search(line, m, regexp)) {

        int current_pos = m.position();
        pos += current_pos + m.length();
        int value = stoi(m.str());
        entry.push_back(value);
        entry.push_back(pos);
        entry.push_back(m.length());
        // Update the search string to continue searching
        line = m.suffix().str();

        engine_init.push_back(entry);

        entry.clear();
    }

    return engine_init;
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
