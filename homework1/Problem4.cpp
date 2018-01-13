//
//  Problem4.cpp
//  Problem4
//
//  Created by Hok Yin Shum on 9/18/17.
//  Copyright © 2017 Hok Yin Shum. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ifstream inFS;
    vector<string> myStringList;
    
    inFS.open(argv[1]); // Open file.
    if (!inFS.is_open()) {
        cout << "Could not open the following file: " << argv[1] << endl;
        return 1; // Error.
    }
    
    while (!inFS.eof()){
        string tmpString;
        getline(inFS,tmpString);
        myStringList.push_back(tmpString);
    }
    
    inFS.close();
    
    // Output the longest line, the first.
    int index_Longest = 0;
    int size_Longest = 0;
    for(int i = 0; i < myStringList.size(); ++i){
        if(myStringList.at(i).size() > size_Longest){
            index_Longest = i;
            size_Longest = myStringList.at(i).size();
        }
    }
    
    cout << myStringList.at(index_Longest) << endl;
    return 0;
}
