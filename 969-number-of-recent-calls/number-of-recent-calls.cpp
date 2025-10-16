#include <queue>
using namespace std;

class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);
        
        // Remove requests older than (t - 3000)
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        // Remaining size is the count of valid requests
        return q.size();
    }
};
