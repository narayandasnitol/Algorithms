#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

vector<int> adj[MAX];
int cost[MAX][MAX], dist[MAX], pre[MAX], c[MAX][MAX];


int main()
{
    freopen("graph.txt", "r", stdin);

    int edges, nodes, source, destination, N, now, flag = 0, f=0;
    vector<int> path;

    //cout << "Enter total node and edge: ";
    cin >> nodes >> edges;

    //cout << "Enter adjacent list: "<<endl;
    for(int i=1; i<=edges; i++){
        int x, y, w;

        cin >> x >> y >> w;

        adj[x].push_back(y);
        cost[x][y] = w;
    }

    //cout << "Source: ";
    cin >> source;
    //cout << "Destination: ";
    //cin >> destination;

    for(int i=0; i<=nodes; i++){
        dist[i] = 9999;
    }

    dist[source] = 0;

    for(int i=1; i<=nodes-1; i++){
        for(int j=1; j<=edges; j++){

            for(int k=0; k<adj[j].size(); k++){
                int u = j, v = adj[j][k];

                if(dist[u]+cost[u][v]<dist[v]){
                    dist[v] = dist[u]+cost[u][v];

                    pre[v]= u;
                }
            }
        }
    }


    for(int j=1; j<=edges; j++){
            for(int k=0; k<adj[j].size(); k++){

                int u = j, v = adj[j][k];

                if(dist[u]+cost[u][v]<dist[v]){
                    cout << endl<< "Graph Has Negative Cycle !!!"<<endl;
                    flag = 1;
                    break;
                }


                else{
                    cout<<"Total Cost from Node "<<source<<":"<<endl<<endl;
                    for(int y=1; y<=nodes; y++){
                        if(dist[y] == 9999)
                            cout << source <<" - "<<y << "-> "<< "infinity"<<endl;
                        else
                            cout << source <<" - "<<y << "-> "<< dist[y]<<endl;
                    }

                    cout << endl<<endl<<endl;
                    cout<<"Shortest Path from Node"<<source<<" :"<<endl;

                    for(int x=1; x<=nodes; x++){
                        destination= x;

                        cout << endl<< "Path from ( " << source << " -> "<<destination<<" )"<<endl;

                        path.push_back(destination);

                        now = destination;
                        while(now != source){
                            c[pre[now]][now] = cost[pre[now]][now];

                            now = pre[now];
                            if(now == pre[now]){
                                flag = 1;
                                break;
                            }

                         path.push_back(now);

                        }

                        if(dist[destination] == 9999)
                            cout<< "shortest path = infinity";


                        if(flag == 0){
                            reverse(path.begin(), path.end());

                            for(int i=1; i<=edges; i++){
                                for(int j=1; j<=edges; j++){
                                    if(c[i][j] != 0){
                                        cout << i <<" -> "<< j << " = "<<c[i][j]<<endl;
                                        c[i][j] = 0;
                                    }
                                }
                            }

                            cout<< "shortest path: ";
                            for(int i=0; i<path.size(); i++){
                                cout << path[i] << " ";
                            }

                        }
                        cout << endl<<endl;
                        flag = 0;
                        path.clear();

                    }

                }
                break;

            }

            break;
        }




    fclose(stdin);

    return 0;
}
