#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct Node
{
    int parent = -1;
    int level = 0;
};

//reaching all nodes of the tree
void bfs(int starting_node, int a[1001][1001], int n, Node node[]) {
    bool visted[1001] = { false };
    queue<int> reachNodes;

    reachNodes.push(starting_node);
    visted[starting_node] = true;
  
    while ( !reachNodes.empty() )
    {
        int u = reachNodes.front();

        reachNodes.pop();
        //cout << u << " ";

        for (int i = 1; i <= n; i++)
        {
            if (a[u][i] == 1 && !visted[i])
            {
                reachNodes.push(i);
                visted[i] = true;
                node[i].parent = u;
                node[i].level = node[u].level + 1;
            }
        }
    }

}

int main() {
    ifstream read;
    read.open("BFS/input.txt");

    int queries;

    read >> queries;
    for (int q = 0; q < queries; q++) {
        int n, m, starting_node;
        int (*a)[1001] = new int[1001][1001];
        Node *node = new Node[1001];

        read >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            read >> u >> v;
            a[u][v] = 1;
            a[v][u] = 1;
        }

        read >> starting_node;

        //reach graph by bfs
        bfs(starting_node, a, n, node);

        //printf distance from starting node to all other nodes
        for (int i = 1; i <= n; i++)
        {
            if (i != starting_node)
            {
                if (node[i].parent == -1)
                    cout << "-1 ";
                else
                {
                    cout << node[i].level * 6 << " "; // 6 is distance of a edge
                }
            }
        }

        cout << endl;
    }

    return 0;
}

