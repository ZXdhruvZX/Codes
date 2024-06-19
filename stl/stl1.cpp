//Syntax of a Vector-  vector<data_type> vector_name;

//And suppose we want to have a vector of integers; the following program would do the needful:

#include<iostream>
#include<vector>
 
 
/* 
int main(){
 
    vector<int> vec1;  //Declaring of a vector
    return 0;
}
*/

//____________________________________________________________________________________


//A Program to demonstrate the working of 

using namespace std;
void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){ 
    vector<int> vec1;
    int element, size;
    cout<<"Enter the size of your vector"<<endl;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter an element to add to this vector: ";
        cin>>element;
        vec1.push_back(element);              //Vectors have a method, push_back(), to insert elements in it from the rear end
    }
    display(vec1);
    
    
    vec1.pop_back();                         //This function removes the last entered element from 
    display(vec1);
    
    display(vec1);
    vector<int> :: iterator iter = vec1.begin();
    vec1.insert(iter,566);
    display(vec1);
}



