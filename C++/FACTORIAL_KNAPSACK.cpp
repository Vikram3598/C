#include <iostream>                                 //HEADER FILE

using namespace std;

struct values                                       //STRUCTURE DEFINITION
{       
    float profit;
    float weight;                       
    float profit_per_kg;
};


/*void sort(struct values* A [],int n)
{
    int i,j;
    float temp[3];
    //struct values v;
    
    for(i=0;i<n;i++)
    {
       //max=A[i];
        for(j=i+1;j<n;j++)
        {
            if(A[j]->profit_per_kg > A[i]->profit_per_kg)
            {
                temp[0] = A[i]->profit;
                temp[1] = A[i]->weight;                
                temp[2] = A[i]->profit_per_kg;
                //v->profit = A[i].profit;
                
                A[i]->profit=A[j]->profit;
                A[i]->weight=A[j]->weight;
                A[i]->profit_per_kg=A[j]->profit_per_kg;                
                //A[i]->profit = A[j].profit;
                
                A[j]->profit=temp[0];
                A[j]->weight=temp[1];
                A[j]->profit_per_kg=temp[2];
                //A[j]->profit = v.profit;
            }
        }
        
    }
    return;
}*/


int main()                                  //main() STARTS
{
    int n,i,j;
    float sum=0,temp[3],knapsack=0,cap=0;
    cout<<"ENTER NUMBER OF DATA VALUES : ";
    cin>>n;
    
    struct values v[n];                     //ARRAY OF SRTUCTURE
    
    for(i=0;i<n;i++)                        //INPUT OF VALUES
    {
        cout<<"PRODUCT ===> "<<i+1<<"\n";
        cout<<"PROFIT         :\t";
        cin>>v[i].profit;
        cout<<"WEIGHT (in KG) :\t";
        cin>>v[i].weight;
        v[i].profit_per_kg=v[i].profit/v[i].weight;
        cout<<"PROFIT/KG      :\t"<<v[i].profit_per_kg<<"\n\n\n";   
        sum=sum + v[i].weight;
        
    }
    
    
    
    
    for(i=0;i<n;i++)                            //operation for sorting the array
    {
        for(j=i+1;j<n;j++)
        {
            if(v[j].profit_per_kg > v[i].profit_per_kg)
            {
                temp[0] = v[i].profit;
                temp[1] = v[i].weight;                
                temp[2] = v[i].profit_per_kg;
                
                
                v[i].profit = v[j].profit;
                v[i].weight = v[j].weight;
                v[i].profit_per_kg = v[j].profit_per_kg;                
                
                
                v[j].profit = temp[0];
                v[j].weight = temp[1];
                v[j].profit_per_kg = temp[2];
            }
        }
    }  
    

    
    cout<<"\n\n"<<"  TOTAL PROFIT\t"<<"    TOTAL WEIGHT(KG)\t"<<"   PROFIT/WEIGHT\n";         //PRINT VALUES IN SORTED FORM
    for(i=0;i<n;i++)
    {
        cout<<"\t"<<v[i].profit<<"\t\t"<<v[i].weight<<"\t\t\t"<<v[i].profit_per_kg<<"\n";
    }    
    
    
    cout<<"\n\nENTER THE CAPACITY OF BAG (FOR MAXIMUM PROFIT) <= "<<sum<<" :\t";
    cin>>cap;    

    
    int k=0;
    while(cap!=0)                                           //OPERATION TO FIND MAXIMUM PROFIT
    {
        if(v[k].weight<=cap)
        {
            knapsack = knapsack + ( v[k].weight * v[k].profit_per_kg);
            cap = cap - v[k].weight;
            k++;
        }
        else
        {
            knapsack = knapsack + (cap * v[k].profit_per_kg);
            cap = cap - cap;
            k++;
        }
    }
    
    cout<<"\n\nMAXIMUM PROFIT :\t"<<knapsack<<"\n";
    
    
    return 0;
}                                                           //END OF main()