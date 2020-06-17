//Include global function search(int) and main function

#include "wordlist.h"
#include "findMatches.h"
#include "grid.h"
#include <bits/stdc++.h>
using namespace std;
 
/* Global function search(int algo) which reads the name of the grid file from the keyboard based on user input
 * and calls findMatches(wordlist, grid) to print out all words from the word list that can be found in the grid.
 * The function also prints out the CPU time to sort the words, the CPU time to find the words, and the total
 * time to run the program. The integer parameter is used to select the sorting algorithm that is ran.
 *  
 * @param       int algo - the choice of algorithm to use, chosen by the user
 * @return      none
 */	
 
void search(int algo) { 
  
  clock_t start, end;
  
  //Recording the starting tick of running the whole program
  start = clock(); 
    
    //declaring variables for number of rows, columns, default character g for the initialization of the matrix,
    //and the file name pointer 
    int numRow;
    char * fileName;
    int numCol;
    char g;

    cout << "What is the name of the file you would like to use? Please use the .txt extension" << endl;
    cin >> fileName;
    cout << "How many rows are in this grid?" << endl;
    cin >> numRow;
    cout << "How many columns are in this grid?" << endl;
    cin >> numCol;
    
    //initialization of the Grid using the first constructor
    Grid A(numRow, numCol, g);
    int row = A.getRows();

    //using the text file to fill in the Grid by calling the second constructor
    Grid X(fileName);
    
    //prints out the grid matrix you just created
    X.printGrid(numCol, numRow);
 
 /* clock_t clock(void) returns the number of clock ticks elapsed since the program was launched. To get the number  
    of seconds used by the CPU, you will need to divide by CLOCKS_PER_SEC, where CLOCKS_PER_SEC is 1000000 on typical 
    32 bit system.
  */
 
  clock_t sortStart, sortEnd, searchStart, searchEnd;
 

  //Wordlist object 
   Wordlist wordlist; 
 
   //read through file and insert words into the wordlist vector
   wordlist.get_words();
  
  //if the user chose to use algorithm 1, then run the insertion_sort() function on the Wordlist 
  if (algo = 1) { 
      
    //Recording the starting clock tick for the insertion sort algorithm
    sortStart = clock(); 
    
    wordlist.insertion_sort();
    
    //Recording the end clock tick  
    sortEnd = clock(); 
  }
  //if the user chose to use algorithm 2, then run the quick_sort() function on the Wordlist 
  else if (algo = 2) { 

    //Recording the starting clock tick for the insertion sort algorithm
    sortStart = clock(); 
    
    wordlist.quick_sort(vector<string> vec, int low, int high);
    
    //Recording the end clock tick  
    sortEnd = clock(); 
  }
  //if the user chose to use algorithm 3, then run the merge_sort() function on the Wordlist 
  else {

    //Recording the starting clock tick for the insertion sort algorithm
    sortStart = clock(); 
    
    wordlist.merge_sort(vector<string> vec, int low, int mid, int high);
  
    //Recording the end clock tick  
    sortEnd = clock(); 
  }
  
  //Recording the starting clock tick for the findMatches() algorithm to search for the matching words in the grid
  searchStart = clock(); 
  
 
  int result = wordlist.lookup();
	 if (result == -1){
      cout << ("Element not present");
	 }
	 else {
		    cout << ("Element found at index ") << result;
	 }
 
  //prints out all words from the word list that can be found in the grid
  findMatches(wordlist, Grid X(fileName));
  
  //Recording the ending clock tick
  searchEnd = clock(); 
  
  //Recording the ending tick of running the whole program
  end = clock();
  
  // Calculating total time taken by the program to sort 
  double sortTime = double(Sortend - Sortstart) / double(CLOCKS_PER_SEC); 
  
  // Calculating total time taken by the program to search 
  double searchTime = double(searchEnd - searchStart) / double(CLOCKS_PER_SEC);
  
  //Calculating the total time of the whole program
  double totalTime = double(end - start) / double(CLOCKS_PER_SEC); 
    
  cout << "CPU Time to Sort the Words: " << sortTime << setprecision(5) << " sec " << endl;
  cout << "CPU Time to Find the Words: " << searchTime << setprecision(5) << " sec " << endl;
  cout << "The Total Time is: " << totalTime << setprecision(5) << " sec " << endl;
  
}
