//
// Created by 钟东 on 2017/1/5 0005.
//
#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(128, -1);//每个字符最后一次的位置，默认为-1
        int firstPos = 0;//初始位置
        int maxLen = 0;//最长长度
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (dict[ch] >= firstPos) {
                firstPos = dict[ch] + 1;
            }
            dict[ch] = i;
            maxLen = max(maxLen, i - firstPos + 1);
        }
        return maxLen;
    }
};

int main() {
    Solution s;

    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
}