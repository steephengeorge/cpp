    int n, m;
    std::cin >> n >> m;
    int *vec[n];
    int num;
    int i = 0;
   
    while( n > 0){
        int cnt;
        int j = 0;
        std::cin>>cnt;
        vec[i] = new int[cnt];
        while(cnt > 0){
            std::cin >>  vec[i][j++];
            --cnt;
        }        
        ++i;
        --n;
    }
    while( m > 0){
        int l , k;
        std::cin >>l>>k;
        std::cout<<vec[l][k]<<"\n";
        --m;
    }
        
	return 0;
}
