int dp[1001][1001];

int max(int a, int b) {
    return (a > b ? a : b);
}

int getlen(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char* revstr(char* text1) {
    int len = getlen(text1);
    char* text2 = (char*)malloc(sizeof(char) * (len + 1));
    text2[len] = '\0';
    for (int i = 0; i < len; i++) {
        text2[i] = text1[len - i - 1];
    }
    printf("REV = %s\n", text2);
    return text2;
}

int getans(char* text1, char* text2, int cur1, int cur2) {
    if (dp[cur1][cur2] != -1) {
        return dp[cur1][cur2];
    }
    if (cur1 == 0 || cur2 == 0) {
        return dp[cur1][cur2] = 0;
    }
    if (text1[cur1 - 1] == text2[cur2 - 1]) {
        return dp[cur1][cur2] = 1 + getans(text1, text2, cur1 - 1, cur2 - 1);
    }
    return dp[cur1][cur2] = max(getans(text1, text2, cur1 - 1, cur2), getans(text1, text2, cur1, cur2 - 1));
}

int longestCommonSubsequence(char* text1, char* text2) {
    int len1 = getlen(text1);
    int len2 = getlen(text2);
    for (int i = 0; i < len1 + 1; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            dp[i][j] = -1;
        }
    }
    return getans(text1, text2, len1, len2);
}

int longestPalindromeSubseq(char* s) {
    char* text2 = revstr(s);
    return longestCommonSubsequence(s, text2);
}