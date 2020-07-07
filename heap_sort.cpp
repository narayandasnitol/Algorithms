#include <bits/stdc++.h>
using namespace std;

int arr[10000];

void max_heapify(int i, int n)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i + 1;

    if(arr[l]>arr[i] && (l <= n)){
        largest = l;
    }
    else{
        largest = i;
    }
    if(arr[r]>arr[largest] && r<= n){
        largest = r;
    }

    if(i != largest){
        swap(arr[i], arr[largest]);
        max_heapify(largest, n);
    }
}

void build_max_heap(int n)
{
    for(int i=n/2; i>=1; i--){
        max_heapify(i, n);
    }
}

void heap_sort(int n)
{
    build_max_heap(n);

    for(int i=n; i>=2; i--){
        swap(arr[1], arr[n]);
        n--;
        max_heapify(1, n);
    }
}


int main()
{
    freopen("input.txt", "r", stdin);

    int k, n, t, x, i, j;
    cin >> n;

    for(i=1; i<=n; i++){
        cin >> arr[i];
    }

    cout << "Before sort: ";
    for(i=1; i<=n; i++){
        cout << arr[i] << " ";
    }


   /*** Algorithm starts here ***/

    heap_sort(n);


    /*** Algorithm ends here ***/



    cout<<endl<< "After sort: ";
    for(i=1; i<=n; i++){
        cout << arr[i]<< " ";
    }
    cout << endl<<endl;


    fclose(stdin);

    return 0;
}



