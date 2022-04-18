//
//  knapsack.cpp
//  HW2
//
//  Created by Nils Streedain on 4/12/22.
//

#include <iostream>

int recursive(int W, int n, int val[], int wt[]) {
	return 0;
}

int dynamic(int W, int n, int val[], int wt[]) {
	
	return 0;
}

int main(int argc, const char * argv[]) {
	srand((int)time(0));
	int W = 100;
	
	for (int n = 10; n <= 50; n += 5) {
		// Init val & weight arrays of size n
		int val[n];
		int wt[n];
		
		// Randomly populate val & weight arrays
		for (int i = 0; i < n; i++) {
			val[i] = rand() % 50;
			wt[i] = rand() % 50;
		}
		
		// Initilize clock vars
		clock_t rStart, rEnd, dpStart, dpEnd;
		
		// Recursive timing
		rStart = clock();
		recursive(W, n, val, wt);
		rEnd = clock();
		
		// Dynamic timing
		dpStart = clock();
		dynamic(W, n, val, wt);
		dpEnd = clock();
		
		// Output
		printf("N=%i\tW=%i\tRec time=%f\tDP time=%f\tmax Rec=%i\tmaxDP=%i\n", n, W, (double)(rEnd - rStart)/CLOCKS_PER_SEC, (double)(dpEnd - dpStart)/CLOCKS_PER_SEC, recursive(W, n, val, wt), dynamic(W, n, val, wt));
	}
}
