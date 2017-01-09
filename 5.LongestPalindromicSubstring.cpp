//
// Created by Administrator on 2017/1/9 0009.
//
#include<iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        bool palindrome = false;
        int subStar = 0;
        int subLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            int left = i - 1;
            int right = i;
            while (left >= 0 && right <= s.length() - 1) {
                if (s[left] == s[right]) {
                    palindrome = true;
                    if (right - left + 1 > subLen) {
                        subLen = right - left + 1;
                        subStar = left;
//                        cout << subStar << " & " << subLen << endl;
                    }
                }
                if (right + 1 <= s.length() - 1 && s[left] == s[right + 1]) {
                    palindrome = true;
                    if (right - left + 1 > subLen) {
                        subLen = right - left + 1;
                        subStar = left;
//                        cout << subStar << " & " << subLen << endl;
                    }
                }
                --left;
                ++right;
            }
        }
        if (palindrome) {
            return s.substr(subStar, subLen);
        } else {
            return s.substr(0, 1);
        }
    }
};

int main() {
    Solution s;

    cout << s.longestPalindrome("abcb") << endl;
    cout << s.longestPalindrome("aaaa") << endl;
    cout << s.longestPalindrome("aaa") << endl;
    cout << s.longestPalindrome("cbbd") << endl;

    return 0;
}