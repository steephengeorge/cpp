		/* Enter your code here */   
std::cout<<std::left;
std::cout<<std::nouppercase;
std::cout.setf ( std::ios::hex, std::ios::basefield );  // set hex as the basefield
std::cout.setf ( std::ios::showbase ); 
std::cout<<std::hex<<(long long)A<<"\n";
//std::cout<<std::setw(0xf)<<std::internal;
//std::cout.unsetf ( std::ios::uppercase );
std::cout<<std::right;
std::cout<<std::setw(15)<<std::setfill('_')<<std::setprecision(2)<<std::showpos<<std::fixed<<B<<"\n";
std::cout.unsetf (std::ios::showpos);
std::cout<<std::uppercase;
std::cout<<std::scientific<<std::setprecision(9)<<C<<"\n";




    