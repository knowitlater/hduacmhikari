#include <iostream>
using namespace std;
#define N 9
char maze[N][N];

int n, m, T;
int i, j, k;
int si, sj;
int dr[4][2] = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };
int newsi, newsj;
bool dfs(int si, int sj, int t) {
//	cout << t << endl;
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= m; j++) {
//			cout << maze[i][j];
//		}
//		cout << endl;
//	}
//	cout << t << endl;
	if (maze[si][sj] == 'D') {
		if (t == T)
			return true;
		else
			return false;
	}
	for (int i = 0; i < 4; i++) {
		newsi = si + dr[i][0];
		newsj = sj + dr[i][1];
		if (newsi <= 0 || newsi > n || newsj <= 0 || newsj > m)
			continue;
		if (maze[newsi][newsj] != 'X') {
			maze[si][sj] = 'X';
			if (dfs(newsi, newsj, t + 1)) {
				return true;
			}
			maze[si][sj] = '.';
		}
	}
	return false;
}
int wall;
int main() {
	while (cin >> n >> m >> T) {
		if (n == 0 && m == 0 && T == 0) {
			return 0;
		}
		wall = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				cin >> maze[i][j];
				if (maze[i][j] == 'S') {
					si = i;
					sj = j;
				} else if (maze[i][j] == 'X')
					wall++;
			}
		}
		if (n * m - wall <= T) {
			cout << "NO" << endl;
			continue;
		}
		if (dfs(si, sj, 0)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
	return 0;
}
