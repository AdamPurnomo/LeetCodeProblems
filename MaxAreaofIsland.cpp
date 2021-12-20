class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (grid[r][c] == 1)
                    res = max(res, DFSAreaofIsland(grid, r, c));
        return res;
    }

    int BFSAreaofIsland(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size(), area = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        grid[i][j] = 0;

        while (!q.empty())
        {
            //prcess the current front
            pair<int, int> cur = q.front();
            area++;
            q.pop();

            //push to queue if it satisfies conditions
            vector<pair<int, int>> dummy;
            dummy.push_back(make_pair(cur.first - 1, cur.second));
            dummy.push_back(make_pair(cur.first + 1, cur.second));
            dummy.push_back(make_pair(cur.first, cur.second - 1));
            dummy.push_back(make_pair(cur.first, cur.second + 1));

            for (pair<int, int> p : dummy)
                if (p.first >= 0 && p.first < m && p.second >= 0 && p.second < n && grid[p.first][p.second] == 1)
                {
                    q.push(p);
                    grid[p.first][p.second] = 0;
                }
        }
        return area;
    }

    int DFSAreaofIsland(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size(), area = 0;

        //process the current cell
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1)
        {
            grid[i][j] = 0;
            area = 1 + DFSAreaofIsland(grid, i - 1, j) + DFSAreaofIsland(grid, i + 1, j) + DFSAreaofIsland(grid, i, j - 1) + DFSAreaofIsland(grid, i, j + 1);
        }

        return area;
    }
};