class Matrix{
  
  //int col, row;
  public:
  std::vector<std::vector<int> > a ;  
  //Matrix( int r, int c){
    //  col = c;
      //row = r; 
      
  //}
  Matrix() {}
  ~Matrix() {}
    
  Matrix operator +(Matrix & second ){
    
      Matrix result;
      for( int i =0 ; i < this->a.size(); ++i)
      {
          std::vector<int> b;
          for( int j =0; j < this->a[0].size(); ++j)
          {
              b.push_back(this->a[i][j] + second.a[i][j]);
          }
          result.a.push_back(b);
      }
      return result;
  }
};