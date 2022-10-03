#include <iostream>
using namespace std;
#include <limits.h>

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



  // Add edges for undirected graph
  void addEdge(int i, int j,int w) 
  {
    adjMatrix[i][j] = w;
    adjMatrix[j][i] = w;
  }
  
  // Add edges for directed graph  
  void addEdge1(int i, int j,int w) 
  {
    adjMatrix[i][j] = w;
    //adjMatrix[j][i] = w;
  }
  

 

  int minDistance(int dist[], bool sptSet[])
  {

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < numVertices; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
  }




// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
	cout <<"\n\n Vertex \t\t Distance from Source" << endl;
	for (int i = 0; i < numVertices; i++)
		cout <<"   "<< i << " \t\t\t\t" << dist[i] << endl;
}




// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra( int src)
{
	int dist[numVertices]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool sptSet[numVertices]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest distance from src to i is
	// finalized

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < numVertices; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < numVertices - 1; count++) 
	{
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < numVertices; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && adjMatrix[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + adjMatrix[u][v] < dist[v])
				dist[v] = dist[u] + adjMatrix[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}


  ~Graph() 
  {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }

};






int main()                      //main() START
{
  
  char choice;
  int n,p,q,w,e;
  cout<<"\n ENTER THE NUMBER OF VERTEX : ";
  cin>>n;
  cout<<"\n ENTER THE NUMBER OF EDGES  : ";
  cin>>e;  
  Graph g(n);
  
      
  cout<<"\n IS GRAPH IS DIRECTED ? (Y/N): ";
  cin>>choice;
  
  
  switch(choice)
  {
    case 'Y' :
        for(int i=0;i<e;i++)
        {
            cout<<"\n ENTER VERTICES FOR EDGE "<<i+1<<" :\t";
            cin>>p>>q;
            cout<<" ENTER WEIGHT : ";
            cin>>w;
    
            if(p>n || q>n )
            {
            cout<<"INVALID INPUT OF VERTICES FOR EDGE !!!!!!    TRY AGAIN PLEASE \n ";
            i=i-1;
            }
            else
            g.addEdge1(p, q, w);
        }
        break;  

    case 'y' :
        for(int i=0;i<e;i++)
        {
            cout<<"\n ENTER VERTICES FOR EDGE "<<i+1<<" :\t";
            cin>>p>>q;
            cout<<" ENTER WEIGHT : ";
            cin>>w;
    
            if(p>n || q>n )
            {
            cout<<"INVALID INPUT OF VERTICES FOR EDGE !!!!!!    TRY AGAIN PLEASE \n ";
            i=i-1;
            }
            else
            g.addEdge1(p, q, w);
        }
        break;      
        
    case 'n' :
        for(int i=0;i<e;i++)
        {
            cout<<"\n ENTER VERTICES FOR EDGE "<<i+1<<" :\t";
            cin>>p>>q;
            cout<<" ENTER WEIGHT : ";
            cin>>w;
    
            if(p>n || q>n )
            {
            cout<<"INVALID INPUT OF VERTICES FOR EDGE !!!!!!    TRY AGAIN PLEASE \n ";
            i=i-1;
            }
            else
            g.addEdge(p, q, w);
        }
        break;  
    
    case 'N' :
        for(int i=0;i<e;i++)
        {
            cout<<"\n ENTER VERTICES FOR EDGE "<<i+1<<" :\t";
            cin>>p>>q;
            cout<<" ENTER WEIGHT : ";
            cin>>w;
    
            if(p>n || q>n )
            {
            cout<<"INVALID INPUT OF VERTICES FOR EDGE !!!!!!    TRY AGAIN PLEASE \n ";
            i=i-1;
            }
            else
            g.addEdge(p, q, w);
        }
        break;

    default :
    cout<<"\n INVALID INPUT !!!!!!";      
  }				

	g.dijkstra(0);                          // Function call

	return 0;
}                                           //END OF main() 

