//[-2,-3,4,-1,-2,1,5,-3]


#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the total no. of elements";
    cin >>n;
    int sum=0;
    int nums[n];
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    } 
    int max=INT_MIN;
    int j=0;
    int s=0;
    int l;
    for(int i=0;i<n;i++)
    {
        sum=sum+nums[i];

        if(sum>max){
            max=sum;
            l=i;
        }
        if(sum<0)       //Agar kbhi bhi sum 0 se kam ho gya toh usko hum 0 kar denge because we will not carry any negative to the future
        {   
            sum=0;
            s=s+1;
        }
    }
    cout<< "The subarray [";
    cout<<max;
}


        
