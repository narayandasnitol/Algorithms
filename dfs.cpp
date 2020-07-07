#include <bits/stdc++.h>
using namespace std;

vector<int> mat[100];

int color[100];
int edge, vertex, x, y, v;


void DFS_VISIT(int u)
{
    color[u] = 1;
    cout << "visited " << u << " for the first time..."<<endl;

    for(int i=0; i<mat[u].size(); i++){
        v = mat[u][i];
        if(color[v] == 0){
            DFS_VISIT(v);
        }
    }

    color[u] =1;
    cout << "visited " << u << "for the second time..."<<endl;
}


void DFS(int v)
{
    for(int i=1; i<=v; ++i){
        if(color[i] == 0){
            DFS_VISIT(i);
        }
    }
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

    DFS(vertex);

    fclose(stdin);
    return 0;

}

