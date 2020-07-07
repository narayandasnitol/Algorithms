#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

vector <int> adj[MAX];
int pre[MAX], dist[MAX], cost[MAX][MAX];


struct compare
{
   bool operator()(const int& low, const int& high){
       return low > high;
   }
 };

priority_queue<int, vector<int>, compare> pq;



int main()
{
    //freopen("input.txt", "r", stdin);

    int node, edges, source, destination;

    cin>> node >> edges;

    for(int i=1; i<=edges; i++){
        int x, y, w;

        cin >> x >> y >> w;

        adj[x].push_back(y);
       // adj[y].push_back(x);
        cost[x][y] = w;
    }



    cin >> source >> destination;

    for(int i=0; i<=node; i++){
        dist[i] = 9999;
    }


    pq.push(source);
    dist[source] = 0;


    while(!pq.empty()){
        int u = pq.top();
        pq.pop();

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];

            if(dist[u] + cost[u][v] < dist[v]){
                dist[v] = dist[u] + cost[u][v];

                pre[v] = u;
                pq.push(v);
            }
        }


    }

        cout << endl<< "total cost " << "["<<source <<"]"<< " - [" << destination << "] = "<< dist[destination] << endl<<endl;
        vector<int> path;

        path.push_back(destination);

        int now = destination;
        while(now != source){
            now = pre[now];

            if(now==pre[now]){
                break;
            }



            path.push_back(now);
        }

        reverse(path.begin(), path.end());
        cout << "shortest path " << "["<<source <<"]"<< " - [" << destination << "] = ";
        for (int i=0; i<path.size(); i++){
            cout << path[i]<< " ";
        }

    cout << endl << endl;

    fclose(stdin);

    return 0;
}

/*
5 6
1 2 1
1 3 10
2 4 2
2 3 5
3 5 6
4 3 2
1 5
*/
