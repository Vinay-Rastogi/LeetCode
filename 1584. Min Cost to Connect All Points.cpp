#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{
private:
        int findParent(vector<int>& parent,int node){

            if(parent[node] == node)
             return node;

            return parent[node] = findParent(parent,parent[node]); 
        }

public:
     int minCostConnectPoints(vector<vector<int>>& points){

          int n = points.size();
          vector<pair<int,pair<int,int>>> edges;

          for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int distance = abs(points[i][0] - points[j][0] + abs(points[i][1]-points[j][1]));

                edges.push_back({distance,{i,j}});
            }
          }

         sort(edges.begin(),edges.end());

         vector<int> parent(n);

         for(int i=0;i<n;i++)
         parent[i]= i;

         int minCost = 0;
         int numEdges = 0;

         for(auto edge : edges){

            int distance = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            int parentU = findParent(parent,u);
            int parentV = findParent(parent,v);

            if(parentU != parentV){

                parent[parentU] = parentV;
                minCost += distance;
                numEdges++;
            }

            if(numEdges == n-1)
            break;

         } 

        return minCost; 
     }

};

int main(){

        Solution sl;
        vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};

        cout << sl.minCostConnectPoints(points);

    return 0;
}