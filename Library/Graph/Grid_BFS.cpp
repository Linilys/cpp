// https://github.com/Linilys/cpp
class GridBFS {
private:
    vector<vector<int>> grid; // グリッド
    int rows, cols; // グリッドの行数と列数

    const vector<pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1} // 下、右、上、左
    };

public:
    GridBFS(const vector<vector<int>>& grid) : grid(grid) {
        rows = grid.size();
        cols = grid[0].size();
    }

    vector<vector<int>> bfs(pair<int, int> start) {
        vector<vector<int>> distance(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;

        q.push(start);
        distance[start.first][start.second] = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && distance[nx][ny] == -1 && grid[nx][ny] == 0) {
                    distance[nx][ny] = distance[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return distance; // 各セルへの距離を返す
    }
};
