//
//  MyBloomFilter.h
//  MyBloomFilter
//
// Created by Hok Yin Shum
// Collaborated with

#ifndef MyBloomFilter_h
#define MyBloomFilter_h

#include <string>
#include "BloomFilter.h"

using namespace std;

class MyBloomFilter: public BloomFilter {
public:
  MyBloomFilter(int len);
  string output();
  void insert(string item);
  bool exists(string item);
private:
  bool* my_array; // pointer to a bool array
  unsigned h1(string x);
  unsigned h2(string x);
};

#endif /* MyBloomFilter_h */
