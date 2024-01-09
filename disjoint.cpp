#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Disjoint{
 vector<int>rank,parent,size;
public:
 //create a constructor
 Disjoint(int n){
   rank.resize(n+1,0);
   size.resize(n+1);
   for(int i=0;i<=n;i++){
     parent.push_back(i);
     size[i]=1;
   }
 }

int findUlParent(int n){
  if(n==parent[n])return n;
  return parent[n]=findUlParent(parent[n]);
}

void unionByRank(int u,int v){
 int ulu=findUlParent(u);
 int ulv=findUlParent(v);
 if(ulu==ulv)return;

  //check for the smaller rank and may go to connect with other parent of the larger rank
  if(rank[ulu]<rank[ulv]){
    parent[ulu]=ulv;
  }else if(rank[ulv]<rank[ulu]){
    parent[ulv]=ulu;
  }else{
    parent[ulv]=ulu;
    rank[ulu]++;
  }
 
}

//create a size of union
void unionBySize(int u,int v){
 int ulu=findUlParent(u);
 int ulv=findUlParent(v);
 if(ulu==ulv)return;
  if(size[ulu]<size[ulv]){
    parent[ulu]=ulv;
    size[ulv]+=size[ulu];
  }else {
    parent[ulv]=ulu;
    size[ulu]+=size[ulv];
  }
  
}
};
int main() {
  Disjoint ds(7);
  ds.unionBySize(1,2);
  ds.unionBySize(2,3);
  ds.unionBySize(4,5);
  ds.unionBySize(6,7);
  ds.unionBySize(5,6);
  ds.unionBySize(3,7);
  if( ds.findUlParent(3)== ds.findUlParent(7)){
     cout<<"yes its belong to the same parent node\n";
   }else cout<<"no it is not the same parent node\n";
  return 0;
}