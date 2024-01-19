#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll Merge(int* arr, int* temp, int l, int m, int r) {
    ll ans = 0, cur = l;
    int p1 = l, p2 = m + 1;
    while (p1 <= m && p2 <= r) {
        if (arr[p1] <= arr[p2]) {
            ans += arr[p1] * (r - p2 + 1);
            temp[cur++] = arr[p1++];
        } else {
            temp[cur++] = arr[p2++];
        }
    }
    while (p1 <= m) {
        temp[cur++] = arr[p1++];
    }
    while (p2 <= r) {
        temp[cur++] = arr[p2++];
    }
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
    return ans;
}

ll SmallSum(int* arr, int* temp, int l, int r) {
    ll ans = 0;
    if (r > l) {
        int m = (l + r) / 2;
        ans = SmallSum(arr, temp, l, m) + SmallSum(arr, temp, m + 1, r) + Merge(arr, temp, l, m, r);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // start from here

    int n;
    cin >> n;
    int arr[n], temp[n];
    for (auto&& i : arr) {
        cin >> i;
    }
    cout << SmallSum(arr, temp, 0, n - 1);

    return 0;
}