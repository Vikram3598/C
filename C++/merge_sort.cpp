#include<iostream>
#include<chrono>                                //help to calculate execution time 
#include<stdlib.h>                              //for rand() function
using namespace std;
                                                
void Merge(int *A,int l, int h, int mid)        //Merge() function  
{
    int i,j,k,n,m;  

    m=mid-l+1;
    n=h-mid;
    int M[m],N[n];
    
    for(i=0;i<m;i++)
        M[i]=A[l+i];
    
    for(i=0;i<n;i++)
        N[i]=A[mid+1+i];
    
    
    i=0,j=0,k=l;
    if(l<h)
    {
        while(i<m && j<n) 
        {
            if(M[i]<=N[j])
                A[k++]=M[i++];
            else
                A[k++]=N[j++];  
        }
        
        for(;i<m;i++)
            A[k++]=M[i];
        
        for(;j<n;j++)
            A[k++]=N[j];
    }
}
    



                                                
void MergeSort(int *A,int l,int h)              //MergeSort() function
{
    if(l<h)
    {
        int mid = l + (h-l)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,h,mid);
    }
}



void PrintArray(int *A,int s)                   //PrintArray() function
{
    int i;
    for(i=0;i<s;i++)
     {
         cout<<A[i]<<"\t";
     }    
}


void GenerateArray(int *A,int size)             //GenerateArray() function
{
    for(int i=0;i<size;i++)
       A[i] = rand();
}


int main()                                                        //main() STARTS
{
    int size,i;
    cout<<"ENTER SIZE OF ARRAY : ";
    cin>>size;
    
    int A[size];
    GenerateArray(A,size);
    
   /* cout<<"\nENTER VALUE IN ARRAY : \n";
        for(i=0;i<size;i++)
            {
                cout<<"A["<<i<<"] = ";
                //cin>>A[i];
            } */
            
    cout<<"\nARRAY BEFORE SORTING : \n ";    
    PrintArray(A,size);
    cout<<"\n";
    
    auto start = std::chrono::high_resolution_clock::now();           //CLOCK START
    
    MergeSort(A,0,size-1);
    
    auto stop = std::chrono::high_resolution_clock::now();            //CLOCK STOP
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    
    cout<<"\n";
    cout<<"\nARRAY AFTER SORTING : \n ";    
    PrintArray(A,size);
    cout<<"\n\nTIME TAKEN BY MERGE SORT FUNCTION : " << duration.count()<<" microseconds\n";
    
 return 0;   
}                                                                     //END OF main()