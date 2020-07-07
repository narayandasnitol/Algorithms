#include <bits/stdc++.h>
using namespace std;

vector<int> mat[100], path;
queue <int> q;

int level[100], visited[100], previous[100];
int edge, vertex, x, y, source, destination, u, v;

void BFS(int source, int destination)
{
    q.push(source);
    level[source] = 0;
    visited[source] = 1;
    previous[source] = source;

    while(!q.empty()){

        u = q.front();
        q.pop();

        for(int i=0; i<mat[u].size(); i++){
            v = mat[u][i];

            if(level[v] == 0){
                level[v] = level[u] + 1;

                visited[v] = 1;
                previous[v] = u;

                q.push(v);
            }
        }
    }

    cout << "Level = "<< level[destination];


    path.push_back(destination);

    int now = destination;
    while(now != source){
        now = previous[now];
        path.push_back(now);
    }

    reverse(path.begin(), path.end());

    cout << endl<< "Shortest path: ";
    for(int i=0; i<path.size(); i++){
        cout << path[i]<< " ";
    }

    cout << endl;

}

int main()
{
    freopen("graph.txt", "r", stdin);

    cin >> vertex >> edge;

    for(int i=0; i<edge; i++){
        cin >> x >> y;

        mat[x].push_back(y);
        mat[y].push_back(x);
    }
    cin>> source;
    cin>> destination;

    BFS(source, destination);



    fclose(stdin);
    return 0;

}
