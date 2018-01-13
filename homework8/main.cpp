//Hok Yin Shum
//ref: http://www.geeksforgeeks.org/printing-longest-common-subsequence/
//Collaborator:  HuaBin Liu

#include <iostream>
#include <string>

using namespace std;

// Given two sequences A and B, finds the longest sequence C such that
// C is a subsequence (not necessarily contiguous) of both A and B
string findMaxSubSeq(string str1, string str2)
{
	// the maximum common subsequence
	string subseq = "TestSubsequence";

	int size1 = str1.length();
	int size2 = str2.length();
	int table[size1+1][size2+1];
	//Table: bottom up, contains length of LCS
	//of str1[0 to i-1] and str2[0 to j -1].
//i = row. j = column.
	for (int i=0; i<=size1; i++){
	  for (int j=0; j<=size2; j++){
	    if (i == 0 || j == 0) table[i][j] = 0; // Initialize first row and column cells all to ZERO.
			//Case 1: chars equal, increment top left diagonal cell for cell value.
	    else if (str1[i-1] == str2[j-1]) table[i][j] = table[i-1][j-1] + 1;
			//Case 2: Chars don't equal, take max of top and left cell.
	    else table[i][j] = max(table[i-1][j], table[i][j-1]);
	  }
	}

	//Construction of LCS string for return.
	int index = table[size1][size2];
	char LCS[index+1];
	LCS[index] = '\0';
	int i = size1, j = size2;

	while (i > 0 && j > 0){//until the boarder is reached.
		 if (str1[i-1] == str2[j-1]){LCS[index-1] = str1[i-1];index--; j--; i--;} // not from the max function, move diagonally up.
		 else if (table[i-1][j] > table[i][j-1]) i--; //from max and left cell, move left.
		 else j--; //from top cell, move to top cell.
	}
	subseq = LCS;
	return subseq;
}

// (sample) main to test findMaxSubSeq
// The actual test cases may be different, this file is for demonstration of format only
int main(int argc, char const *argv[])
{
	// example sequences A, B
	string a; //= "dynamic";
	string b;// = "programming";

	if( argc == 3 ){a = argv[1]; b = argv[2];}
	// maximum subsequence in example sequences
	string maxSubSeq = findMaxSubSeq(a, b);

	cout << "Maximum common subsequence for " << a << " and " << b << " : " << maxSubSeq << endl;

	return 0;
}
