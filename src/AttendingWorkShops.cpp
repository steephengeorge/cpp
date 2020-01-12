
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop{
    int start_time;
    int end_time;
    int duration;
};

struct Available_Workshops {
    int n;
    std::vector<Workshop> aw; 
};

Available_Workshops * initialize (int start_time[], int duration[], int n) {
  Available_Workshops  *a = new Available_Workshops;
  a->n = n;
  a->aw.reserve(n);
  
  for( int i = 0 ; i < n; ++i){     
      a->aw[i].start_time = start_time[i];
      a->aw[i].duration = duration[i];
      a->aw[i].end_time = start_time[i] + duration[i];
  }
  return a;
}
struct val{
bool operator()(const Workshop& a, const Workshop& b)const{ 
    return  a.end_time <= b.end_time ;     
}
};

int CalculateMaxWorkshops(Available_Workshops * ptr) {
    int cnt = 1;  
    std::set< Workshop, val> mySet;
    
    for(int i = 0; i < ptr->n; ++i){             
           mySet.insert(ptr->aw[i] );
    }
       
    int last = mySet.begin()->end_time;      
    for(auto i = ++(mySet.begin()); i != mySet.end(); ++i){  
       
        if( i->start_time >=  last )
        {
          ++cnt;
          last = i->end_time;  
        }
    }
    //ptr->aw.clear();
    delete ptr;
    return cnt;
}