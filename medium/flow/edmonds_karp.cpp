#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

class Edmonds_Karp{
private:
  vector< vector< int > > capacities;
  vector< vector< int > > flowPassed;
  vector< vector< int > > graph;
  vector< int > parentsList;
  vector< int > currentPathCapacity;
  int startNode;
  int endNode;
  int maxFlow;

public:
  Edmonds_Karp(vector< vector< int > > graph, vector< vector< int > > capacities, int startNode, int endNode){
    this->graph = graph;
    this->capacities = capacities;
    this->startNode = startNode;
    this->endNode = endNode;
    flowPassed.resize(graph.size());
    for ( int i = 0; i < graph.size(); i++ ){
      flowPassed[i].resize(graph.size(), 0);
    }
    parentsList.resize(graph.size());
    currentPathCapacity.resize(graph.size());
    makeFlow();
  }

  int bfs(){
    int INF = 9+1e9;
    int currentNode, to;
    for (  int i = 0; i < parentsList.size(); i++ ){
      parentsList[i] = -1;
    }
    for (  int i = 0; i < currentPathCapacity.size(); i++ ){
      currentPathCapacity[i] = 0;
    }
    queue< int > q;
    q.push(startNode);
    parentsList[startNode] = -2;
    currentPathCapacity[startNode] = INF;
    while( !q.empty() ){
      currentNode = q.front(); q.pop();
      for( int i = 0; i < graph[currentNode].size(); i++ ){
	to = graph[currentNode][i];
	if( parentsList[to] == -1 ){
	  if( capacities[currentNode][to] - flowPassed[currentNode][to] > 0 ){
	    parentsList[to] = currentNode;
	    currentPathCapacity[to] = min(currentPathCapacity[currentNode], capacities[currentNode][to] - flowPassed[currentNode][to]);
	    if( to == endNode ){
	      return currentPathCapacity[endNode];
	    }
	    q.push(to);
	  }
	}
      }
    }
    return 0;
  }

  int makeFlow(){    
    maxFlow=0;
    while(true){
      int flow=bfs();
      if(flow==0){
	break;
      }
      maxFlow +=flow;
      int currentNode=endNode;
      while(currentNode != startNode){
	int previousNode = parentsList[currentNode];
	flowPassed[previousNode][currentNode] += flow;
	flowPassed[currentNode][previousNode] -= flow;	
	currentNode=previousNode;
      }
    }
  }

  int getFlow(){
    return maxFlow;
  }
  
  vector< vector< int > > getFlowMatrix(){
    return flowPassed;
  }

};

int main(){
  
}
