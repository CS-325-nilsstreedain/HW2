//
//  knapsack.cpp
//  HW2
//
//  Created by Nils Streedain on 4/12/22.
//

#include <iostream>

// Recursive Knapsack algorithm function
int recursive(int W, int n, int val[], int wt[]) {
	// Recursive base case
	if (W == 0 || n ==0)
		return 0;
	
	// Item k is too big to fit with cap W
	if (wt[n - 1] > W)
		return recursive(W, n - 1, val, wt);
	// Else, return larger subset containing or not containing item k
	else {
		int nCont = val[n - 1] + recursive(W - wt[n - 1], n - 1, val, wt);
		int nNot = recursive(W, n - 1, val, wt);
		return (nCont > nNot) ? nCont : nNot;
	}
}

// Dynamic Programming Knapsack algorithm function
int dynamic(int W, int n, int *val, int *wt) {
	int V[n + 1][W + 1];

	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			// Dynamic base case
			if (i == 0 || w == 0)
				V[i][w] = 0;
			// Item k is too big to fit with cap W
			else if (wt[i - 1] > w)
				V[i][w] = V[i - 1][w];
			// Else, return larger subset containing or not containing item k
			else {
				int nCont = val[i - 1] + V[i - 1][w - wt[i - 1]];
				int nNot = V[i - 1][w];
				V[i][w] = (nCont > nNot) ? nCont : nNot;
			}
		}
	}
	
	return V[n][W];
}

// Function to time various Knapsack algorithms
template<typename Function>
double timer(Function func, int *max, int W, int n, int *val, int *wt) {
	clock_t start, end;
	start = clock();
	*max = func(W, n, val, wt);
	end = clock();
	return (double)(end - start)/CLOCKS_PER_SEC;
}

// Main driver knapsack fucntion
int main(int argc, const char * argv[]) {
	srand((int)time(0));
	
	//Initalize general vars
	int W = 100;
	
	for (int n = 0; n <= 50; n += 1) {
		// Init val & weight arrays of size n
		int val[n];
		int wt[n];
		
		// Randomly populate val & weight arrays
		for (int i = 0; i < n; i++) {
			val[i] = rand() % 50;
			wt[i] = rand() % 50;
		}
		
		// Time each knapsack algorithm and store results
		int rMax, dpMax;
		double rTime = timer(recursive, &rMax, W, n, val, wt);
		double dpTime = timer(dynamic, &dpMax, W, n, val, wt);
		
		// Output
		printf("N=%i\tW=%i\tRec time=%f\tDP time=%f\tmax Rec=%i\tmaxDP=%i\n", n, W, rTime, dpTime, rMax, dpMax);
	}
}
