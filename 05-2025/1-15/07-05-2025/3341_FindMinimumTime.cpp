/*
Problem:https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/?envType=daily-question&envId=2025-05-07
*/
/*
Author: Minikie - Phan NT Son
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
class Solution
{
public:
    /*
    Explain Solution:
        We use Dijkstra's algorithm to solve this problem.

        Inside we use Priority Queue to pop out the smallest first.

        After we pop out a Node from the queue, if that Node was 
        visited then skip.
        
        If current Node's neighboor is a Node that has been visited,
        we also skip it.

        Each time we move to next node, time will pass 1 sec. 
        Therefore, the weight will be: max(current Weight, neighboor's Weight) + 1
        
        We return the result when the Node popped out the queue is the
        bottom-right Node of the matrix.
    */
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int m = moveTime.size(), n = moveTime[0].size();
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            auto [w, pos] = pq.top();
            auto [i, j] = pos;
            pq.pop();

            if (visited[i][j])
                continue;
            visited[i][j] = true;

            if (i == m - 1 && j == n - 1)
                return w;

            for (int d = 0; d < 4; d++)
            {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny])
                {
                    int newCost = max(w, moveTime[nx][ny]) + 1;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }

        return -1;
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int n, m;
        cout << "Rows: ";
        cin >> n;
        cout << "Cols: ";
        cin >> m;
        vector<vector<int>> moveTime(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << "[" << i << "][" << j << "]: ";
                cin >> moveTime[i][j];
            }
        }

        cout << "Answer: " << s.minTimeToReach(moveTime) << "\n";

        char x;
        cout << "Continue ? Y/N:";
        cin >> x;
        if (x == 'n' || x == 'N')
        {
            break;
        }
    }
    return 0;
}