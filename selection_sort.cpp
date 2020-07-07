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

    for(j=n; j>=2; j--){
        t = 1;
        for(k=2; k<=j; k++){
            if(arr[t] < arr[k]){
                t = k;
            }
        }
        swap(arr[j], arr[t]);
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


