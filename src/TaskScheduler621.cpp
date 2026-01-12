class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskTimes;

        for (char task : tasks) {
            taskTimes[task]++;
        }

        priority_queue<int> pq;
        for (const auto& [task, time] : taskTimes) {
            pq.push(time);
        }

        queue<pair<int,int>> waitingList;
        int time = 0;
        while (!pq.empty() || !waitingList.empty()) {
            time++;
            while (!waitingList.empty() && time - waitingList.front().first > n) {
                int timeLeft = waitingList.front().second;
                waitingList.pop();
                pq.push(timeLeft);
            }

            if (!pq.empty()) {
                int top = pq.top();
                pq.pop();
                top--;
                if (top > 0) {
                    waitingList.push({ time, top });
                }
            }
        }

        return time;
    }
};