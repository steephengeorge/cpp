/*You are given four integers: , , , . You will use them in order to create the sequence  with the following pseudo-code.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31)

Your task is to calculate the number of distinct integers in the sequence .

Input Format

Four space separated integers on a single line, , , , and  respectively.

Output Format

A single integer that denotes the number of distinct integers in the sequence .

Constraints




Sample Input

3 1 1 1
Sample Output

3
Explanation


Hence, there are  different integers in the sequence.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, s , p, q;
    std::cin >> n>>s>>p>>q;

    std::vector<int> vec(n);

    vec[0] = s & 2147483647;
    for( int i = 1; i <= n-1; ++i)
    {
        vec[i]= ((vec.at(i-1)*p)+q) & (2147483647);
    }
    auto it= std::unique(vec.begin(), vec.end());
    std::cout << std::distance(vec.begin(), it);
}