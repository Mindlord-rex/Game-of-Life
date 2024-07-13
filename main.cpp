#include <bits/stdc++.h>
#include "main.h"

using namespace std;


vector<vector<int>> GameOfLife::random_state(int width, int height){
    vector<vector<int>> state = dead_state(width, height);
    srand(time(NULL));
    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            state[i][j] = rand()%2;
        }
    }
    return state;
}

vector<vector<int>> GameOfLife::dead_state(int width, int height){
    return vector<vector<int>> (width, vector<int> (height, 0));
}

vector<vector<int>> GameOfLife::next_board_state(vector<vector<int>> state){
    vector<vector<int>> new_state = dead_state(state[0].size(), state.size());
    for(int i=0;i<state[0].size();i++){
        for(int j=0;j<state.size();j++){
            int sum = 0;

            // wrap around in a circle
            if(i!=0) sum+= state[i-1][j];
            if(j!=0) sum+= state[i][j-1];
            if(i!=0 && j!=0) sum+= state[i-1][j-1];
            if(i!=0 && j!=(state.size()-1)) sum += state[i-1][j+1];
            if(j!=(state.size()-1)) sum += state[i][j+1];
            if(i!=(state[0].size()-1) && j!=0) sum+= state[i+1][j-1];
            if(i!=(state[0].size()-1)) sum+= state[i+1][j];
            if(i!=(state[0].size()-1) && j!=(state.size()-1)) sum+= state[i+1][j+1];

            if(sum<=1) new_state[i][j] = 0;
            else if(sum>3) new_state[i][j] = 0;
            else if(sum==3) new_state[i][j] = 1;
        }
    }
    return new_state;
}

void GameOfLife::render(vector<vector<int>> state){
    // int width = 20;
    // int height = 30;
    // vector<vector<int>> state = random_state(width, height);
    char c;
    for(int i=0; i<state[0].size(); i++){
        for(int j=0; j<state.size(); j++){
            if(state[i][j])c='*';
            else c='.';
            cout << c << " ";
        }
        cout << endl;
    }
}


int main(){
        GameOfLife game;
        vector<vector<int>> state = game.random_state(10,10);
        game.render(state);
        cout<<"##################"<<endl;
        game.render(game.next_board_state(state));

        return 0;
}