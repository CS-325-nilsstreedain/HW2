//
//  knapsack.cpp
//  HW2
//
//  Created by Nils Streedain on 4/12/22.
//

#include <iostream>

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

int dynamic(int W, int n, int *val, int *wt) {
	int K[n + 1][W + 1];
	
	int i, j;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= W; j++) {
			if (i == 0 || j == 0)
				K[i][j] = 0;
			else if (wt[i - 1] > j)
				K[i][j] = K[i - 1][j];
			else {
				int nCont = val[i - 1] + K[i - 1][j - wt[i - 1]];
				int nNot = K[i - 1][j];
				K[i][j] = (nCont > nNot) ? nCont : nNot;
			}
		}
	}
	
	return K[n][W];
}

template<typename Function>
double timer(Function func, int *max, int W, int n, int *val, int *wt) {
	clock_t start, end;
	start = clock();
	*max = func(W, n, val, wt);
	end = clock();
	return (double)(end - start)/CLOCKS_PER_SEC;
}

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
		
		int rMax, dpMax;
		double rTime = timer(recursive, &rMax, W, n, val, wt);
		double dpTime = timer(dynamic, &dpMax, W, n, val, wt);
		
		// Output
		printf("N=%i\tW=%i\tRec time=%f\tDP time=%f\tmax Rec=%i\tmaxDP=%i\n", n, W, rTime, dpTime, rMax, dpMax);
	}
}
