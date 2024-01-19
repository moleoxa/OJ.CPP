#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int* temp;

    int reverse(vector<int>& nums, int l, int m, int r) {
        int p1, p2;
        int ans = 0;
        for (p1 = l, p2 = m + 1; p2 <= r; p2++) {
            while (p1 <= m && nums[p1] <= (long long)2 * nums[p2]) {
                p1++;
            }
            ans += (m - p1 + 1);
        }
        int cur = l;
        for (p1 = l, p2 = m + 1; p1 <= m && p2 <= r; cur++) {
            temp[cur] = nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++];
        }
        while (p1 <= m) {
            temp[cur++] = nums[p1++];
        }
        while (p2 <= r) {
            temp[cur++] = nums[p2++];
        }
        for (int i = l; i <= r; i++) {
            nums[i] = temp[i];
        }
        return ans;
    }

    int reversePairs(vector<int>& nums, int l = 0, int r = -1) {
        if (r == -1) {
            r = nums.size();
            temp = new int[r--];
        }
        int ans = 0;
        if (r > l) {
            int m = (l + r) / 2;
            ans = reversePairs(nums, l, m) + reversePairs(nums, m + 1, r) + reverse(nums, l, m, r);
        }
        return ans;
    }
};