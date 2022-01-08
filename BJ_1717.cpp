#include <iostream>
using namespace std;
int parent[1000001];
int find_set(int v, int &cnt)
{
  while (parent[v] != v)
  {
    v = parent[v];
    cnt++;
  }
  return v;
}
void union_set(int v1, int v2)
{
  int cnt_x = 0, cnt_y = 0;
  v1 = find_set(v1, cnt_x);
  v2 = find_set(v2, cnt_y);
  if (v1 != v2)
  {
    if (cnt_x < cnt_y)
    {
      parent[v1] = v2;
    }
    else
    {
      parent[v2] = v1;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  int cmd, v1, v2, Q1 = 0, Q2 = 0;
  cin >> N >> M;
  for (int i = 0; i <= N; i++)
  {
    parent[i] = i;
  }
  for (int i = 0; i < M; i++)
  {
    cin >> cmd >> v1 >> v2;
    if (cmd == 0)
    {
      union_set(v1, v2);
    }
    else
    {
      int N1 = find_set(v1, Q1);
      int N2 = find_set(v2, Q2);
      if (N1 == N2)
      {
        cout << "YES\n";
      }
      else
      {
        cout << "NO\n";
      }
    }
  }
  return 0;
}