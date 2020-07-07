#include <bits/stdc++.h>
using namespace std;

 int n, arr[1000], k, t, x, i, j;

void quick_sort(int f, int l)
{
    if(f<l){

        i = f+1;
        while(arr[i]<arr[f]){
            i++;
        }

        j = l;
        while(arr[j]>arr[f]){
            j--;
        }

        while(i < j){
            swap(arr[i], arr[j]);

            while(arr[i]<=arr[f]){
                i++;
            }
            while(arr[j]>=arr[f]){
                j--;
            }

        }

        swap(arr[f], arr[j]);

        quick_sort(f, j-1);
        quick_sort(j+1, l);
    }
}



int main()
{
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


    quick_sort(1, n);


    /*** Algorithm ends here ***/



    cout<<endl<< "After sort: ";
    for(i=1; i<=n; i++){
        cout << arr[i]<< " ";
    }
    cout << endl<<endl;


    fclose(stdin);

    return 0;
}



