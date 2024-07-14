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

            if(i==0) sum += state[state.size()-1][j];
            if(j==0) sum += state[i][state[0].size()-1];
            if(i==0 && j==0) sum += state[state.size()-1][state[0].size()-1];
            if(i==state.size()-1) sum += state[0][j];
            if(j==state[0].size()-1) sum += state[i][0];

            if(sum<=1) new_state[i][j] = 0;
            else if(sum>3) new_state[i][j] = 0;
            else if(sum==3) new_state[i][j] = 1;
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


int main(){
        GameOfLife game;

        vector<vector<int>> state = game.random_state(10,10);
        int i=0;
        while(i<5){
            state = game.next_board_state(state);
            game.render(state);
            cout<<"##################"<<endl;
            i++;
        }

        ;
        

        return 0;
}