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
				int nCont = v[i - 1] + V[i - 1][w - wt[i - 1]];
				int nNot = V[i - 1][w];
				V[i][w] = (nCont > nNot) ? nCont : nNot;
			}
		}
	}
	
	int k = W;
	int max = V[n][W]; //maximal value of items that can be placed in the Knapsack

	// Find actual items
	for (int i = n; i > 0 && max > 0; i--) {
		if (max != V[i - 1][k]) {
			list.push_back(i);
			max -= v[i - 1];
			k -= wt[i - 1];
		}
	}
	return V[n][W];
}

int main(int argc, const char * argv[]) {
	// Create input stream from file
	std::ifstream is("shopping.txt");
	
	// Loop while file stream is open
	while (is.is_open()) {
		std::string currLine;
	
		int t, n, f, m;
		is >> t;
		
		// Loop for each test case
		for (int i = 0; i < t; i++) {
			// Find num items and init arrays
			is >> n;
			int price[n];
			int weight[n];
			
			// Store prices and weights
			for (int j = 0; j < n; j++) {
				is >> price[j];
				is >> weight[j];
			}
			
			// Create 2D vector to store list of items for each family member
			std::vector<std::vector<int>> list;
			int totalPrice = 0;
			
			// Loop over each family member
			is >> f;
			for (int j = 0; j < f; j++) {
				is >> m;
				
				// Create item list for each memeber & find total price
				std::vector<int> curr;
				totalPrice += dynamic(m, n, price, weight, curr);
				list.push_back(curr);
			}
			
			// Print full case output
			printf("Test Case %i\nTotal Price %i\n", i + 1, totalPrice);
			for (int j = 0; j < list.size(); j++) {
				printf("%i: ", j + 1);
				for(std::vector<int>::reverse_iterator it = list[j].rbegin(); it != list[j].rend(); ++it)
					printf("%i ", *it);
				printf("\n");
			}
			printf("\n");
		}
		// Close file to end while loop
		is.close();
	}
}
