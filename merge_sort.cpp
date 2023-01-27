#include <iostream>
using namespace std;

const int N = 1005;
int arr[N];

void merge(int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(l, m);
        merge_sort(m + 1, r);

        merge(l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    merge_sort(0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
This program first defines a merge function, which merges two sorted subarrays arr[l..m] and arr[m+1..r] into one sorted array. The merge function is called by the merge_sort function, which recursively divides the array into smaller subarrays and sorts them by calling the merge function. The base case of the recursion is when the subarray has only one element, which is already considered sorted. The main function takes input the number of elements in the array and the array itself. It


3