//
//  Problem5.cpp
//  Problem5
//  Collaborator: HuaBin Liu
//  Created by Hok Yin Shum on 9/18/17.
//  Copyright © 2017 Hok Yin Shum. All rights reserved.
// U77071350

/*
 Algorithm:
 1.Declare a 2d vector of type char with the number of rows and columns equal to the grid size.
 2.Initialize the vectors with  underscore.
 3.Assume coordinate (0,0) on bottom left.
 4. For i = 0, i <= N, ++i, insert X on (i,i) and insert X on (i, i + 1). Do this for all N+1 the columns.
 5. if N is an even number, then place an o on (N+1 ,N+1).
 6. if N is an odd number, place 2 o. First on (N + 2, N). Second on ( N +2, N + 2).
 */

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    //initialize 2d vector.
    int number_of_columns = 10;
    int number_of_rows = 10;
    char initial_value = '_';
    
    std::vector<std::vector<char>> matrix;
    matrix.resize(number_of_rows, std::vector<char>(number_of_columns, initial_value));
    
    //Setting up the coodinates.
    int x_zero = 0;
    int y_zero = number_of_rows - 1;
   
    //confusing implementation rule:
    //use (y,x) Flipped order in the coordinates for matrix indexing.
    //use - for + operation in vertical (y)
    //use + for + operation in horizontal (x)
    //matrix[y_zero][x_zero] = 'x';
    
    cout << "Please enter N, an integer.Acceptable range is[0,7]: ";
    int N = 0;
    cin >> N;
    
    //Step 4. For i = 0, i <= N, ++i, insert X on (i,i) and insert X on (i, i + 1).
    for(int i = 0; i <= N; ++i)
    {
        matrix[y_zero - i][x_zero + i] = 'X';
        matrix[y_zero - i -1][x_zero + i] = 'X';
    }
    
    //Step 5.if N is an even number, then place an o on (N+1 ,N+1).
    if(N%2 == 0) matrix[y_zero - N - 1][x_zero + N + 1] = 'O';
   
    //Step 6. if N is an odd number, place 2 o. First on (N + 2, N). Second on ( N +2, N + 2).
    if(N%2 == 1){
        matrix[y_zero - N][x_zero + N + 2] = 'O';
        matrix[y_zero - N - 2][x_zero  + N +2] = 'O';
    }

    //Display the grid.
    for(int i = 0; i<number_of_rows; i++) {
        for(int j = 0; j<number_of_columns; j++) {
            cout  << matrix[i][j];
        }
        cout << endl;
    }
    
    
    return 0;
}
