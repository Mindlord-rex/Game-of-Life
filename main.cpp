#include <bits/stdc++.h>
#include "main.h"
#include <unistd.h>

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

int next_cell_value(int x, int y, vector<vector<int>> state){
    int width = state[0].size();
    int height = state.size();
    int sum = 0;

    for(int i=x-1; i<(x+1)+1;i++){
        if(i<0 || i>=width) continue;

        for(int j=y-1; j<(y+1)+1;j++){
            if(j<0 || j>=height) continue;
            if(i==x && j==y) continue;
            if(state[i][j]==1) sum += 1;
        }
    }

    if(state[x][y]==1){
        if(sum<=1) return 0;
        else if(sum<=3) return 1;
        else return 0;
    }else{
        if(sum==3) return 1;
        else return 0;
    }
}

vector<vector<int>> GameOfLife::next_board_state(vector<vector<int>> state){
    vector<vector<int>> new_state = dead_state(state[0].size(), state.size());
    for(int i=0;i<state[0].size();i++){
        for(int j=0;j<state.size();j++){
            new_state[i][j] = next_cell_value(i, j, state);
        }
    }
    return new_state;
}

void GameOfLife::render(vector<vector<int>> state){

    char c;
    for(int i=0; i<state[0].size(); i++){
        for(int j=0; j<state.size(); j++){
            if(state[i][j])c='#';
            else c='.';
            cout << c << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> GameOfLife::load_board_state(string path){
    ifstream file;
    vector<vector<int>> board_state;
    file.open(path);
    if(file.is_open()){
        string board;
        while(getline(file,board)){
            vector<int> row;
            for(char ch: board){
                int cell_value = ch - '0';
                row.push_back(cell_value);
            }
            board_state.push_back(row);
        }
        file.close();
    }

    return board_state ;
}

void GameOfLife::run_forever(vector<vector<int>> state){
    
    while(true){
        render(state);
        cout<<"##################"<<endl;
        state = next_board_state(state);
        sleep(0.03);
    }
}


int main(){
        GameOfLife game;

        vector<vector<int>> state = game.load_board_state("D:\\code\\Projects\\Game of Life\\toad.txt");
        game.run_forever(state);
        

        return 0;
}