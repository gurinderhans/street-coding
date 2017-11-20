#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>

using namespace std;

struct edge {
  int u,v,t0,P,d;
  int T;
};

void timedDijkstra(vector<edge> edges, int start, int end)
{
  unordered_map<int,pair<bool,int>> node_map;
  for(auto e:edges)
  {
    node_map[e.u]={false, INT_MAX};
    node_map[e.v]={false, INT_MAX};
  }

  node_map[start]={true, 0};

  int nodes_visited_count=0;

  while(nodes_visited_count < node_map.size())
  {
    int min_dist_node=-1; int dist_cmp=INT_MAX;
    for (auto it:node_map)
    {
      if (it.second.first == false && it.second.second < dist_cmp)
      {
        min_dist_node = it.first;
        dist_cmp = it.second.second;
      }
    }

    node_map[min_dist_node].first=true;
    nodes_visited_count++;

    for(auto e:edges)
    {
      if(e.u == min_dist_node)
      {
        int new_dist=node_map[min_dist_node].second + (e.t0 + T * e.P) + e.d;
        if (new_dist < node_map[min_dist_node].second)
        {
          node_map[min_dist_node].second = new_dist;
          // T=new_dist;
        }
      }
    }
  }

  cout << node_map[end].second<<endl;
}

int main()
{
  int n,m,q,s;
  cin>>n>>m>>q>>s;

  vector<edge> edges(m);
  for(int i=0;i<m;++i)
  {
    int u,v,t0,P,d;
    cin>>u>>v>>t0>>P>>d;
    edges[i]=edge{u,v,t0,P,d};
  }

  for(int i=0;i<q;++i)
  {
    int e;cin>>e;
    timedDijkstra(edges,s,e);
    break;
  }

  return 0;
}
