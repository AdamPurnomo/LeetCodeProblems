class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        /*
        The idea is the same as rotting oranges. We process the 0 and do BFS while incrementing distances of non 0 cells
        */
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        int dist = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                    q.push(make_pair(i, j));
                else if (mat[i][j] == 1)
                    mat[i][j] = -1; //unprocessed cells
            }

        while (!q.empty())
        {
            int length = q.size();
            for (int i = 0; i < length; i++)
            {
                //process
                pair<int, int> id = q.front();
                q.pop();
                mat[id.first][id.second] = dist;

                //push the neighboring
                for (int j = 0; j < 4; j++)
                {
                    int r = id.first + dx[j];
                    int c = id.second + dy[j];
                    if (r >= 0 && r < m && c >= 0 && c < n && mat[r][c] == -1)
                    {
                        q.push(make_pair(r, c));
                        mat[r][c] = -2; //about to get processed so that no duplicate of unprocessed due to same neighbor
                    }
                }
            }
            dist++;
        }
        return mat;
    }
};