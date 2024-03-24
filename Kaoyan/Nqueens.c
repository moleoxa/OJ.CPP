#include<stdio.h>
#include<math.h>

int cnt = 0;

void solve(int n, int* ans, int cur) {
    if (cur >= n) {
        cnt++;
    }
    for (int i = 0; i < n; i++) {
        int valid = 1;
        for (int j = 0; j < cur; j++) {
            if ((ans[j] == i) || (abs(ans[j] - i) == cur - j)) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            ans[cur] = i;
            solve(n, ans, cur + 1);
        }
    }
    return;
}

int main() {
    int n = 8;
    // scanf("%d", &n);
    int ans[9] = {};
    solve(n, ans, 0);
    printf("%d\n", cnt);
    return 0;
}