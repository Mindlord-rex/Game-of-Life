#include <bits/stdc++.h>

using namespace std;

class GameOfLife{
public:
    vector<vector<int>> random_state(int width, int height){
        vector<vector<int>> state(width, vector<int> (height, 0));

        for(int i=0; i<width; i++){
            for(int j=0; j<height; j++){
                state[i][j] = rand()%2;
            }
        }
        return state;
    }

    vector<vector<int>> dead_state(int width, int height){
        return vector<vector<int>> (width, vector<int> (height, 0));
    }

};

int main(){
        GameOfLife game;
        int width = 10;
        int height = 10;
        vector<vector<int>> state = game.random_state(width, height);
        vector<vector<int>> new_state = game.dead_state(width, height);

        for(int i=0; i<width; i++){
            for(int j=0; j<height; j++){
                cout << state[i][j] << " ";
            }
            cout << endl;
        }

        return 0;
}