#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct dsu {
    vector<int>par,sz;
    void init(int n) {

        for (int i = 1; i <= n; i++) {

            par[i]=i;
            sz[i]=1;
        }
    }

    int find_par(int u) {
        if (par[u]== u)
            return u;
        return par[u] = find_par(par[u]);
    }

    void connect(int u, int v) {

            u = find_par(u);
            v = find_par(v);
            if (u == v)
                return;

         if(sz[u]>sz[v])
         {
             sz[u]+=sz[v];
             par[v]=u;
         }
         else
         {
             sz[v]+=sz[u];
             par[u]=v;
         }
    }


};

int main(){
    
    int num_of_nodes, num_of_edges ;

    cin>>num_of_nodes>>num_of_edges;

    vector<pair<int,pair<int,int>>>edges;


    for(int i=0;i<num_of_edges;i++)
    {
        int u,v ,w;

        cin>>u>>v>>w;

        edges.push_back({w,{u,v}});
    }
    dsu ds ;

    ds.par.resize(num_of_nodes+1);

    ds.sz.resize(num_of_nodes+1);
    ds.init(num_of_nodes+1);

    sort(edges.begin(),edges.end());

    int cost= 0 ;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].second.first;
        int v=edges[i].second.second;
        int  c=edges[i].first;
        if(ds.find_par(u)!=ds.find_par(v)) {
            ds.connect(u, v);
            cost+=c;
        }
    }
    cout<<cost<<endl;
   
}
