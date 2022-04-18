//
//  shopping.cpp
//  HW2
//
//  Created by Nils Streedain on 4/17/22.
//

#include <iostream>
#include <fstream>

// Dynamic Programming Knapsack algorithm function
int dynamic(int W, int n, int *val, int *wt) {
	int K[n + 1][W + 1];
	
	int i, j;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= W; j++) {
			// Dynamic base case
			if (i == 0 || j == 0)
				K[i][j] = 0;
			// Item k is too big to fit with cap W
			else if (wt[i - 1] > j)
				K[i][j] = K[i - 1][j];
			// Else, return larger subset containing or not containing item k
			else {
				int nCont = val[i - 1] + K[i - 1][j - wt[i - 1]];
				int nNot = K[i - 1][j];
				K[i][j] = (nCont > nNot) ? nCont : nNot;
			}
		}
	}
	
	return K[n][W];
}

int main(int argc, const char * argv[]) {
	// Create input stream from file
	std::ifstream is("shopping.txt");
	
	// Loop while file stream is open
	while (is.is_open()) {
		std::string currLine;
	
		int t, n, f, m;
		is >> t;
		
		for (int i = 0; i < t; i++) {
			is >> n;
			int price[n - 1];
			int weight[n - 1];
			for (int j = 0; j < n; j++) {
				is >> price[j];
				is >> weight[j];
			}
			
			int maxPrice = 0;
			is >> f;
			for (int i = 0; i < f; i++) {
				is >> m;
				maxPrice += dynamic(m, n, price, weight);
			}
			
			printf("Test Case %i\nTotal Price %i\n", i + 1, maxPrice);
			
			
			
			
			
			
		}
		// Close file to end while loop
		is.close();
	}
}
