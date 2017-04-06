/*
Given a sorted array with "n" elements, distributed them into "k" nearly equally weighing buckets.

Space is not constraint.

Ex: [1,3,6,9,10]
bucket size: 3

output:[10],[9,1],[3,6]

*/
std::vector<std::vector<int> > kmeans(std::vector<int> & vec, int k)
{


    std::vector<std::vector<int> > result (k, std::vector<int> () );
    if(k == 1)
    {
       result.push_back(vec);
       return result;
    }
    int target = std::ceil(std::accumulate(vec.begin(), vec.end(), 0.0) / k );
    std::vector<bool> taken(vec.size(), false);

    for(int i = 0; i < k ; ++i)
    {
        for( size_t j = 0; j < vec.size() ; ++j)
        {
             if( !taken[j] )
             {
                 result[i].push_back(vec[j]);

                 if(std::accumulate(result[i].begin(), result[i].end(), 0)  > target)
                 {
                     result[i].pop_back();
                     break;
                 }
                 taken[j] = true;
             }
        }
    }

    for(auto& x: result)
    {
        for(auto& y : x)
        {
            std::cout << y;
        }
        std::cout << "\n";
    }
    return result;
}


int main()
{
    std::vector<int> vec = {1,3,6,9,10};
    kmeans(vec, 3);
    vec = {-1,1,1,1,8,10};
    kmeans(vec, 2);
}