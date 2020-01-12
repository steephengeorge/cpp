#include <iostream>
#include <deque> 
using namespace std;
void printKMax(int arr[], int n, int k){
   //Write your code here.
   std::deque<int> de(k);
   int i;
   for( i =0; i < k; ++i){
      while( !de.empty() && arr[de.back()] <= arr[i]){          
              de.pop_back();
      }
      de.push_back(i);       
   }
   for( ; i < n; ++i){
       std::cout<< arr[de.front()] <<" ";
       
       while( !de.empty()&& arr[de.back()] <= arr[i]){         
              de.pop_back();      
       }
       while( !de.empty()&& de.front() <= i - k){
          de.pop_front();
       }      
       
              
      de.push_back(i);          
   }
   std::cout<< arr[de.front()] <<"\n";
   
   
}
int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
