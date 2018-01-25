# Improve the prefroamnce of program #
**program output before changes**

Measure_AddBlocks took: 1751ms.
Measure_FindBlocksByAttribute took: 3268ms.

**program output after changes**

Measure_AddBlocks took: 306ms.
Measure_FindBlocksByAttribute took: 522ms.

**Compiler and options used**

g++ -std=c++14 -O3 -Wall -pedantic main.cpp && ./a.out


**Brief description of changes**

1. Replace std::list<> with std::vector<>. This change will help  to avoid cache missing so we will get better performance
2. Introduce a  static const int variable to set the capacity of std::vector<> holding Blocks to avoid continous reallocations of conatiner
3. Implemented const correctness in multiple lines of code
4. Passing arguements as reference instead value in multiple functions
5. Function Graph::GetBlocksWithAttribute is  rewritten idiomatically using lamdas and STL algorithms
6. Function Graph::BlockNameExistsInGraph is rewritten idomatically using lambda as well as STL algorthm
7. Function Graph::GetUniqueBlockNameInGraph is reewritten. Removed redundant function call and unncessary variables
8. usage of std::ostringstream is removed and replaced with modern C++ function std::to_string to cnvert integral 
   type to std::string 
9. Commented the destructor decalaration of class Block, so this class will become movable.
   So standard conatiners may use move symantics instead copy syamantics. 
10. Created destructor and constructor for Graph class. 
   
**Additional suggestion**

 "Graphs are responsible for ownership of a collection of Blocks". This statement may help us to bring the std::unique_ptr
 within solution. Instead of using raw pointer  to hold block we can depend on std::unique_ptr<>. So 
 we can re declare  std::vector<std::unique_ptr<Block> > m_blocks. Then from main we can create std::unique_ptr by 
 using std::make_unique<> instead using naked new operator. We will end up in a few additional challenges later when we try to 
 invoke some of const member functions since std::unique_ptr<> is not copyable. 
 







