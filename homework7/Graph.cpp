#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <stdio.h>
#include <list>

//HOKYINSHUM
//COLBAORATE: HUA BIN LIU
Graph::Graph(){

};

int Graph::addVertex(){
  int tmp = vertices.size();
  vertices.insert(tmp);
  return tmp;
};

int Graph::getNumVertices(){
  return vertices.size();
};

void Graph::addEdge(directedEdge newEdge, int weight){
  set<int>::iterator end =vertices.end();
  set<int>::iterator one = vertices.find(newEdge.first);
  set<int>::iterator two = vertices.find(newEdge.second);
  if(one == end || two == end){
    cout << "One of the vertices not initizalized."  << endl;
  }
  else{
    edges.insert(newEdge);
    pair<directedEdge, int> tmp;
    tmp.first = newEdge;
    tmp.second = weight;
    weights.insert(tmp);
  }
  return;
};

bool Graph::isEdge(directedEdge newEdge){
  set<directedEdge>::iterator end =edges.end();
  set<directedEdge>::iterator one = edges.find(newEdge);
  if(one == end){
    return false;
  }
  return true;
};

int Graph::getWeight(directedEdge edge){
  if(isEdge(edge)){
    map<directedEdge, int>::iterator it;
    it = weights.find(edge);
    return (*it).second;
  }
  return -1;
};

//output adjacency list with weight.
void Graph::print(){
  for(int i = 0; i < vertices.size(); ++i){
    cout << i << ": ";
    //iterate through the edges finding .second,
    for(set<directedEdge>::iterator it = edges.begin(); it != edges.end(); it++){
      if((*it).first == i) {
        cout << (*it).second << " (" << getWeight((*it)) << ") ";
      }
    }
    cout << endl;
  }
};

void Graph::generateGraph(string fileName){
  string line;
  ifstream myfile(fileName.c_str());
  if(myfile.is_open())
  {
    //First line input.
    int v_num = 0;
    int e_num = 0;
    myfile >>  v_num;
    for(int i = 0; i < v_num; ++i) addVertex();
    myfile >> e_num;
    getline(myfile,line);

    //Subsequent line input.
    while (getline (myfile,line)){
      vector<int> input;
      stringstream ss;
      ss << line;
      string temp;
      int found;
      while(!ss.eof()){
        ss >> temp;
        if(stringstream(temp) >> found)
          //cout << found << " ";
          input.push_back(found);
          temp ="";
      }
      directedEdge inputEdge;
      int inputWeight;
      inputWeight = input.at(2);
      inputEdge.first = input.at(0);
      inputEdge.second = input.at(1);
      addEdge(inputEdge, inputWeight);
    }
    myfile.close();
  }
  else cout << "Unable to open file" << endl;
  return;
};
//modified so that the relax function finds not the actual path but the # of paths
//of that length. and uses negative instead of infinity.
void Graph::modifiedDijkstra(int source){
  //initialization
	int d[getNumVertices()]; // d[];
	int paths[getNumVertices()];//p[];
	list<int>q; //queue
	list<int>::iterator qIt; //qIt = Queue_Iterator.
	set<directedEdge>::iterator eIt; // eIt = Edge_Iterator.
	for(int i = 0; i < getNumVertices(); i++){
		d[i] = -1; //No negative weight, use this as like Infinity.
		paths[i] = 0;//itialize number of paths at there as 0.
		if(i != source){
      //Queue q contains all v but src
			q.push_back(i);
		}
	}
	d[source] = 0; //initialize source distance.

  //Special case for src
	//Auto update: min distance since every other vertex is infinity(-1)
	for(eIt = edges.begin(); eIt != edges.end(); eIt++){
		if(eIt->first == source){
			d[eIt->second] = getWeight(*eIt);
			paths[eIt->second]++;
		}
	}
	int d_min; // Minimum distance.
	list<int>::iterator i_min; //Minimum's index.
	while(!q.empty()){
		qIt = q.begin();
		d_min = d[*qIt];
		i_min = qIt;
		for(qIt = q.begin(); qIt != q.end(); qIt++){
			if(d[*qIt] == -1){
				continue;
			}
			if(d_min == -1){ //INF.
				d_min = d[*qIt];
				i_min = qIt;
			}
			else if(d[*qIt] < d_min){
				d_min = d[*qIt];
				i_min = qIt;
			}
		}
		for(eIt = edges.begin(); eIt != edges.end(); eIt++){
			if(eIt->first == *i_min){
				if(d[eIt->second] == -1){
					d[eIt->second] = d[eIt->first] + getWeight(*eIt);
					paths[eIt->second]++;
				}
				else if(d[eIt->first] + getWeight(*eIt) < d[eIt->second])
					d[eIt->second] = d[eIt->first] + getWeight(*eIt);
				else if(d[eIt->first] + getWeight(*eIt) == d[eIt->second])
					paths[eIt->second]++;
	      else{}
			}
		}
		q.erase(i_min);
	}
	cout << endl;
  cout << "Shortest paths from node " << source << ":" << endl;
	for(int i = 1; i < getNumVertices(); i++){
		cout << "distance to vertex " << i << " is ";
    cout << d[i] << " and there are " << paths[i] << " shortest paths" << endl;
	}
	return;
}
