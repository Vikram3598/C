#include <cstring>
#include <iostream>
using namespace std;



class Graph 
{
   private: 
   
    int** adjMatrix;
    int numVertices;


   public:
   
  // Initialize the matrix to zero
  Graph(int numVertices) 
  {
    this->numVertices = numVertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) 
    {
      adjMatrix[i] = new int[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = 0;
    }
  }



  
  // Add edges
  void addEdge(int i, int j,int w) 
  {
    adjMatrix[i][j] = w;
    adjMatrix[j][i] = w;
  }




  
  // Remove edges
  void removeEdge(int i, int j) 
  {
    adjMatrix[i][j] = 0;
    adjMatrix[j][i] = 0;
  }




  // Print the martix
  void toString()
  {
    cout<<"\n";
    for (int i = 0; i < numVertices; i++) 
    {
      cout <<" "<< i << " :\t";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << "\t";
      cout << "\n\n";
    }
  }




 void min_edge(int N)
 {
    int no_edge =0;
    int sum = 0;
    int selected[N];      
    
    memset(selected, false, sizeof(selected));      
    selected[0] = true;
         
   while (no_edge < N - 1) 
   {
     {
   
    
        int min = 999999;
        int x = 0;
        int y = 0;

        for (int i = 0; i < N; i++) 
        {
          if (selected[i]) 
          {
            for (int j = 0; j < N; j++) 
            {
              if (!selected[j] && adjMatrix[i][j]) 
              {  // not in selected and there is an edge
                if (min > adjMatrix[i][j]) 
                {
                  min = adjMatrix[i][j];
                  x = i;
                  y = j;
                }
              }
            }
          }
        }
        cout << " " << x << " - " << y << "\t :\t " << adjMatrix[x][y];
        cout << endl;
        sum = sum + adjMatrix[x][y];
        selected[y] = true;
        no_edge++;
     }

   }
      cout<<"\n SUM OF PATH : \t "<<sum<<"\n";
     
 }



  ~Graph() 
  {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};



int main() 
{
  int n,p,q,w,e;
  cout<<"\n ENTER THE NUMBER OF VERTEX : ";
  cin>>n;
  cout<<"\n ENTER THE NUMBER OF EDGES  : ";
  cin>>e;  
  Graph g(n);

  for(int i=0;i<e;i++)
  {
    cout<<"\n ENTER VERTICES FOR EDGE "<<i+1<<" :\t";
    cin>>p>>q;
    cout<<" ENTER WEIGHT : ";
    cin>>w;
    
    if(p==q && w>0)
     {
     cout<<"INVALID INPUT !!!!!     FOR THIS INPUT OF VERTICES WEIGHT MUST BE ZERO .\n";
     i=i-1;
     }
    else if(p!=q && w==0)
     {
     cout<<"INVALID INPUT !!!!!     FOR THIS INPUT OF VERTICES WEIGHT MUST BE GRATER THEN ZERO .\n";
     i=i-1;
     }
    else if(p>n || q>n )
     {
     cout<<"INVALID INPUT OF VERTICES FOR EDGE !!!!!!    TRY AGAIN PLEASE \n ";
     i=i-1;
     }
    else
     g.addEdge(p, q, w);

  }
  
  g.toString();
  
  cout << "\n Edge\t "<<":\t"<<"Weight";
  cout << endl;
  g.min_edge(n);
}