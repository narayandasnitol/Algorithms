#include <bits/stdc++.h>
using namespace std;


int arr[1000];

void mergeS(int p, int q, int r)
{
    int n1, n2, x, i, j;

    n1 = q-p+1;
    n2 = r-q;

    int L[n1+1], R[n2+1];

    for(i=1; i<=n1; i++){
        L[i]= arr[p+i-1];
    }

    for(j=1; j<=n2; j++){
        R[j] = arr[q+j];
    }

    L[n1+1] = INT_MAX;
    R[n2+1] = INT_MAX;

    i=1, j=1;

    for(x=p; x<=r; x++){
        if(L[i]<=R[j]){
            arr[x] = L[i];
            i++;
        }
        else{
            arr[x] = R[j];
            j++;
        }
    }

}

void merge_sort(int p, int r)
{
    int q;

    if(p<r){
        q = (p+r)/2;

        merge_sort(p, q);
        merge_sort(q+1, r);
        mergeS(p, q, r);
    }
}



int main()
{
    int i, j, k, n;

    freopen("input.txt", "r", stdin);


    cin >> n;

    for(i=1; i<=n; i++){
        cin >> arr[i];
    }

    cout << "Before sort: ";
    for(i=1; i<=n; i++){
        cout << arr[i] << " ";
    }


   /*** Algorithm starts here ***/

    merge_sort(1, n);

    /*** Algorithm ends here ***/



    cout<<endl<< "After sort: ";
    for(i=1; i<=n; i++){
        cout << arr[i]<< " ";
    }
    cout << endl<<endl;


    fclose(stdin);

    return 0;
}



