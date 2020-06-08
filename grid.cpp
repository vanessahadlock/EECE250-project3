//Grid Class file for Project 3
//Michael Gesuale, Jack Geisler, & Vanessa Hadlock
//June 4th, 2020

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

Grid::Grid() {

    ifstream inFile("input15.txt"); //opens the file of letters

    if (!inFile) {
    
        cout << "Unable to open file the letter text file";
        exit(1);   // call system to stop
    }

//    int sLine;

//    n >> sLine;

//    const size_t n = 15;         //set n equal to the dimensions of the matrix (grid) 
  
//    char grid[ n ][ n ] = {};    //create a matrix characters called grid of size n x n
    
    int column = 0;     //initialize column to 0 to start
    int row = 0;        //initialize row to 0 to start
  
    inFile >> column >> row;

    const int n = column; 

    char grid[ n ][ n ] = {};

    for(int column_counter = 1; column_counter < column; column_counter++) {

        for (int row_counter = 1; row_counter < row; row_counter++) {

            inFile >> grid[column_counter][row_counter];

        }
    }
  
    inFile.close();
  
    for(int i = 0; i < n; i++) {
      
        for(int j = 0; j < n; j++) {
          
        cout<< grid[i][j] << " ";
        
        }
        cout<<endl;
    }

    cout<<endl;

}
