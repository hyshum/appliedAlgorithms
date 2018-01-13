/*
  Hok Yin Shum U77071350.
  HWK2_
  Problem3.cpp
  Collaborator: Huabin Liu
 */
#include <iostream>
#include <vector>
#include "Problem3.h"
using namespace std;
/*
 Explanation of Algo. 
 Theres a LIS ending at each index i of D[i] of 2D vector D. Looping through i for the length of the array, we initialize each element D[i] = num[i].
 Then with a nested for loop, we loop through each of the previous subvector D[j] before the selected D[i]
 If the D[j]'s last element is smaller than the initial value num[i], then we store D[j] at a temp vector of int. We push_back() it with the initial value num[i].
 Comparing the size of temp with D[i], if temp is longer, D[i] becomes temp.
 Else if length of temp is same as D[i], we compare the sum of temp with D[i] sum.
 If temp sum > D[i] sum , then D[i] = temp. 

After this forfor loop, we just compare each D[i] by length , and output the longest D[i] and its length.Again, if lengths conincide, we consider the sum that is the largest and output that one.  
 */

void MaxIncSeq(int *nums, int len) {
    vector<vector<int> > D;
    vector<int > temp;
    int index, temp_sum = 0, D_sum = 0;
    //Loop through the nums array.
    for(int i=0; i<len; i++) {
        D.push_back({nums[i]}); // Initiatize the 2D vector. Initialize Each row ,D[i], with 1 element, nums[i].
        for(int j=i-1; j>=0; j--) { // Loop through all previous rows of D[i]
            if(D.at(j).back() < nums[i]) { // if the biggest element of the selected row j is smaller than the nums[i].
                temp = D.at(j); //then, initialize a temporary object to hold that selected row j.
                temp.push_back(nums[i]); // then, append num[i] to that selected row temporarily stored in the object.
                if(temp.size() > D.at(i).size()) D.at(i) = temp; // if the size of temp > size of D[i], then D[i] = temp.
                // This is for the 1, 3, 4 case. Without this block, the code would be 1, 2, 4. Examine the sum.
                if(temp.size() == D.at(i).size()) { // if temp size = D[i] size, then compare sum of temp and D[i].
                    for(int k=0; k<temp.size(); k++) {
                        temp_sum += temp.at(k);
                        D_sum += D.at(i).at(k);
                    }
                    if(temp_sum > D_sum) D.at(i) = temp; // if temp sum > D[i] sum, then D[i] = temp. Change 1,2,4 to 1,3,4.
                }
            }
        }
    }
    //Find index of the LIS  length.
    index = 0;
    temp_sum = 0; //reused for at[i]
    D_sum = 0;//reused for at[index]
    for(int i=1; i < len; i++) {
        if(D.at(i).size() > D.at(index).size()) index = i;
	if(D.at(i).size() == D.at(index).size()) { //same logic as above to compare sum when lengths conicide. and only act when sum is greater. 
	    for(int j = 0; j < D.at(index).size(); ++j){
	      temp_sum += D.at(i).at(j);
	      D_sum += D.at(index).at(j);
	    }
	    if(temp_sum > D_sum) index = i;
	}
    }
    //COUT the LIS.
    for(int i=0; i < D.at(index).size(); i++)cout << D.at(index).at(i) << ' ';
    cout << endl << "The length is: " << D.at(index).size() << endl;
    return;
}


