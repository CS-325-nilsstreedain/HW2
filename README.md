# Homework 2
## Problem 1: (15 points) 0-1 Knapsack: Recursive vs DP
Given weights and values of n items, select items to place in a knapsack of capacity W to maximize the total value in the knapsack. That is, given two integer arrays val[] and wt[ ] which represent values and weights associated with n items respectively and an integer W which represents knapsack capacity, determine the maximum value subset of val[] such that sum of the weights of this subset is ≤ W. Items cannot be broken or used more than once, you either select the complete item, or don’t select it. Implement both a recursive and dynamic programming algorithm to solve the 0-1 knapsack problem. Both algorithms should return the maximum total value of items that can fit in the knapsack.

1. Implement both the recursive and dynamic programming algorithm in one program named knapsack (.cpp, .c or .py). Your program should randomly generate test cases that are solved using both the DP and Recursive algorithm. The program should output to the terminal: n, W, time for the DP algorithm, max for the DP, time for the Recursive algorithm, max for Recursive. The max values should be the same. Sample output is below
<img width="742" alt="Screen Shot 2022-04-12 at 1 13 21 PM" src="https://user-images.githubusercontent.com/25465133/163045740-c16210ae-1cc9-480d-8395-2b7cfdeefebd.png">

2. Conduct experiments to collect running times for randomly generated input.  Since there are two variables, n and W, you can hold W constant while varying the value of n.  If the recursive algorithm is too slow you can use different values of n for each algorithm.

3. Plot the data, calculate the best fit equation and graph the best fit curves.   

## Problem 2:  Shopping Spree:  (15 points)
Acme Super Store is having a contest to give away shopping sprees to lucky families. If a family wins a shopping spree each person in the family can take any items in the store that he or she can carry out, however each person can only take one of each type of item. For example, one family member can take one television, one watch and one toaster, while another family member can take one television, one camera and one pair of shoes. Each item has a price (in dollars) and a weight (in pounds) and each person in the family has a limit in the total weight they can carry. Two people cannot work together to carry an item. Your job is to help the families select items for each person to carry to maximize the total price of all items the family takes.  Write a **dynamic programming** algorithm to determine the maximum total price of items for each family and the items that each family member should select.

1. Give a written description and pseudo-code for your algorithm.  Try to create an algorithm that is efficient in both time and storage requirements.

2. Implement your algorithm by writing a program named “**shopping**” (in C, C++ or Python) that compiles and runs on the OSU engineering servers.   The program should satisfy the specifications below.

**Input**: The input file named “**shopping.txt**” consists of T test cases
- T  (1 ≤ T ≤ 100) is given on the first line of the input file.
- Each test case begins with a line containing a single integer number N that indicates the number of items (1 ≤ N ≤ 100) in that test case.
- Followed by N lines, each containing two integers: P and W. The first integer (1 ≤ P ≤ 5000) corresponds to the price of object and the second integer (1 ≤ W ≤ 100) corresponds to the weight of object.
- The next line contains one integer (1 ≤ F ≤ 30) which is the number of people in that family.
- The next F lines contains the maximum weight (1 ≤ M ≤ 200) that can be carried by the ith person in the family (1 ≤ i ≤ F).

**Output**: Printed to the terminal.  For each test case your program should output the maximum total price of all goods that the family can carry out during their shopping spree and for each the family member, numbered 1 ≤ i ≤ F,  list the item numbers 1 ≤ N ≤ 100 that they should select.

**Sample Input**
```
2
3
72 17
44 23
31 24
1
26
6
64 26
85 22
52 4
99 18
39 13
54 9
4
23
20
20
36
```

**Sample Output**:
```
Test Case 1
Total Price 72
 1:    1
Test Case 2
Total Price 568
  1:    3 4
  2:    3 6
  3:    3 6
  4:    3 4 6
```

*Note: You will not be collecting experimental running rimes for the Shopping Spree problem.*

**Submit the write up to Canvas.**

**Submit to [TEACH](https://teach.engr.oregonstate.edu/teach.php?type=assignment) a .zip file containing your code files for problems 1 & 2. The .zip file should contain**
- knapsack.**
- shopping.**
- shopping.txt
- HW2Solution.txt
- HW2.sh
