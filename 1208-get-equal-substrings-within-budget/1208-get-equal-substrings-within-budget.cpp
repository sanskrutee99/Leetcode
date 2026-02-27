class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> diff(n, 0);
        diff[0] = abs(s[0] - t[0]);
        for (int i = 1; i < n; i++) {
            diff[i] = diff[i - 1] + abs(s[i] - t[i]);
        }
        int ans = 0;
        int l = 0;
        int h = n;
        while (l < h) {
            int m = (l + h) / 2;
            if (diff[m] > maxCost)
                h = m;
            else {
                ans = max(ans, m+ 1);
                l = m + 1;
            }
        }
        for (int i = 1; i < n; i++) {
            int l = i;
            int h = n;
            while (l < h) {
                int m = (l + h) / 2;
                if (diff[m] - diff[i - 1] > maxCost)
                    h = m;
                else {
                    ans = max(ans, m - i + 1);
                    l = m + 1;
                }
            }
        }
        return ans;
    }
};