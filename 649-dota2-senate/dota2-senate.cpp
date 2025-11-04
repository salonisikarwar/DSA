#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rQueue, dQueue;
        int n = senate.size();

        // Step 1: Fill both queues with indices
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                rQueue.push(i);
            else
                dQueue.push(i);
        }

        // Step 2: Simulate rounds
        while (!rQueue.empty() && !dQueue.empty()) {
            int r = rQueue.front(); rQueue.pop();
            int d = dQueue.front(); dQueue.pop();

            // Smaller index senator bans the other
            if (r < d)
                rQueue.push(r + n); // Radiant acts first
            else
                dQueue.push(d + n); // Dire acts first
        }

        // Step 3: Determine winner
        return rQueue.empty() ? "Dire" : "Radiant";
    }
};
