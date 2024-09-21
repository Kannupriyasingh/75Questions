class Solution {
      public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> freq = new HashMap<>();
        int i = 0, j = 0, len = 0;

        while (j < s.length()) {
            freq.put(s.charAt(j), freq.getOrDefault(s.charAt(j), 0) + 1);

            if (freq.size() == (j - i + 1)) {
                len = Math.max(len, j - i + 1);
            } else if (freq.size() < (j - i + 1)) {
                while (freq.size() != (j - i + 1)) {
                    freq.put(s.charAt(i), freq.get(s.charAt(i)) - 1);
                    if (freq.get(s.charAt(i)) == 0) {
                        freq.remove(s.charAt(i));
                    }
                    i++;
                }
                len = Math.max(len, j - i + 1);
            }
            j++;
        }

        return len;
    }
}
