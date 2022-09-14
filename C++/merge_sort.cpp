#include<iostream>
using namespace std;

int main()
{

int i=0,j=0,k=0,n,m;
int arr[n],arr1[m],arr2[m+n];

cout<<"ENTER VALUE OF 'n' : ";
cin>>n;
//int arr[n];
cout<<"\nENTER VALUE IN FIRST ARRAY : \n ";
 for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  
  

cout<<"\nENTER VALUE OF 'm' : ";
cin>>m;
//int arr1[m];
cout<<"\nENTER VALUE IN SECOND ARRAY : \n ";
 for(i=0;i<m;i++)
  {
    cin>>arr1[i];
  }

//int arr2[n+m];
i=0;

while(i<=n &&  j<=m)
{
    if(arr[i]<=arr1[j])
        arr2[k++]=arr[i++];
    else
        arr2[k++]=arr1[j++];
}

for(;i<=n;i++)
 arr2[k++]=arr[i];

for(;j<=m;j++)
 arr2[k++]=arr1[j];


for(k=0;k<(n+m);k++)
{
    cout << arr2[k] << "  ";
}

return 0;
}