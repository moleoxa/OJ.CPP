#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // start from here

    int n;
    cin >> n;
    int arr[n], temp[n];
    for (auto&& i : arr) {
        cin >> i;
    }

    for (int step = 1;step < n;step *= 2) {
        for (int start = 0; start < n; start += (2 * step)) {
            int p1 = start, p2 = start + step;
            if (p2 >= n) {
                break;
            }
            int q1 = p2, q2 = min(p2 + step, n);
            int cur = p1;
            while (p1 < q1 && p2 < q2) {
                temp[cur++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
            }
            while (p1 < q1) {
                temp[cur++] = arr[p1++];
            }
            while (p2 < q2) {
                temp[cur++] = arr[p2++];
            }
            for (int j = start; j < q2; j++) {
                arr[j] = temp[j];
            }
        }
    }

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