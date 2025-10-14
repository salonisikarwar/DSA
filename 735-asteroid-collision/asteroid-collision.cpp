class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];

            if (curr > 0) {
                st.push_back(curr);
            } else {
                while (!st.empty() && st.back() > 0 && st.back() < abs(curr)) {
                    st.pop_back(); // destroy smaller positive asteroid
                }

                if (!st.empty() && st.back() == abs(curr)) {
                    st.pop_back(); // both explode
                } else if (st.empty() || st.back() < 0) {
                    st.push_back(curr); // survives or stack only had left-moving
                }
                // If the top of the stack is a larger asteroid, the current one gets destroyed (do nothing)
            }
        }

        return vector<int>(st.begin(), st.end()); // convert list to vector
    }
};