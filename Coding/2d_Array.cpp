#include <iostream>
using namespace std;

int main()
{
    int rows;
    int columns;
    cout<<"Enter the rows"<<endl;
    cin>>rows;
    cout<<"Enter the columns"<<endl;
    cin>>columns;

    //Creating array
    int **arr=new int *[rows];
    for(int i=0;i<rows;i++)
    {
        arr[i]=new int [columns];
    }

    //Taking Input
    cout<<"Enter the values in array"<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin>>arr[i][j];
        }
        
    }

    //Showing output
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}