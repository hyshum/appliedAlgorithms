// main.cpp
//EC330_HW4_Question6
//MissingNum
//Hok Yin Shum
//U77071350
//Collaborator: HuaBin Liu
// vherzog@bu.edu Veronica. TA
/*
1. Get the sum of numbers
     total = n*(n+1)/2
2  Subtract all the numbers from sum and
 you will get the missing number.
 Runtime: O(nlogn)
 n from the outermost for loop
 log n from the bit comparisions, assume it goes beyond 32 bits, its just n = 2^k - 1,
 and the number of bits comparision scale in logn.
*/
#include <iostream>
#include <cmath>
#include "InputArray.h"

using namespace std;

//missNum function.
int main(){
  InputArray A;
  int predicted_sum = A.n * (A.n + 1) / 2 ;
  int sum = 0;

  for(int i = 0; i < A.n; ++i ){
    int temp = 0;
    //find A[i].
    for(int j = 0; j < 32; ++j){
      if(A.findBit(i,j)){
        temp = temp + pow(2,j);
      }
    }
    sum = sum + temp; //
  }
  cout << predicted_sum - sum;
  return 0;
}
