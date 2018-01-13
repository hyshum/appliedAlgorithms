//MyBloomFilter.cpp
#include <iostream>
#include <cmath>
#include "MyBloomFilter.h"

MyBloomFilter::MyBloomFilter(int len):BloomFilter(len){
  length = length * 8;
  my_array = new bool[length]; //Heap useage.
  //initialize them with 0.
  for(int i = 0; i < length; i++){
    my_array[i] = 0;
  }
}

string MyBloomFilter::output(){
  //char c[length]; // Initialize C-string.
  string c;
  for(int i = 0; i < length; i++){
    // input boolean value in each element with offset.
    //c[i] = my_array[i] + 48;
    c += my_array[i] + 48;
  }
  //string s(c); //put c-string into string.
  //return s;
  return c;
}

void MyBloomFilter::insert(string item){
  my_array[h1(item)] = 1;
  my_array[h2(item)] = 1;
  //cout << item << " hashed to " << h1(item) << " and " << h2(item) << endl;
  return;
}
//module of each char, multiply it by whatever and then do the weight sum and module again.

//Multiplicative hash function
unsigned MyBloomFilter::h1(string x){//Bernstein's hash function djb2
  int p = 37;//large prime.
  int a = 33;
  unsigned h = 5381; // initial.
  for(unsigned i = 0; i < x.length(); i++){
    h =  ((h*a) + x[i]) % p;
  }
  h = h % length;
  return h;
}
//Multiplicative hash function
unsigned MyBloomFilter::h2(string x){//java.lang.String.hashCode()
  int p = 19;//med prime.
  int a = 31;
  unsigned h = 0; // initial.
  for(unsigned i = 0; i < x.length(); i++){
    h =  ((h*a) + x[i]) % p;
  }
  h = h % length;
  return h;
}

bool MyBloomFilter::exists(string item){
  if(my_array[h1(item)] == 1){
    if(my_array[h2(item)] == 1){
      return true;
    }
  }
  return false;
}
