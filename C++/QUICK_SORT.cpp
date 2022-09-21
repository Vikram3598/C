#include <stdlib.h>                         // HEADER FILE FOR rand() function
#include <iostream>
#include<chrono>                            // HEADER FILE FOR chrono() function which calculate execution time
using namespace std;

void swap(int *a,int *b)                                        //swap() FUNCTION
 {
     int temp = *a;
     *a = *b;
     *b = temp;
 }

int partition(int A[],int s,int l)                              //partition() FUNCTION DEFINITION
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



void Quick_sort(int A[],int s,int l)                             //Quick_sort() FUNCTION
{
    if(s<l)
    {
    int T = partition(A,s,l);
    Quick_sort(A,s,T-1);
    Quick_sort(A,T+1,l);
    }

}


void GenerateArray(int *A,int size)                             //GenerateArray() function
{
    for(int i=0;i<size;i++)
       A[i] = rand();
    
    /*{   
        cout<<"A["<<i<<"] = ";
        cin>>A[i];
    }*/
}


void PrintArray(int *A,int s)                                     //PrintArray() function
{
    for(int i=0;i<s;i++)
     {
         cout<<A[i]<<"\t";
     }    
}


int main()                                                          //main() START
{
    int i,j;                                                        //variables
    int k,n,s=0;
    
    cout<<"ENTER ARRAY SIZE : ";
    cin>>n;
    int A[n];
    
    GenerateArray(A,n);                                             //CALLING GenerateArray() 
    
    cout<<"\nARRAY BEFORE SORTING :  ";
    PrintArray(A,n);                                                //CALLING PrintArray()
    
    
    auto start = std::chrono::high_resolution_clock::now();         //CLOCK START
    Quick_sort(A,0,n-1);                                            //CALLING Quick_sort() FUNCTION
    auto stop = std::chrono::high_resolution_clock::now();          //CLOCK END
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    
    
    cout<<"\nARRAY AFTER SORTING :\t";
    PrintArray(A,n);                                                //CALLING PrintArray()

    cout<<"\n\nTIME TAKEN BY Quick_sort() FUNCTION : " << duration.count()<<" microseconds\n";
return 0;
}                                                                   //END OF main()