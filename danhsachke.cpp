#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node* next;
};
node* head[100];
bool visit[100];
string city[100];
int n, m;
void add(int x, int y) {
    node* p = new node;
    p->data = y;
    p->next = head[x];
    head[x] = p;
}
void bfs(int s) {
    queue<int> q;
    visit[s] = true;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << city[x] << " ";
        node* p = head[x];
        while (p != NULL) {
            int y = p->data;
            if (!visit[y]) {
                visit[y] = true;
                q.push(y);
            }
            p = p->next;
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> city[i];
        head[i] = NULL;
        visit[i] = false;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    string s;
    cin >> s;
    int t = -1;
    for (int i = 1; i <= n; i++) {
        if (city[i] == s) {
            t = i;
            break;
        }
    }
    if (t == -1) {
        cout << "Khong tim thay thanh pho";
        return 0;
    }
    bfs(t);
    return 0;
}
