/*
 * Complete the function below.
 */
int findMinGates(vector < int > arrivals, vector < int > departures, int flights) {
    std::vector<std::pair<int,int>>gates;
    gates.push_back(std::pair<int,int>(arrivals[0],departures[0]));

    for(int i = 1 ; i < flights; ++i)
    {
        bool toggle = false;
        for(std::pair<int,int>& x: gates)
        {
           // std::cout << x.first <<"Second " << x.second << "\n";
            //std::cout << arrivals[i] << "second " << departures[i]<<"\n";
            if( x.first < arrivals[i] && x.second < departures[i] && x.second < arrivals[i] )
            {
                //std::cout <<"updated \n";
                x.first = arrivals[i];
                x.second = departures[i];
                toggle = true;
                break;
            }
        }
        if(toggle == false)
        {
            gates.push_back(std::pair<int,int>(arrivals[i],departures[i]));
        }
    }
    return gates.size();


}
