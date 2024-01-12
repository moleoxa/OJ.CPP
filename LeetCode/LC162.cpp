#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int findP(vector<int>& nums, int l, int r) {
        if (r - l > 1) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
                return m;
            }
            if (nums[m] < nums[m - 1]) {
                return findP(nums, l, m);
            }
            if (nums[m] < nums[m + 1]) {
                return findP(nums, m, r);
            }
        }
        return -1;
    }

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }
        return findP(nums, 0, n - 1);
    }
};