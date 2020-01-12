/* Enter your macros here */

#define INF (100000000)
//#define INF (unsigned)!((int)0)
//#define FUNCTION(name, op) void  name( int x, int y) { if( y op x) x = y; }
#define FUNCTION(name,operator) inline void name(int &current, int candidate) {!(current operator candidate) ? current = candidate : false;}
#define io(v) std::cin >> v
#define toStr(x) ("Result =")
#define foreach(x, i) for (int i =0 ; i< x.size(); ++i)


