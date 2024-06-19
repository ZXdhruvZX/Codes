//Queue me FIFO follow hota h
//Push rear me hota h
//Pop front ses hota h

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    //Creating a queue
    queue<int> q;

    q.push(10);
    q.push(12);
    q.push(14);
    cout<<"Size of queue is "<<q.size()<<endl;

    q.pop();

    cout<<"Size of queue is "<<q.size()<<endl;

    if(q.empty())
        cout<<"Queue is empty";
    else
        cout<<"Queue is not empty";


    cout<<endl;
    cout<<"Front of queue is "<<q.front();
    


}