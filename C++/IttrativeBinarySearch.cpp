#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int h,mid,l=0,i;
   
    
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
    
    
    while(l<=h)
    {
        int mid=(l+h)/2;
     
        if(arr[mid]==n)
        {
          cout<<"\nELEMENT "<<n<<" FOUND AT LOCATION "<<mid <<". "<<".  \n";
          exit(0);
        }
     
        else if(arr[mid]<n)
             l=mid+1;
        
        else
        
              h=mid-1;
        
    }

    cout<<"\nELEMENT NOT FOUND  \n";
    
    

    return 0;
}
