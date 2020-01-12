	// Add your code here
    Difference(std::vector<int>& a){
       std::copy(a.begin(),a.end(),std::back_inserter(elements));   
    }
    void computeDifference(){
        int min = *std::min_element(elements.begin(), elements.end());
        int max = *std::max_element(elements.begin(), elements.end());
        maximumDifference = max - min;
    }