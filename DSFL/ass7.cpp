#include <bits/stdc++.h>

using namespace std;

struct adjElement{
    bool isEdge = false;
    int weight=0;
};

struct edge{
    int from, to, weight;
};

class Graph{
    int n, m;
    adjElement **adj;
    edge *edges;
    int edgei;
    
public:
    Graph(int n, int m){
        this->n = n;
        this->m = m;
        this->adj = new adjElement*[n];
        for(int i=0;i<n;i++)
            adj[i] = new adjElement[n];
        this->edges = new edge[m];
        edgei = 0;
    }
    
    void makeSide(int from, int to, int weight){
        if(from > n || to > n || weight <= 0)
            throw 0;
        adj[from-1][to-1] = {true, weight};
        adj[to-1][from-1] = {true, weight};
        edges[edgei++] = {from, to, weight};
    }
    
    static int comp(edge a, edge b){
        return (a.weight < b.weight);
    }
    
    Graph getMst(){
        Graph mst(n, n-1);
        
        bool vis[n+1]={0};
        int grp[n+1]={0};
        int maxgrp = 1;
        sort(edges, edges+m, comp);
        for(int i=0;i<m;i++)
        {
            if(grp[edges[i].from] ==0 && grp[edges[i].to]==0){
                grp[edges[i].from] = maxgrp++;
                grp[edges[i].to] = grp[edges[i].from];
                mst.makeSide(edges[i].from, edges[i].to, edges[i].weight);
                continue;
            }
            if(grp[edges[i].from] ==0){
                grp[edges[i].from] = grp[edges[i].to];
                mst.makeSide(edges[i].from, edges[i].to, edges[i].weight);
                continue;
            }
            if(grp[edges[i].to] ==0){
                grp[edges[i].to] = grp[edges[i].from];
                mst.makeSide(edges[i].from, edges[i].to, edges[i].weight);
                continue;
            }
            
            if(grp[edges[i].from] == grp[edges[i].to])
                continue;
            
            for(int j=0;j<m;j++){
                if(grp[edges[j].from] == grp[edges[i].to]){
                    grp[edges[j].from] = grp[edges[i].from];
                    grp[edges[j].to] = grp[edges[i].from];
                }
            }
            mst.makeSide(edges[i].from, edges[i].to, edges[i].weight);
        }
        
        return mst;
    }
    
    void disp(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << adj[i][j].weight << "  ";
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4, 5);
    g.makeSide(1, 2, 1);
    g.makeSide(1, 3, 2);
    g.makeSide(3, 4, 3);
    g.makeSide(2, 4, 5);
    g.makeSide(1, 4, 4);
    g.disp();
    cout << "\n\nMST: \n";
    Graph mst = g.getMst();
    mst.disp();
    return 0;
}
