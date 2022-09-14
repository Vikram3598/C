#include <stdio.h>
#include <iostream>
using namespace std;

int main()                              //MAIN STARTS
{
    int h,mid,l=0,i;
    int BinarySearch(int[],int,int,int);
    
    cout<<"ENTER THE SIZE OF ARRAY :";
    cin>>h;
    
    int arr[h],n;
    
    cout<<"\nENTER ELEMENTS OF ARRAY IN ASCENDING ORDER : \n";
    for(i=0;i<h;i++)
     {
         cout<<"arr["<<i<<"] = ";
         cin>>arr[i];
     }
     
         
    cout<<"\nENTER ELEMENT TO SEARCH : ";
    cin>>n;

    int result = BinarySearch(arr,n,l,h);               //FUNCTION CALL
    
    if(result==-1)
        {
          cout<<"\nELEMENT NOT FOUND.  \n";
        }
    else
        {
          cout<<"\nELEMENT "<<n<<" FOUND AT LOCATION "<<result <<". "<<"\n";
          exit(0);
        }

    return 0;
}                       //END OF MAIN()



int BinarySearch(int arr[],int n,int l,int h)       //DEFINITION RECURSIVE BINARY SEARCH FUNCTION
 {
        
     if(l<=h)
      {
        int mid=(l+h)/2;
     
     
        if(arr[mid]==n)
                return mid;
        else if(arr[mid]<n)
                return BinarySearch(arr,n,mid+1,h);
        else
                return BinarySearch(arr,n,l,mid-1);
      }

    return -1;       
 }