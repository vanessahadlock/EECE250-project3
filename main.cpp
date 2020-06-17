//Main file for project 3
#include "wordlist.h"
#include "findMatches.h"
#include "grid.h"
#include "heap.h"
#include "search.h"
#include "hash.h"
using namespace std;

int main() {
	

	int algo;
  	cout << "Which algorithm would you like to use to search the worldlist? Please enter 1, 2, or 3 to choose:" << endl;  
  	cout << "#1 Insertion Sort "<< endl;
  	cout << "#2 Quick Sort "<< endl;
  	cout << "#3 Merge Sort "<< endl;
  	cin >> algo;
  
  	if (algo = 1 || algo = 2 || algo = 3) {
    		search(algo);
  	}
  	else { 
    		cout << "You have entered an invalid algorithm choice. Please try again." << endl;
  	}
}
