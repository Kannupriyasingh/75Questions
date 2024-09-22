class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>freq;
        int i = 0, j = 0, len = 0;
        int startIndex = -1, endIndex = -1;
        while(j < s.size()) {
            freq[s[j]]++;
            if(freq.size() == (j-i+1)) {
                len = max(len, (j-i+1));
                // this change if we want to get the answer substring's start and end Index
                startIndex = i;
                endIndex = j;
            } 
            else if(freq.size() < (j-i+1)) {
                while(freq.size() != (j-i+1)) {
                    freq[s[i]]--;
                    if(freq[s[i]] == 0)
                        freq.erase(s[i]);
                    i++;
                }
                len = max(len, (j-i+1));
            }
            j++;
        }
        // here we can find that substring using its start and end Index
        string ls = s.substr(startIndex, (endIndex-startIndex+1));
        cout << ls;
        return len;
    }
};

// abcabcbb
// a - 1 (1)
// b - 1 (2)
// c - 1 (3)

