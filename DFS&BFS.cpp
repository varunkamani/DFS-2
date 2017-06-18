#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <string>
#include <stack>
using namespace std;
class graph{
    int n;
    vector< vector<int> > matrix;
public:
    graph(int n){
        this->n=n;
        matrix = vector<vector<int> >(n,vector<int>(n));
    }
    void addEdge(int a,int b);
    void printGraph();
    void BFS(int i);
    void DFS(int i);
};
void graph::addEdge(int a,int b){
        matrix[a][b]=1;
        matrix[b][a]=1;
    }
void graph::printGraph(){
        string str="";
        cout<<"    ";
        for(int i=0;i<n;i++){
            cout<<i<<" ";
            str+="-";
        }
        str+=str;
        cout<<"\n    "<<str<<"\n";
        for(int i=0;i<n;i++){
            cout<<i<<" : ";
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
void graph::BFS(int i){
        cout<<"BFS : ";
        queue<int> q;
        q.push(i);
        vector<int> visited(n,0);
        visited[i]=1;
        while(!q.empty()){
            int p=q.front();
            for(int j=0;j<n;j++){
                if(matrix[p][j]==1 && visited[j]!=1){
                    q.push(j);
                    visited[j]=1;
                }
            }
            cout<<q.front()<<" ";
            q.pop();
        }
    }
void graph::DFS(int k){
        cout<<"DFS : ";
        stack<int> s;
        vector<int> visited(n,0);
        s.push(k);
        visited[k]=1;
        while(!s.empty()){
            int p = s.top();
            cout<<p<<" ";
            s.pop();
            for(int j=0;j<n;j++){
                if(matrix[p][j]==1 && visited[j]!=1){
                    visited[j]=1;
                    s.push(j);
                }
            }
        }
    }
int main(){
    int n;
    cout<<"Number of nodes in graph (0 to n-1) : ";
    cin>>n;
    graph gh(n);
    int start,option=1,choice,i,j;
    while(option){
        cout<<"\n 1.Add Edge\n 2.Print Adjacency Matrix \n 3.Breadth First Search of Graph\n 4.Depth First Search of Graph\n 5.Exit\n Your choice ?\n";
        cin>>choice;
        switch(choice){
            case 1: 
                cout<<"Enter two nodes : ";
                cin>>i>>j;
                gh.addEdge(i,j);
                break;
            case 2:
                gh.printGraph();
                break;
            case 3:
                cout<<"Starting node ? ";
                cin>>i;
                gh.BFS(i);
                break;
            case 4:
                cout<<"Starting node ? ";
                cin>>start;
                gh.DFS(start);
                break;
            case 5:
                option=0;
                break;
            default:
                cout<<"Enter valid choice\n";
                break;
        }
    }
    return 0;
}
