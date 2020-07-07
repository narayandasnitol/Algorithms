#include <bits/stdc++.h>
using namespace std;


struct edge{
  int x, y, w;

};

int parent[10000];
vector<edge> e, mst;


bool cmp ( edge a , edge b  )
{
    return a.w < b.w ;
}


int FindRepresentative(int r)
{
    if(parent[r] == r){
        return r;
    }


    parent[r] = FindRepresentative(parent[r]);
    return parent[r];
}


void kruskalMST(int n)
{
    sort(e.begin(), e.end(), cmp);

    for(int i=1; i<=n; i++){
        parent[i]= i;
    }

    for(int i =0; i< e.size(); i++){

        int u = FindRepresentative(e[i].x);
        int v = FindRepresentative(e[i].y);

        if(u != v){
            parent[u] = v;

            mst.push_back(e[i]);
        }

    }

    cout << endl << endl << "Spanning Tree: "<<endl;

    int sum = 0;
    for(int i=0; i< mst.size(); i++){
        cout << mst[i].x << ' ' << mst[i].y << ' ' << mst[i].w << endl;

        sum += mst[i].w;
    }

    cout << endl<< "Weight: " << sum<<endl;

}


int main()
{
    //freopen("input.txt", "r", stdin);

    int edges, vertices;

    cout << "Enter total vertices and edges: ";
    cin >> vertices >> edges;

    cout << " Enter u , v , w: ";
    for(int i=1; i<=edges; i++){
        int u, v, w;

        cin >> u >> v >> w;

        edge get;

        get.x = u;
        get.y = v;
        get.w = w;
        e.push_back(get);
    }


    kruskalMST(vertices);


   // fclose(stdin);

    return 0;
}

/* 5 7
1 2 7
1 3 4
1 4 1
2 4 8
2 5 6
3 4 3
4 5 6

1 4 1
3 4 3
2 5 6
4 5 6

Weight: 16*/

