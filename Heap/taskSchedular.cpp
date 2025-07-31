//https://leetcode.com/problems/task-scheduler/

// mathematical solution


class Solution {
public:
    using ll = long long;

    int leastInterval(vector<char>& tasks, int m) {
        int n = tasks.size();
        map<char, int> freq; 
        ll maxi = 0;
        for(int i = 0; i < n; i++) {
            freq[tasks[i]]++;
            maxi = max(maxi, (ll)freq[tasks[i]]);
        }
        ll elehaveMax = 0;
        for(auto i : freq) {
            if(i.second == maxi) elehaveMax++;
        }
        ll ans = max((ll)n, (maxi - 1) * (m + 1) + elehaveMax);

        return ans;
    }
};



// priority queue solution -- simulate the process 
// Count the frequency of each task.

// Push all frequencies into a max heap (in C++, use priority_queue<int>).

// Simulate time units:

//     At every unit of time:

//         Pick the task with the highest frequency (from heap).

//         Decrease its frequency and push it to a temporary cooldown queue (with time when it becomes available again).

//     After every time unit, check if any task in cooldown becomes available (i.e., cooldown expired), and push it back to heap.

// Continue until all tasks are processed and heap + cooldown queue are both empty.


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for (char ch : tasks) {
            freq[ch]++;
        }

        // Max heap (stores frequencies)
        priority_queue<int> pq;
        for (auto [ch, f] : freq) {
            pq.push(f);
        }

        int time = 0;

        // cooldown queue: pair<time_ready, frequency>
        queue<pair<int, int>> cooldown;

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            // Release from cooldown if ready
            if (!cooldown.empty() && cooldown.front().first == time) {
                pq.push(cooldown.front().second);
                cooldown.pop();
            }

            if (!pq.empty()) {
                int curr = pq.top();
                pq.pop();

                if (curr > 1) {
                    // cooldown period is time + n
                    cooldown.push({time + n + 1, curr - 1});
                }
            }
        }

        return time;
    }
};
