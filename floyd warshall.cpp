#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

int  adj[MAX][MAX], next[MAX][MAX];
vector<int> path;

void FindPath(int i, int j)
{
    path.push_back(i);

    while(i != j){
        i = next[i][j];
        path.push_back(i);
    }

    return ;
}


int main()
{
    freopen("input.txt", "r", stdin);

    int node, edge;

    //cout << "Enter Node and Edge: ";
    cin>> node >> edge;

   // cout << "Enter the matrix: "<<endl;
    for(int i=1; i<=node; i++){
        for(int j=1; j<=node; j++){
            cin >> adj[i][j];

            next[i][j] = j;
        }
    }


    for(int k=1; k<=node; k++){
        for(int i=1; i<=node; i++){
            for(int j=1; j<=node; j++){
                if(adj[i][k]+adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];

                    next[i][j] = next[i][k];

                }
            }
        }
    }


    for(int i=1; i<=node; i++){
        cout <<endl<< "cost from node ( "<<i<<" )"<<endl;

        for(int j=1; j<=node; j++){
                if(adj[i][j] == 999)
                    cout << i << " -> " << j << " = "<< "infinity"<<endl;
                else
                    cout << i << " -> " << j << " = "<< adj[i][j]<<endl;
        }
    }


    cout << endl << endl<< "Shortest Path for all nodes: "<<endl<<endl;

    for(int i=1; i<=node; i++){
        for(int j=1; j<=node; j++){
            if(i != j){
                FindPath(i,j);

                if(adj[i][j] == 999){
                    cout << "path for "<<i << " - "<<j<<" : no path"<<endl;
                }
                else{
                    cout << "path for "<<i << " - "<<j<<" : ";
                    for(int k=0; k<path.size(); k++){
                        cout << path[k]<<" ";
                    }
                    cout<<endl;

                }
                path.clear();
            }
        }
        cout << endl;
    }







    fclose(stdin);


    return 0;
}
