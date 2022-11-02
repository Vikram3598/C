#include <iostream>
using namespace std;
#include <limits.h>

#define INF 99999

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


  
  // Add edges for directed graph  
  void addEdge1(int i, int j,int w) 
  {
    adjMatrix[i][j] = w;
    //adjMatrix[j][i] = w;
  }
  


/* A utility function to print solution */
void printSolution(int dist[][numVertices])
{
	cout << "The following matrix shows the shortest distances between every pair of vertices \n";
	
	for (int i = 0; i < numVertices; i++) 
	{
		for (int j = 0; j < numVertices; j++) 
		{
			if (dist[i][j] == INF)
				cout << "INF"<< "	 ";
			else
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
}




  

void floydWarshall()
{
	/* dist[][] will be the output matrix
	that will finally have the shortest
	distances between every pair of vertices */
	int dist[numVertices][numVertices], i, j, k;

	/* Initialize the solution matrix same
	as input graph matrix. Or we can say
	the initial values of shortest distances
	are based on shortest paths considering
	no intermediate vertex. */
	for (i = 0; i < numVertices; i++)
		for (j = 0; j < numVertices; j++)
			dist[i][j] = adjMatrix[i][j];

	/* Add all vertices one by one to
	the set of intermediate vertices.
	---> Before start of an iteration,
	we have shortest distances between all
	pairs of vertices such that the
	shortest distances consider only the
	vertices in set {0, 1, 2, .. k-1} as
	intermediate vertices.
	----> After the end of an iteration,
	vertex no. k is added to the set of
	intermediate vertices and the set becomes {0, 1, 2, ..
	k} */
	for (k = 0; k < numVertices; k++) 
	{
		// Pick all vertices as source one by one
		for (i = 0; i < numVertices; i++) 
		{
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < numVertices; j++) 
			{
				// If vertex k is on the shortest path from
				// i to j, then update the value of
				// dist[i][j]
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
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
    
        if(p>n || q>n )
        {
        cout<<"INVALID INPUT OF VERTICES FOR EDGE !!!!!!    TRY AGAIN PLEASE \n ";
        i=i-1;
        }
        else
        g.addEdge1(p, q, w);
    }    
        
	g.floydWarshall();                          // Function call

	return 0;
}                                           //END OF main() 
        
        