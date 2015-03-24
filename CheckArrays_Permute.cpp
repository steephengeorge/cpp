#include<iostream>
#include<set>
#include<algorithm>

       
bool ArraysPermute(int  array1[],int size1, int  array2[], int size2)
{       
       if( size1  != size2)           
           return false;
       else
       {        
           std::set<int> first_set(array1, array1+size1);
           std::set<int> second_set(array2, array2+size2);
       
           std::pair<std::set<int>::iterator,std::set<int>::iterator> myPair=std::mismatch(first_set.begin(),first_set.end(),second_set.begin());
          
           if( *myPair.first != *myPair.second)
                
                return false;
            else
                return true;
       }
}


int main()
{     
    int array1[] ={1,2,3,5};
    int array2[]={1,2,4,3};
    
    if(ArraysPermute(array1,sizeof(array1)/sizeof(int), array2, sizeof(array2)/sizeof(int)))
        std::cout<< " Arrays are permutation of each other\n"; 
    else
        std::cout<< " Arrays are not permutation of each other\n";
       
    return 0;
}
