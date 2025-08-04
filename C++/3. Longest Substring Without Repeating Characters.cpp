#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> pos; 
        int maxLen = 0;
        int l = 0;

        for (int r = 0; r < s.length(); ++r) {
            char ch = s[r];

            if (pos.find(ch) != pos.end() && pos[ch] >= l) {
                l = pos[ch] + 1;
            }

            pos[ch] = r;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
