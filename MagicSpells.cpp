  /* Enter your code here */
   if( Fireball* fire = dynamic_cast<Fireball*> (spell) ){
       fire->revealFirepower();           
   }else if( Frostbite* frost = dynamic_cast<Frostbite*> (spell)){
       frost->revealFrostpower();
   }else if( Thunderstorm* thunder = dynamic_cast<Thunderstorm*> (spell)){
       thunder->revealThunderpower();
   }else if( Waterbolt* water = dynamic_cast<Waterbolt*> (spell)){
       water->revealWaterpower();
   }
   else{
       int result=0;
      
       std::string scroll = spell->revealScrollName();
       size_t start = 0;
       
       for ( ; start < scroll.length() && start < SpellJournal::journal.length() && 
                                          scroll[start] == SpellJournal::journal[start]; ++start, ++result);
      
       size_t f_end = scroll.length()-1;
       size_t l_end = SpellJournal::journal.length()-1;       
       for ( ; start<= f_end && start <= l_end &&  scroll[f_end] == SpellJournal::journal[l_end]; 
                                                       --f_end, --l_end, ++result );
       
      // std::cout << result;
       int rows = scroll.length() - result+1;
       int cols = SpellJournal::journal.length()- result+1;
       int c [ rows][cols];
       
       
       for( int i = 0; i < rows; ++i ){         
               c[i] [0]  = 0;           
       }
       for(int j = 0; j < cols; ++j){
           c[0][j] =0;
       }
       //std::cout << start;
       for( int i = 1; i < rows; ++i ){
           for(int j = 1; j < cols; ++j){
               
               if( scroll[start+i-1] == SpellJournal::journal[start+j-1]){
                   c[i][j] = c[i-1][j-1]+1;                   
               }
               else{
                   c[i][j] = std::max( c[i-1][ j], c[i] [j-1]);
               }
           }
       }
       
       
     //std::cout << result <<"\n";
      
      std::cout << c[rows-1] [cols-1] + result <<"\n";
   }
   
       
    