#include<bits/stdc++.h>
using namespace std;

int a, b, u, v, n, i, j, serial=1;

int visited[10]={0}, mini=999, mincost=0, cost[10][10];

int main()

{

	cout << "\nEnter the number of nodes:";
	cin >> n;

	cout << "\nEnter the adjacency matrix:\n";

	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            cin >> cost[i][j];

            if(cost[i][j]==0)
                cost[i][j]=999;
        }


	visited[1]=1;

	cout << endl;

	while(serial < n){

		for(i=1, mini=999;i<=n; i++){
            for(j=1; j<=n; j++){
                if(cost[i][j]< mini){
                    if(visited[i]!=0){

                        mini=cost[i][j];

                        a = u =i;
                        b = v =j;
                    }
                }
            }
		}

		if(visited[u]==0 || visited[v]==0){
			cout<< endl<< "edge " << serial++ <<" : "<< a << "-"<< b << "  cost: "<< mini << endl;

			mincost+=mini;

			visited[b]=1;
		}

		cost[a][b]=cost[b][a]=999;

	}

	cout << "\n \nMinimum cost = " << mincost<<endl;

	return 0;

}

/*
4
0 2 3 0
0 0 4 6
0 0 0 8
0 0 0 0

weight = 11 */
