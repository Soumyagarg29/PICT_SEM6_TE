#include <bits/stdc++.h>
using namespace std;

// Define possible movements: up, down, left, right
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

// Node structure to represent each cell in the grid
class Node {
public:
    int row, col, cost, heuristic; // cost -> f(n) = g(n) + h(n) // heuristic -> h(n) = |x1 - x2| + |y1 - y2|

    Node(int r, int c, int g, int h) { row = r, col = c, cost = g, heuristic = h; }

    bool operator>(const Node &other)const  {
        return (cost + heuristic) > (other.cost + other.heuristic);
    }
};

class AlgorithmAStar
{

public:
    int rows, cols;
    AlgorithmAStar(int r, int c)
    {
        rows = r;
        cols = c;
    }
    // A* algorithm function
    vector<pair<int, int>> astarAlgorithm(vector<vector<int>> &grid, pair<int, int> start, pair<int, int> goal)
    {
        // Priority queue to store nodes based on their total cost (priority queue uses the > operator)
        priority_queue<Node, vector<Node>, greater<Node>> openList;

        // Initialize the start node and add it to the priority queue
        openList.push(Node(start.first, start.second, 0, abs(start.first - goal.first) + abs(start.second - goal.second)));

        // Matrix to store the cost of reaching each cell
        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX)); // f(n) = g(n) + h(n)

        // Parent matrix to store the parent of each cell for reconstructing the path
        vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

        // Set the cost of the starting cell to 0
        cost[start.first][start.second] = 0;

        // Main A* loop
        while (!openList.empty())
        {
            // Get the node with the lowest cost from the openList
            Node current = openList.top();
            openList.pop();

            // Check if we reached the goal
            if (current.row == goal.first && current.col == goal.second)
            {
                // Reconstruct the path
                vector<pair<int, int>> path;
                while (parent[current.row][current.col] != make_pair(-1, -1))
                {
                    path.push_back({current.row, current.col});
                    current = {parent[current.row][current.col].first, parent[current.row][current.col].second, 0, 0};
                }
                path.push_back({start.first, start.second});

                reverse(path.begin(), path.end());
                return path;
            }

            // Explore neighbors
            for (int i = 0; i < 4; ++i)
            {
                int new_row = current.row + dr[i];
                int new_col = current.col + dc[i];

                // Check if the new position is within the grid boundaries
                if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && grid[new_row][new_col] == 0)
                {
                    int new_cost = current.cost + 1;

                    // If the new cost is lower than the current cost to reach the neighbor, update the cost and push to the queue
                    if (new_cost < cost[new_row][new_col])
                    {
                        cost[new_row][new_col] = new_cost;
                        parent[new_row][new_col] = {current.row, current.col};
                        openList.push(Node(new_row, new_col, new_cost, abs(new_row - goal.first) + abs(new_col - goal.second)));
                    }
                }
            }
        }

        // If the priority queue is empty and we haven't reached the goal, return an empty path
        return {};
    }
};

int main()
{

    int n;
    cout << "Enter the size of the grid: ";
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter the value of grid[" << i << "][" << j << "]: ";
            cin >> grid[i][j];
        }
    }

    // Define start and goal positions
    pair<int, int> start, goal;

    // input start and goal values
    cout << "Enter the start position: ";
    cin >> start.first >> start.second;
    cout << "Enter the goal position: ";
    cin >> goal.first >> goal.second;

    // Find the path using A* algorithm
    AlgorithmAStar obj(n, n);
    vector<pair<int, int>> path = obj.astarAlgorithm(grid, start, goal);

    // Print the path
    if (path.empty())
    {
        cout << "No path found!" << endl;
    }
    else
    {
        cout << "Path: ";
        for (const auto &point : path)
        {
            cout << "(" << point.first << ", " << point.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
