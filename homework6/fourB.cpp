//myB.cpp
//HokYinShum
//reference: http://www.geeksforgeeks.org/trie-insert-and-search/
//referrence: http://www.sourcetricks.com/2011/06/c-tries.html#.VvyRi7wX6hc
//Structure is consulted, and modification is made to suit the code for the assignment.
#include<iostream>
#include<vector>//
#include<fstream>
#include<string>
using namespace std;
//***************************NODE.CPP**********************************************************************
class Node{//Class of Node that will be used in trie.
public:
  Node(){alphabet = 0; square = false;} //constructor
  ~Node(){};//Destructor.
  void setAlphabet(char c){alphabet = c;}//Setter for alphabet.
  char getAlphabet(){return alphabet;}//Getter for alphabet.
  void setSquare(){square = true;}//Set a square to mark that the string exists.
  bool getSquare(){return square;}//Get the square mark value of the node.
  Node* findChildPtr(char c);//Function to return the child ptr that match 'c'.
  void appendChild(Node* child){children.push_back(child);};//Function to push_back a node to the vector of node*.
  vector<Node*> getChildren(){return children;}//Return the vector of node* of children.
private:
  char alphabet;//The char of the node.
  bool square;//The marker for the string existence.
  vector<Node*> children;// The vector of Node pointer of children.
};

Node* Node::findChildPtr(char c){
  //Iterate through the children vector.
  for(int i = 0; i < children.size(); ++i){
    Node* tmp = children.at(i);
    //examine if the char is equal to the alphabet of the node.
    if(c == children.at(i)->alphabet) return tmp;//return pointer of that node.
  }
  return NULL;//if not found, return NULL.
}
//**************************Trie.cpp************************************************************************
class Trie {
public:
    Trie();//Contructor.
    ~Trie();//Destructor.
    void insertString(string s);//Insert the string into the trie.
    bool searchString(string s);//Search for the string in the trie.
private:
    Node* root;// Node pointer to the root of the trie.
};

Trie::Trie(){
  root = new Node(); //Heap <- new node .
}

Trie::~Trie(){
  delete root; //delete heap use.
}

void Trie::insertString(string s){
  Node* current = root; //Set current = root.
  //Case 1: empty string case set root equals to square marker.
  if ( s.length() == 0 ){current->setSquare(); return;}

  for(int i = 0; i < s.length(); i++ ){
      Node* child = current->findChildPtr(s[i]);
      if (child != NULL) current = child;
      else{
          Node* tmp = new Node();//Heap <- make new node.
          tmp->setAlphabet(s[i]);//Set tmp node's alphabet to s[i].
          current->appendChild(tmp);//append tmp node to current.
          current = tmp; //move to next child follow the string order.
      }
      //set square when a string end.
      if (i == s.length() - 1) current->setSquare();
  }
  return;
}

bool Trie::searchString(string s)
{
    Node* current = root;// start from root.
    while ( current != NULL){//loop through the trie.
        for ( int i = 0; i < s.length(); i++){ //for i in s.length() - 1
            Node* tmp = current->findChildPtr(s[i]);// tmp node = next corresponding child.
            if( tmp == NULL ) return false;//There's nothing end with this as findChildPtr returned NULL.
            current = tmp; //current = corresponding child.
        }
        if ( current->getSquare()) return true; // found string that matches.
    }
    return false;
}
//**************************MAIN.cpp************************************************************************
int main(){
  Trie* myTrie = new Trie(); // Heap<- make new trie called myTrie.
  string word;
  int count = 0; // count of word without 'h' start.
  ifstream input("dictionary.txt");
  while(!input.eof()){
    getline(input, word);//no delimiting
    myTrie->insertString(word);//insert word into trie.
  }

  ifstream input2("BigData.txt");
  while (!input2.eof()){
      getline(input2, word);
      for (int i = 0; i < word.length(); i++){//start from beginning to find word.
          for (int j = 1; j < word.length() - i + 1; j++){
              string test = word.substr(i,j);//Create substring to test.
              bool check = myTrie->searchString(test);//Boolean to see if the tested string exist in trie.
              if (check == true && test[0] != 'h')count++; //if exist and not start with 'h', count++.
              else break;//else break from the innermost loop. and try for next substring.
          }
      }
  }
  cout << "Number of words not ending with 'h': " << count << endl;
  delete myTrie;
  return 0;
}
