#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class graph{    
  private:
       int vertices;
       std::vector<int> *adj;
     
  public:
     graph(int n, int e){       
         vertices = n;
         adj = new std::vector<int>[n];         
     }
    ~graph() {
        delete[] adj;
    }
     void addEdge( int x, int y){
         adj[x-1].emplace_back(y);
         adj[y-1].emplace_back(x);
     }
     std::vector<int> BFSLeastCost(int start)
     {      
         std::list<int> que;                
         std::vector<int> visited( vertices, 0);
         que.push_back(start);
         visited[start-1] = 0 ;
         
         while( !que.empty()){            
             int vert = que.front();            
             que.pop_front();           
             
             for( int& val: adj[vert-1] ){
                       
                 if( !visited[val-1] && val != start )
                 {
                   
                     if(visited[val-1] == 0 )
                        visited[val-1] = visited[vert-1] + 1 ;
                     else if( visited[val-1] > visited[vert-1] + 1)
                        visited[val-1] = visited[vert-1] + 1 ;
                     que.push_back(val);
                 }                 
             }
             
             
         }
         return visited;
         
     }
       
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios_base::sync_with_stdio(false);
   
    int testes;
    std::cin >> testes;
     
    while( testes > 0)
    {
      
        int vert = 0;
        int edges = 0;        
        std::cin >> vert;
        std::cin >> edges;
      
        
        graph gph(vert, edges);
       
       
       
        while( edges > 0)
        {          
            int x, y;
            std::cin>> x >> y;            
            gph.addEdge(x,y);            
            --edges;              
        }
       
        int start = 0;
        std::cin >> start;
        
       
        
        std::vector<int> result = gph.BFSLeastCost(start);
       
        for (int it= 0; it < result.size(); ++it)
        {
            if( it != start-1)
            {
               if( result[it])
               {
                   std::cout<< result[it]*6 <<" "; 
                   continue;
               }                      
               std::cout << -1 <<" ";
            }
            
            
        } 
        std::cout<<"\n";
        --testes;
        
    }
    return 0;
}
