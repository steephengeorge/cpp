/*
There are two kangaroos on an x-axis ready to jump in the positive direction (i.e, toward positive infinity). The first kangaroo starts at location x1  and moves at a rate of v1 meters per jump. The second kangaroo starts at location x2  and moves at a rate of v2 meters per jump. Given the starting locations and movement rates for each kangaroo, can you determine if they'll ever land at the same location at the same time?

Input Format

A single line of four space-separated integers denoting the respective values of , , , and .

Constraints
0 <= x1 < x2 <= 10000
1 <= v1 <= 10000
1 <= v2 <= 10000

Output Format

Print YES if they can land on the same location at the same time; otherwise, print NO.

Note: The two kangaroos must land at the same location after making the same number of jumps.

Sample Input 0

0 3 4 2
Sample Output 0

YES
Explanation 0

The two kangaroos jump through the following sequence of locations:

Thus, the kangaroos meet after  jumps and we print YES.

Sample Input 1

0 2 5 3
Sample Output 1

NO
Explanation 1

The second kangaroo has a starting location that is ahead (further to the right) of the first kangaroo's starting location (i.e., ). Because the second kangaroo moves at a faster rate (meaning ) and is already ahead of the first kangaroo, the first kangaroo will never be able to catch up. Thus, we print NO.
*/

int main(){
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;

     if( ( x1 < x2  && v1 < v2 ) || (x1 > x2) && (v1 > v2) )
     {
         std::cout<<"NO";
     }else if( x1 == x2 && v1 != v2){
         std::cout<<"NO";
     }
     else if( v1 ==v2 && x1 != x2){
        std::cout<<"NO";
     }
     else if( std::abs(v1 -v2) != 0 && std::abs(x2 -x1) % std::abs(v1 -v2) == 0  )
     {
         std::cout << "YES";
     }
     else if( std::abs(x2 -x1) != 0 && std::abs(v1 -v2) % std::abs(x2 -x1)  == 0 )
     {
            std::cout << "YES";
     }
     else
     {
            std::cout<< "NO";
     }
}