// Add your code here
template<typename T>
void printArray(std::vector<T> vec)
{
    for( auto& x : vec){
        std::cout << x<<"\n";
    }
}