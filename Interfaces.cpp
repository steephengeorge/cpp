//Write your code here
class Calculator: public AdvancedArithmetic{
    int divisorSum(int n){
        int i = 1;
        int sum = 0;
        while( i <= n/2){
            if( n % i == 0 )
                sum += i;   
            ++i;
        }
        return (sum+n);
    }
};