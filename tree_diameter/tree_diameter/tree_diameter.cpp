#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void bfs(std::vector<std::vector<int>> g,int s, std::vector<int>& res_d) {
  size_t n = g.size();
  res_d.resize(n);
  std::queue<int> q;
  q.push(s);
  std::vector<bool> used(n);
  std::vector<int> p(n);
  used[s] = true;
  p[s] = -1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (size_t i = 0; i < g[v].size(); ++i) {
      int to = g[v][i];
      if (!used[to]) {
        used[to] = true;
        q.push(to);
        res_d[to] = res_d[v] + 1;
        p[to] = v;
      }
    }
  }
}

int tree_diameter(std::vector<std::vector<int>>& g) {
  int v = 0;
  int u = 0; 
  int w = 0;
  std::vector<int> d;
  bfs(g, v, d);
  auto max_it = std::max_element(d.begin(), d.end());
  u = max_it - d.begin();
  d.clear();
  bfs(g, u,d);
  max_it = std::max_element(d.begin(), d.end());
  return *max_it;
}


int main()
{
  int n,a,b;
  std::vector<std::vector<int>> g;
  std::cin >> n;
  g.resize(n);
  for (int i = 0; i < n-1; ++i) {
    std::cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

    std::cout << tree_diameter(g); 
}
