#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> result(queries.size(), -1);
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < queries.size(); ++i) {
            sortedQueries.emplace_back(queries[i], i);
        }

        sort(sortedQueries.begin(), sortedQueries.end());
        sort(intervals.begin(), intervals.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int i = 0;

        for (auto [q, idx] : sortedQueries) {
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0], r = intervals[i][1];
                pq.emplace(r - l + 1, r);
                ++i;
            }

            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }

            if (!pq.empty()) {
                result[idx] = pq.top().first;
            }
        }

        return result;
    }
};