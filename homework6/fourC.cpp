//Find the longest Palindrome
//Hok Yin Shum

//Algorithm referrenced:http://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string getLongest(string word){

  int low = 0;
  int high = 0;
  string current, longest;

  for (int key = 1; key < word.length() - 1; key++){
    //Find the odd longest Palindrome by fixing one key.
    low = key - 1;
    high = key + 1;
    while (low >= 0 && high < word.length()) {
      if (word[low] != word[high]) break;
      else{
        current = word.substr(low, high - low + 1);
        if(current.length() > longest.length()){
          longest = current;
        }
        //Expand in both directions.
        low--;
        high++;
      }
    }
    //Find the even longest Palindrome by fixing 2 keys on low&high.
    low = key - 1;
    high = key;
    while (low >= 0 && high < word.length()) {
      if (word[low] != word[high]) break;
      else{
        current = word.substr(low, high - low + 1);
        if(current.length() > longest.length()){
          longest = current;
        }
        //Expand in both directions.
        low--;
        high++;
      }
    }
  }
  return longest;
}

void fourC(){

  ifstream my_stream("BigData.txt");
  string superString;
  //while (!my_stream.eof())
  //{
  getline(my_stream,superString);
  string longest = getLongest(superString);
  cout << longest << endl;
  //superString = " ";
  //}

}

int main(){
  fourC();
  return 0;
}
