#include "Maze.cpp"
using namespace std;
#define MAX 1000


namespace solutions
{

int getNumberOfWalls(MazeNode *a_node)
{
    int wall_counter = 0;
    for (directions::nesw dir = directions::NORTH; dir < directions::EAST; dir = directions::nesw(dir + 1))
    {
        if (a_node->getDirectionNode(dir) == nullptr || a_node->getDirectionNode(dir)->isWall() || a_node->getDirectionNode(dir)->isVisited())
        {
            wall_counter++;
        }
    }
    return wall_counter;
}

bool canTravel(MazeNode *a_node)
{
    if (a_node->isVisited() || a_node->isWall())
    {
        return false;
    }
    return true;
}

std::vector<MazeNode> solveDFS(Maze &a_maze){

}

std::vector<MazeNode> solveBFS(Maze &a_maze)
{
}

std::vector<MazeNode> solveDEF(Maze &a_maze)
{
}

std::vector<MazeNode> solveCustom(Maze &a_maze)
{
}
} // namespace solutions
