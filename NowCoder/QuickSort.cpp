#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void swap(int* arr, int a, int b) {
    if (a != b) {
        int c = arr[a];
        arr[a] = arr[b];
        arr[b] = c;
    }
    return;
}

void QuickSort(int* arr, int l, int r) {
    if (r > l) {
        int x = arr[rand() % (r - l + 1) + l];
        int le = l - 1, mo = r + 1;
        for (int i = l; i < mo; i++) {
            if (arr[i] < x) {
                swap(arr, i, ++le);
            } else if (arr[i] > x) {
                swap(arr, i--, --mo);
            }
        }
        QuickSort(arr, l, le);
        QuickSort(arr, mo, r);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // start from here

    int n;
    cin >> n;
    int arr[n];
    for (auto&& i : arr) {
        cin >> i;
    }

    QuickSort(arr, 0, n - 1);

    bool b = true;
    for (auto&& i : arr) {
        if (b) {
            b = false;
        } else {
            cout << " ";
        }
        cout << i;
    }

    return 0;
}