// #include "Maze.hpp"
// #include "MazeNode.hpp"
#include "Solutions.cpp"
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main(){
    Maze thing("maze_1.csv");
    stack<MazeNode*> mazeStack;
    vector<MazeNode*> nodeVector;
    mazeStack.push(thing.getCurrentNode());
    while (thing.getCurrentNode() != thing.getLastNode()){
        thing.getCurrentNode()->setVisited();
        for (directions::nesw dir = directions::NORTH; dir < directions::WEST; dir = directions::nesw(dir + 1)){
            if (thing)
        }
        // if (thing.getCurrentNode()->isVisited()){
        //     mazeStack.
        // }
        // nodeVector.push_back(thing.getCurrentNode());
        // mazeStack.push(thing.getCurrentNode());
        
    }
    
    return 0;
}
