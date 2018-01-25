/*
A student signed up for  workshops and wants to attend the maximum number of workshops
 where no two workshops overlap. You must do the following:

Implement  structures:

struct Workshop having the following members:

The workshop's start time.
The workshop's duration.
The workshop's end time.
struct Available_Workshops having the following members:

An integer,  (the number of workshops the student signed up for).
An array of type Workshop array having size .
Implement  functions:

Available_Workshops* initialize (int start_time[], int duration[], int n)
Creates an Available_Workshops object and initializes its elements using the elements in
the  and  parameters (both are of size ). Here,  and  are the respective start time and
 duration for the  workshop. This function must return a pointer to an Available_Workshops
 object.

int CalculateMaxWorkshops(Available_Workshops* ptr)
Returns the maximum number of workshops the student can attend—without overlap. The next
workshop cannot be attended until the previous workshop ends.

Note: An array of unkown size () should be declared as follows:

DataType* arrayName = new DataType[n];
Input Format

Input from stdin is handled by the locked code in the editor; you simply need to write your
functions to meet the specifications of the problem statement above.

Constraints

Output Format

Output to stdout is handled for you.

Your initialize function must return a pointer to an Available_Workshops object.
Your CalculateMaxWorkshops function must return maximum number of non-overlapping workshops
the student can attend.

Sample Input

6
1 3 0 5 5 8
1 1 6 2 4 1
Sample Output

CalculateMaxWorkshops should return .

Explanation

The first line denotes , the number of workshops.
The next line contains  space-separated integers where the  integer is the  workshop's
start time.
The next line contains  space-separated integers where the  integer is the  workshop's
duration.

The student can attend the workshops  and  without overlap, so CalculateMaxWorkshops
returns  to main (which then prints  to stdout).
*/


//Implement the functions initialize and CalculateMaxWorkshops
#include <set>
#include <vector>

struct Workshop
{
    int start_time;
    int end_time;
    int duration;
};

struct Available_Workshops
{
    int n;
    std::vector<Workshop> aw;
};

Available_Workshops * initialize (int start_time[], int duration[], int n)
{
  Available_Workshops  *a = new Available_Workshops;
  a->n = n;
  a->aw.reserve(n);

  for( int i = 0 ; i < n; ++i)
  {
      a->aw[i].start_time = start_time[i];
      a->aw[i].duration = duration[i];
      a->aw[i].end_time = start_time[i] + duration[i];
  }
  return a;
}
struct val
{
  bool operator()(const Workshop& a, const Workshop& b)const
  {
     return  a.end_time <= b.end_time ;
  }
};

int CalculateMaxWorkshops(Available_Workshops * ptr)
{
    int cnt = 1;
    std::set< Workshop, val> mySet;

    for(int i = 0; i < ptr->n; ++i)
    {
           mySet.insert(ptr->aw[i] );
    }

    int last = mySet.begin()->end_time;
    for(auto i = ++(mySet.begin()); i != mySet.end(); ++i)
    {
        if( i->start_time >=  last )
        {
            ++cnt;
            last = i->end_time;
        }
    }
    delete ptr;
    return cnt;
}
