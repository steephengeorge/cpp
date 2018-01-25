#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <iostream>

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;


/*You are battling a powerful dark wizard. He casts his spells from a distance, giving you only a few seconds to react and conjure your counterspells. For a counterspell to be effective, you must first identify what kind of spell you are dealing with.

The wizard uses scrolls to conjure his spells, and sometimes he uses some of his generic spells that restore his stamina. In that case, you will be able to extract the name of the scroll from the spell. Then you need to find out how similar this new spell is to the spell formulas written in your spell journal.

Spend some time reviewing the locked code in your editor, and complete the body of the counterspell function.

Input Format

The wizard will read  scrolls, which are hidden from you.
Every time he casts a spell, it's passed as an argument to your counterspell function.

Constraints

, where  is a scroll name.
Each scroll name, , consists of uppercase and lowercase letters.
Output Format

After identifying the given spell, print its name and power.
If it is a generic spell, find a subsequence of letters that are contained in both the spell name and your spell journal. Among all such subsequences, find and print the length of the longest one on a new line.

Sample Input

3
fire 5
AquaVitae 999 AruTaVae
frost 7
Sample Output

Fireball: 5
6
Frostbite: 7
Explanation

Fireball and Frostbite are common spell types.
AquaVitae is not, and when you compare it with AruTaVae in your spell journal, you get a sequence: AuaVae
*/

#include <iostream>
#include <vector>
#include <string>

class Spell
{
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName()
        {
            return scrollName;
        }
};

class Fireball : public Spell
{
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower()
        {
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell
{
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower()
        {
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell
{
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower()
        {
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell
{
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower()
        {
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal
{
    public:
        static string journal;
        static string read()
        {
            return journal;
        }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell)
{
    if( Fireball* fire = dynamic_cast<Fireball*> (spell) )
    {
       fire->revealFirepower();
    }
    else if( Frostbite* frost = dynamic_cast<Frostbite*> (spell))
    {
       frost->revealFrostpower();
    }
    else if( Thunderstorm* thunder = dynamic_cast<Thunderstorm*> (spell))
    {
       thunder->revealThunderpower();
    }
    else if( Waterbolt* water = dynamic_cast<Waterbolt*> (spell))
    {
       water->revealWaterpower();
    }
    else
    {
       int result=0;

       std::string scroll = spell->revealScrollName();
       size_t start = 0;

       for ( ; start < scroll.length() && start < SpellJournal::journal.length() &&
                                          scroll[start] == SpellJournal::journal[start]; ++start, ++result);

       size_t f_end = scroll.length()-1;
       size_t l_end = SpellJournal::journal.length()-1;
       for ( ; start<= f_end && start <= l_end &&
               scroll[f_end] == SpellJournal::journal[l_end];
               --f_end, --l_end, ++result );

       int rows = scroll.length() - result+1;
       int cols = SpellJournal::journal.length()- result+1;
       int c [ rows][cols];


       for( int i = 0; i < rows; ++i )
       {
               c[i] [0]  = 0;
       }
       for(int j = 0; j < cols; ++j)
       {
           c[0][j] =0;
       }
       for( int i = 1; i < rows; ++i )
       {
           for(int j = 1; j < cols; ++j)
           {
               if( scroll[start+i-1] == SpellJournal::journal[start+j-1])
               {
                   c[i][j] = c[i-1][j-1]+1;
               }
               else
               {
                   c[i][j] = std::max( c[i-1][ j], c[i] [j-1]);
               }
           }
       }
       std::cout << c[rows-1] [cols-1] + result <<"\n";
    }
}
class Wizard
{
    public:
        Spell *cast()
        {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire")
            {
                spell = new Fireball(power);
            }
            else if(s == "frost")
            {
                spell = new Frostbite(power);
            }
            else if(s == "water")
            {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder")
            {
                spell = new Thunderstorm(power);
            }
            else
            {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main()
{
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--)
    {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
}