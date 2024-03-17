#include <iostream>
#include <queue>
#include <vector>
#include "../../UnitTests.h"
using namespace std;

class Node {
public:
    int x, y, distance;
    Node() {
        // Default constructor
    }
    Node(int x, int y) {
        this->x = x;
        this->y = y;
        this->distance = 0;
    }
    Node(int x, int y, int distance) {
        this->x = x;
        this->y = y;
        this->distance = distance;
    }
};


int shortestPathUsingBFS(int grid[][1000], int n, int m, Node start, Node des) {
    // Hanld sepcial cases
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    if (n == 1) return 1;
    
    int directions[8][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, -1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}};
    int numDirections = sizeof(directions) / sizeof(directions[0]);
    queue<Node> path;
    path.push(start);
    while (!path.empty()) {
        Node cur = path.front();
        path.pop();
        for (int i = 0; i < numDirections; i++) {
            Node nextNode(cur.x + directions[i][0], cur.y + directions[i][1], cur.distance + 1);

            if ((grid[nextNode.x][nextNode.y] == 0) && (0 <= nextNode.x) && (nextNode.x < m) 
            && (0 <= nextNode.y) && (nextNode.y < n)) {
                if ((nextNode.x == des.x) && (nextNode.y == des.y)) {
                    return nextNode.distance;
                }
                grid[nextNode.x][nextNode.y] = 1;
                path.push(nextNode);
            }
        }
    }
    return -1;
}

int main() {
    int tc1[][1000] = {
        {0, 0, 0, 0, 0},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };
    Node start(0, 0, 1);
    Node des(4, 4);
    runTest<int>(shortestPathUsingBFS(tc1, 5, 5, start, des), 7);
    return 0;
}
