#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int n, arr[100], k, t;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    cout << "Before sort: ";
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }


  /*** Algorithm starts here ***/

    k = n;
    while( k !=0 ){

        t=0;
        for(int j=1; j<=k; j++){

            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                t = j;
            }
        }
        k = t;
    }

    /*** Algorithm ends here ***/

    cout<<endl<< "After sort: ";
    for(int i=1; i<=n; i++){
        cout << arr[i]<< " ";
    }
    cout << endl<<endl;


    fclose(stdin);

    return 0;
}
