#include<iostream>
#include<list>
using namespace std;

class Graph {

   int V;
   list<int> *adj;
   public:

   Graph(int V){
       this->V = V;
       adj = new list<int>[V];
   }
   void addEdge(int v,int w){
       adj[v].push_back(w);
   }
   void BFS(int s){
       bool visited[V];
       for(int i = 0;i<V;++i){
           visited[i] = false;
       }
       list<int> queue;
       queue.push_back(s);
       visited[s] = true;
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