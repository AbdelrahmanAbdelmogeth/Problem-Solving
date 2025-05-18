class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int tasks_freqs_map[26] = {0};
        for (char task : tasks)
            tasks_freqs_map[task - 'A']++;

        priority_queue<int> max_heap;
        for (int task_freq : tasks_freqs_map)
            if (task_freq > 0)
                max_heap.push(task_freq);

        int time = 0;
        int cycle = n + 1;
        queue<int> q; 

        while (!max_heap.empty()) {
            // process one cycle of tasks
            for (int i = 0; i < cycle; i++) {
                if (!max_heap.empty()) {
                    int task_count = max_heap.top();
                    max_heap.pop();

                    if (task_count - 1 > 0)
                        q.push(task_count - 1);  // push the decremented count
                }

                time++;

                // if both queues are empty, break early because nothing to do
                if (max_heap.empty() && q.empty())
                    break;
            }

            // push all remaining tasks back into the heap
            while (!q.empty()) {
                max_heap.push(q.front());
                q.pop();
            }
        }

        return time;
    }
};
