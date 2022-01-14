#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> edges[101];
bool visited[101];
queue<pair<int, int>> q; // bfs에서 사용할 큐 (idx, depth)
int len, src, dst;

void initialize() {
   for (int i = 0; i < 101; i++) {
      visited[i] = false;
      edges[i] = vector<int>(0);
   }
}

void inputs() {
   cin >> len >> src;
   q.push(make_pair(src, 0));
   for (int i = 0; i < len; i += 2) {
      cin >> src >> dst;
      edges[src].push_back(dst);
   }
}

int bfs() {
   int max_dep = 0;
   int max_val = 0;

   while (!q.empty()) {
      int cur = q.front().first;
      int dep = q.front().second;
      q.pop();
      if (max_dep < dep || (max_dep == dep && max_val < cur)) {
         max_dep = dep;
         max_val = cur;
      }
      if (!visited[cur]) {
         visited[cur] = true;
         for (int next : edges[cur]) {
            if (!visited[next]) {
               q.push(make_pair(next, dep + 1));
            }
         }
      }
   }
   return max_val;
}

int main(void) {
   for (int test_case = 1; test_case <= 10; ++test_case){
      initialize();
      inputs();
      cout << '#' << test_case << ' ' << bfs() << '\n';
   }

   return 0;
}