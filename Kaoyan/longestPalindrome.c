#include<stdio.h>
#include<stdlib.h>

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
    return text2;
}

int longestCommonSubstr(char* text1, char* text2) {
    int len1 = getlen(text1);
    int len2 = getlen(text2);
    for (int i = 0; i < len1 + 1; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return 0;
}

char* longestPalindrome(char* s) {
    char* text2 = revstr(s);
    longestCommonSubstr(s, text2);
    int len = getlen(s);
    int sp, ans = 0;
    for (int i = 0; i < len + 1; i++) {
        for (int j = 0; j < len + 1; j++) {
            if (dp[i][j] > ans && i + j - dp[i][j] == len) {
                ans = dp[i][j];
                sp = i - ans;
            }
        }
    }
    char* pal = (char*)malloc(sizeof(char) * (ans + 1));
    pal[ans] = '\0';
    for (int i = 0;i < ans;i++) {
        pal[i] = s[sp + i];
    }
    return pal;
}

// int main() {
//     char* s = "aacabdkacaa";
//     printf("%s", longestPalindrome(s));
//     return 0;
// }