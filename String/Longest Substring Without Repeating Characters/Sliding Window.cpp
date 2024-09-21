class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>freq;
        int i = 0, j = 0, len = 0;
        
        while(j < s.size()) {
            freq[s[j]]++;
            if(freq.size() == (j-i+1)) {
                len = max(len, (j-i+1));
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
        return len;
    }
};

