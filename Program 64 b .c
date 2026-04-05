//You are given an m x n grid where each cell can have one of three values: Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int queue[m * n][2];
    int front = 0, rear = 0;

    int fresh = 0;

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int minutes = 0;

    while (front < rear && fresh > 0) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;   
                    fresh--;

                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                }
            }
        }

        minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}
