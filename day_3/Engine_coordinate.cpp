#include "Engine_coordinate.h"

Engine_coordinate::Engine_coordinate(vector<int> data, int line_number)
{
    set_value(data[0]);
    set_positions(data[1], line_number, data[2]);
    set_len(data[2]);
}

Engine_coordinate::~Engine_coordinate()
{
}

void Engine_coordinate::set_value(int entry_value)
{
    value = entry_value;
    return ;
}

void Engine_coordinate::set_positions(int x, int y, int l)
{
    vector<int> entry ;
    entry.assign(2, 0);
    for(int i = 1; i <= l; i++){
        entry[0] = x - i;
        entry[1] = y;

        positions.push_back(entry);
    }
}

void Engine_coordinate::set_len(int entry_len)
{
    len = entry_len;
    return ;
}
