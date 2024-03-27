int lengthOfLIS(int* nums, int numsSize) {
    int pre[numsSize + 1];
    pre[0] = -10001;
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = ans;
        while (nums[i] <= pre[x]) {
            x--;
        }
        if (x == ans) {
            pre[++ans] = nums[i];
        } else if (pre[++x] > nums[i]) {
            pre[x] = nums[i];
        }
    }
    return ans;
}