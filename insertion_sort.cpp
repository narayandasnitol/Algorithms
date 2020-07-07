#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int n, arr[1000], k, t, x, i, j;
    cin >> n;

    for(i=1; i<=n; i++){
        cin >> arr[i];
    }

    cout << "Before sort: ";
    for(i=1; i<=n; i++){
        cout << arr[i] << " ";
    }


   /*** Algorithm starts here ***/

    arr[0] = -9999;
    for(j=2; j<= n; j++){
        k = j-1;
        t = arr[j];

        while(t < arr[k]){
            arr[k+1] = arr[k];
            k = k-1;
        }
        arr[k+1] = t;
   }


    /*** Algorithm ends here ***/


    cout<<endl<< "After sort: ";
    for(i=1; i<=n; i++){
        cout << arr[i]<< " ";
    }
    cout << endl<<endl;


    fclose(stdin);

    return 0;
}

