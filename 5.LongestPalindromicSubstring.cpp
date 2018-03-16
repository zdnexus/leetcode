//
// Created by zdnexus on 2017/1/9 0009.
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
            while (left >= 0 && right < s.length()) {
                if (s[left] == s[right]) {
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
            left = i - 1;
            right = i + 1;
            while (left >= 0 && right < s.length()) {
                if (s[left] == s[right]) {
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

    cout << s.longestPalindrome("abcd") << endl;
    cout << s.longestPalindrome("abcb") << endl;
    cout << s.longestPalindrome("aaaa") << endl;
    cout << s.longestPalindrome("aaa") << endl;
    cout << s.longestPalindrome("cbbd") << endl;

    return 0;
}