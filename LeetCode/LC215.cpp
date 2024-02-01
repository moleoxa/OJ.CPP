#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    void swap(vector<int>& nums, int a, int b) {
        if (a != b) {
            int c = nums[a];
            nums[a] = nums[b];
            nums[b] = c;
        }
        return;
    }

    int findKthLargest(vector<int>& nums, int k) {
        k--;
        int l = 0, r = nums.size() - 1;
        int mo, x, le;
        while (true) {
            mo = l - 1, le = r + 1;
            x = nums[rand() % (r - l + 1) + l];
            for (int i = l; i < le; i++) {
                if (nums[i] > x) {
                    swap(nums, ++mo, i);
                } else if (nums[i] < x) {
                    swap(nums, i--, --le);
                }
            }
            if (k <= mo) {
                r = mo;
            } else if (k >= le) {
                l = le;
            } else {
                break;
            }
        }
        return nums[k];
    }
};