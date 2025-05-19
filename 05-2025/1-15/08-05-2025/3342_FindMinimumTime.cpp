/*
Problem:https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/?envType=daily-question&envId=2025-05-08
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
    Explain #1 Solution:
        Same Idea as problem 3341 in 07-05-2025. We use Dijkstra.
        
        The different is we store 4 values: time, room, i, j
        room:   to count how many rooms we have passed

        If the number of room is 2 then the next room we enter
        we will have to increase time 2 and reset the coutner
        back to 0.
    */
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int rows, cols;
        rows = moveTime.size();
        cols = moveTime[0].size();

        // {time, {room've passed, {i, j}}}
        priority_queue<pair<int, pair<int, pair<int, int>>>,
                       vector<pair<int, pair<int, pair<int, int>>>>,
                       greater<pair<int, pair<int, pair<int, int>>>>>
            pq;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};

        pq.push({0, {1, {0, 0}}});
        int i, j, time, room, nx, ny, nTime, nRoom;
        while (!pq.empty())
        {
            time = pq.top().first;
            room = pq.top().second.first;
            i = pq.top().second.second.first;
            j = pq.top().second.second.second;

            pq.pop();
            if (visited[i][j])
            {
                continue;
            }
            visited[i][j] = true;

            if (i == (rows - 1) && j == (cols - 1))
            {
                break;
            }

            for (int d = 0; d < dx.size(); d++)
            {
                nx = i + dx[d];
                ny = j + dy[d];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols)
                {
                    int nextTime = moveTime[nx][ny];
                    nTime = max(time, nextTime);
                    nRoom = room;
                    if (room == 2)
                    {
                        nRoom = 0;
                        nTime += 2;
                    }
                    else
                    {
                        nTime++;
                    }
                    pq.push({nTime, {nRoom + 1, {nx, ny}}});
                }
            }
        }
        return time;
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