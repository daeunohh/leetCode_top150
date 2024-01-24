const char WATER = '0';
const char LAND = '1';
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int GridRowSize = 0;
int GridColSize = 0;

void findIsland(char** grid, int i, int j) {
	grid[i][j] = WATER;

	for (int dir = 0; dir < 4; dir++) {
		if ((0 > i + dx[dir] || i + dx[dir] >= GridRowSize) || \
			(0 > j + dy[dir] || j + dy[dir] >= GridColSize)) continue;

		if (grid[i + dx[dir]][j + dy[dir]] == LAND) {
			findIsland(grid, i + dx[dir], j + dy[dir]);
		}
	}
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
	int islandCnt = 0;
	GridRowSize = gridSize; GridColSize = *gridColSize;

	for (int i = 0; i < GridRowSize; i++) {
		for (int j = 0; j < GridColSize; j++) {
			if (grid[i][j] == LAND) {
				findIsland(grid, i, j);
				islandCnt += 1;
			}
		}
	}

	return islandCnt;
}
