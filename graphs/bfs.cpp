#include<iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;

class Graph {
    map<int, bool> visited;
    map<int, list<int> > adj;
 
    public: 
    void addEdge(int v,int w){
        adj[v].push_back(w);
    }

    void BFS(int s){
        
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        list<int>::iterator i;
        while(!queue.empty()){
            s = queue.front();
            cout<<s<<" ";
            queue.pop_front();
            for(i = adj[s].begin();i!=adj[s].end();++i){
                if(!visited[*i]){
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
};

int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}