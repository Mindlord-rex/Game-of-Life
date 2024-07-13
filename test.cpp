#include "main.h"
using namespace std;

//g++ -Wall -Wextra -g3 test.cpp main.cpp -o output\main.exe

//cd output
//.\main.exe


int main(){
        GameOfLife game;
        
        vector<vector<int>> init_state1 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

        vector<vector<int>> expected_next_state1 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        vector<vector<int>> actual_next_state1 = game.next_board_state(init_state1);
        assert(expected_next_state1 == actual_next_state1);

        vector<vector<int>> init_state2 = {{0, 0, 1}, {0, 1, 1}, {0, 0, 0}};
        vector<vector<int>> expected_next_state2 = {{0, 1,1}, {0, 1, 1}, {0, 0, 0}};
        vector<vector<int>> actual_next_state2 = game.next_board_state(init_state2);
        assert(expected_next_state2 == actual_next_state2);

        return 0;
}

