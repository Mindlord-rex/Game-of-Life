#ifndef MAIN_H
#define MAIN_H

#include <bits/stdc++.h>
using namespace std;

class GameOfLife{
public:
    vector<vector<int>> random_state(int width, int height);
    vector<vector<int>> dead_state(int width, int height);
    vector<vector<int>> next_board_state(vector<vector<int>> state);
    void render(vector<vector<int>> state);
};

#endif
