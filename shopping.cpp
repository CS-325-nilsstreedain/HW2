//
//  shopping.cpp
//  HW2
//
//  Created by Nils Streedain on 4/17/22.
//

#include <iostream>
#include <fstream>
#include <vector>

// Dynamic Programming Knapsack algorithm function
int dynamic(int W, int n, int *v, int *wt, std::vector<int> &list) {
	int K[n + 1][W + 1];

	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			// Dynamic base case
			if (i == 0 || w == 0)
				K[i][w] = 0;
			// Item k is too big to fit with cap W
			else if (wt[i - 1] > w)
				K[i][w] = K[i - 1][w];
			// Else, return larger subset containing or not containing item k
			else {
				int nCont = v[i - 1] + K[i - 1][w - wt[i - 1]];
				int nNot = K[i - 1][w];
				K[i][w] = (nCont > nNot) ? nCont : nNot;
			}
		}
	}
	
	int max = K[n][W];
	int k = n;

	for (int i = k; i > 0 && max > 0; i--) {
		if (max != K[i - 1][k]) {
			list . push_back(i);
			max -= v[i - 1];
			k -= wt[i - 1];
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
			int price[n];
			int weight[n];
			for (int j = 0; j < n; j++) {
				is >> price[j];
				is >> weight[j];
			}
			
			int maxPrice = 0;
			std::vector<int> list;
			is >> f;
			for (int j = 0; j < f; j++) {
				is >> m;
				maxPrice += dynamic(m, n, price, weight, list);
			}
			printf("Test Case %i\nTotal Price %i\n", i + 1, maxPrice);
			
			for (int j = 0; j < list.size(); j++) {
				std::cout << list[j] << " ";
			}
			
//			std::cout << j + 1 << ": ";
			std::cout << std::endl;
			
			
			
		}
		// Close file to end while loop
		is.close();
	}
}
