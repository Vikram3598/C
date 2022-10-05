#include <iostream>

using namespace std;

int main()
{
    int n,i,j,k,d;
    cout<<"\n ENTER NUMBER OF MATRIX TO MULTIPLY : ";
    cin>>n;
    
    int D[n+1],min,q=0,Cost_Matrix[n][n]={0},Parenthesis_Matrix[n][n]={0};

    for(int i=0;i<n+1;i++)
    {
        cin>>D[i];
    }
    
    
    for(i=0;i<n;i++)
    {
        Cost_Matrix[i][i]=0;  
        Parenthesis_Matrix[i][j]=0;
    }
    

    for(d=1;d<n;d++)
    {
        for(i=0;i<n-d;i++)
        {
            j=i+d;
            min=99999;   
            for(k=i;k<j;j++)
            {
                q=Cost_Matrix[i][k]+Cost_Matrix[k+1][j]+(D[i]*D[k+1]*D[j+1]);
                
                if(q<min)
                {
                    min=q;
                    Parenthesis_Matrix[i][j]=k;
                }
            }
            Cost_Matrix[i][j]=min;
        }
    }
    
    
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
        cout<<Cost_Matrix[i][j]<<"\t";
        }
        cout<<"\n";        
    }
    

    return 0;
}
