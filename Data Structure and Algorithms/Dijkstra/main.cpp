#include <iostream> 
#include <limits.h>
#include <fstream>  
using namespace std;

int minDistance(long long dist[], bool sptSet[], int n)
{
    long long min = LLONG_MAX;
    int min_index;

    for (int v = 1; v <= n; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[3001][3001], int src, int n) {
    long long dist[3001];
    bool sptSet[3001] = { false };

    for (int i = 0; i <= n; i++)
        dist[i] = LLONG_MAX;
    dist[src] = 0;

    for (int count = 1; count < n; count++) {
        int u = minDistance(dist, sptSet, n);

        sptSet[u] = true;

        for (int v = 1; v <= n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != LLONG_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    for (int i = 1; i <= n; i++) {
        if (i != src)
        {
            if (dist[i] == LLONG_MAX) cout << "-1 ";
            else cout << dist[i] << " ";
        } 
    }

}

int main()
{
    ifstream read;
    read.open("D:\\Projects\\CPP\\Data Structure and Algorithms\\Dijkstra\\input.txt");

    int numTC;
    read >> numTC;

    for (int tc = 0; tc < numTC; tc++)
    {
        int(*graph)[3001] = new int[3001][3001];
        int n, starting_position;
        long m;

        read >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++)
        {
            int u, v, distance;
            
            read >> u >> v >> distance;
            if (graph[u][v] > 0) {
                distance = (distance < graph[u][v]) ? distance : graph[u][v];
            }
            graph[u][v] = distance;
            graph[v][u] = distance;
        }
        read >> starting_position;

        dijkstra(graph, starting_position, n);
        cout << endl;
    }


    system("pause");
    return 0;
}
