class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; // to simulate collisions

        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];

            // Case 1: Moving right → safe for now, just push
            if (curr > 0) {
                st.push(curr);
            } 
            // Case 2: Moving left → possible collisions
            else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(curr)) {
                    // Current asteroid destroys smaller right-moving asteroid
                    st.pop();
                }

                // If both are equal → both destroy each other
                if (!st.empty() && st.top() == abs(curr)) {
                    st.pop(); // both destroyed
                }
                // If stack empty or top is also moving left → push current
                else if (st.empty() || st.top() < 0) {
                    st.push(curr);
                }
                // If top > abs(curr), current asteroid gets destroyed → do nothing
            }
        }

        // Convert stack to vector (in correct order)
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
