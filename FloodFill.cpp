class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        int basis = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        bool visited[m][n];

        //initialize visited
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                visited[i][j] = false;

        while (!q.empty())
        {
            //process the current cell
            pair<int, int> cur = q.front();
            if (image[cur.first][cur.second] == basis)
                image[cur.first][cur.second] = newColor;
            visited[cur.first][cur.second] = true;
            q.pop();

            //push to dummy vector for validity check
            vector<pair<int, int>> dummy;
            dummy.push_back(make_pair(cur.first - 1, cur.second));
            dummy.push_back(make_pair(cur.first + 1, cur.second));
            dummy.push_back(make_pair(cur.first, cur.second - 1));
            dummy.push_back(make_pair(cur.first, cur.second + 1));

            for (pair<int, int> p : dummy)
                if (inrange(p, m, n) && image[p.first][p.second] == basis && visited[p.first][p.second] == false)
                    q.push(p);
        }

        return image;
    }

    bool inrange(pair<int, int> p, int m, int n)
    {
        return (p.first >= 0 && p.first < m && p.second >= 0 && p.second < n);
    }
};