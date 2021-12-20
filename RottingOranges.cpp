class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int minutes = -1, m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int sum_fresh = 0;

        int dir[5] = {-1, 0, 1, 0, -1}; //used for finding 4 adjacent coordinates

        //initialize
        find_rottenfresh(grid, q, sum_fresh);

        while (!q.empty())
        {
            int length = q.size();
            minutes++;

            for (int i = 0; i < length; i++)
            {
                //pop the front
                pair<int, int> f = q.front();
                q.pop();

                //push and process
                for (int j = 0; j < 4; j++)
                {
                    int r = f.first + dir[j];
                    int c = f.second + dir[j + 1];
                    if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
                    {
                        sum_fresh--;
                        grid[r][c] = 2;
                        q.push(make_pair(r, c));
                    }
                }
            }
        }
        if (sum_fresh > 0)
            return -1;
        else if (minutes == -1)
            return 0;
        else
            return minutes;
    }

    void find_rottenfresh(vector<vector<int>> &grid, queue<pair<int, int>> &q, int &fresh)
    {
        queue<pair<int, int>> rottenid;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
            }
    }
};