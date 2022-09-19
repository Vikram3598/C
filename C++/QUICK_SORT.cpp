#include <stdio.h>
#include <iostream>
using namespace std;

void swap(int *a,int *b)                 //swap() FUNCTION
 {
     int temp = *a;
     *a = *b;
     *b = temp;
 }

int partition(int A[],int s,int l)        //partition() FUNCTION DEFINITION
{
    int i,j,pivot,temp;

    pivot=A[l];
    i=s-1;
    j=s;

    while(j<=l)
    {
        if(A[j] < pivot)
        {
            i++;
            swap(&A[j],&A[i]);
        }    
     
        j++;

    }
    
    swap(&A[i+1],&A[l]);    
    return (i+1);
}



void Quick_sort(int A[],int s,int l)        //Quick_sort() FUNCTION
{
    if(s<l)
    {
    int T = partition(A,s,l);
    Quick_sort(A,s,T-1);
    Quick_sort(A,T+1,l);
    }

}


int main()                          //main() START
{
    int i,j;                        //variables
    int k,n,s=0;
    
    cout<<"ENTER ARRAY SIZE : ";
    cin>>n;
    int A[n];
    
    cout<<"\nENTER ARRAY :  \n";
    for(int k=0;k<n;k++)
    {   
        cout<<"A["<<k<<"] = ";
        cin>>A[k];
    }
    
    Quick_sort(A,0,n-1);            //CALLING Quick_sort() FUNCTION

    cout<<"\nSORTED  ARRAY IS  :\t";
    for(k=0;k<n;k++)
    {
        cout<<"A["<<k<<"] = "<<A[k]<<"\t";
    }

return 0;
}                                   //END OF main()