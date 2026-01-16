#include <iostream>
#include <queue>
using namespace std;
int a[100][100];
int n, m;
bool visit[100];
string city[100];
void bfs(int s){
	visit[s] = true;
	queue<int> p;
	p.push(s);
	while (!p.empty()) {
		int x = p.front();
		p.pop();
		cout << city[x] << " ";
		for (int y = n; y >=1; y--) {
			if (a[x][y] == 1 && !visit[y]) {
				visit[y] = 1;
				p.push(y);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	cout << "nhap ten thanh pho theo so thu tu:" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> city[i];
		for (int j = 1; j <= n; j++) {
			a[i][j] = 0;
		}
	}
	cout << "nhap duong:";
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		visit[i] = false;
	}
	int t=0;
	for (int i = 1; i <= n; i++) {
		if (city[i] == s) {
			t = i;
			break;
		}
	}
	bfs(t);
	return 0;
}
