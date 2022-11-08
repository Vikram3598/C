#include <iostream>

using namespace std;


void floyds(int n,int b[][10])
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout<<"\nMinimum Cost With Respect to Node:"<<i<<endl;
        for (j = 0; j < n; j++)
        {
            cout<<b[i][j]<<"\t";
        }
 
    }
}
int main()
{
	int n;
	cout<<"ENTER NUMBER OF NODES :\t";
	cin>>n;
	int  b[n][10];
    cout<<"ENTER VALUES OF ADJACENCY MATRIX\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>b[i][j];
        }
		cout<<"\n\n";
    }
    floyds(n,b);
}