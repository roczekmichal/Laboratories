#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <chrono>

// Sequence containers
// Sequence containers implement data structures which can be accessed sequentially.
#include <vector>  //vector
#include <list>    //list
#include <array>   //array
#include <forward_list>  //forward_list
#include <deque> //deque

// Container adaptors
// Container adaptors provide a different interface for sequential containers
#include <stack> //stack
#include <queue> //queue, priority_queue

// Associative containers
// Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).
#include <map> //map, multimap
#include <set> //set, multiset
// set and map:
// - usually implemented as binary search tree
// - ordered
// - unique elements
// - position depends on key
// set: keys only (used as values)
// map: key-value pairs


// Unordered associative containers
// Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) amortized, O(n) worst-case complexity).
#include <unordered_set> //unordered_set, unordered_muiltiset
#include <unordered_map> //unordered_map unordered_multimap
// unordered_set and unordered_map:
// - usually implemented as hash table
// - unordered
// - unique elements
// - position depends on key
// unordered_set: keys only (used as values)
// unordered_map: key-value pairs


// Other similar structures
#include <bitset> //bitset
#include <valarray> //valarray
#include <utility>  //pair

using namespace std;


int main() {
    
    //************* EX 1 *************//
    cout << "************* EX 1 *************" << endl;
    //
    int num_size = 8;
    int num[] = {88, 33, 66, 66, 11, 33, 99, 66};
    // 1.a) Construct the following containers using num array (or insert elements from the num array to empty containers):
    //  - vector
    //  - set
    //  - multiset
    //  - unordered_set
    //  - unordered_multiset
    //  - map
    //  - multimap
    //  - unordered_map
    //  - unordered_multimap
     
    vector<int> v(num, num+num_size);
    set<int> s(num, num+num_size);
    multiset<int> ms(num, num+num_size);
    unordered_set<int> us(num,num+num_size);
    unordered_multiset<int> ums(num,num+num_size);

    map<int,int> m;
    for(int i = 0; i < num_size; i++)
    {
        m.insert({num[i],i});
    }

    multimap<int,int> mm;
    for(int i = 0; i < num_size; i++)
    {
        mm.insert({num[i],i});
    }

    unordered_map<int,int> um;
    for(int i = 0; i < num_size; i++)
    {
        um.insert({num[i],i});
    }

    unordered_multimap<int, int> umm;
    for(int i = 0; i < num_size; i++)
    {
        umm.insert({num[i],i});
    }
    // 1.b) Display all elements from each container
    cout << endl << "Content of vector:"<< endl;
    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl << "Content of set:"<< endl;
    for(int i : s)
    {
        cout << i << " ";
    }
    cout << endl << "Content of multiset:"<< endl;
    for(int i : ms)
    {
        cout << i << " ";
    }
    cout << endl << "Content of unordered_set:"<< endl;
    for(int i : us)
    {
        cout << i << " ";
    }
    cout << endl << "Content of unordered_multiset:"<< endl;
    for(int i : ums)
    {
        cout << i << " ";
    }
    cout << endl << "Content of map:"<< endl;
    for( auto & el : m)
    {
       cout << el.first << ":" << el.second << " ";
    }
    cout << endl << "Content of multimap:"<< endl;
    for( auto & el : mm)
    {
       cout << el.first << ":" << el.second << " ";
    }
    cout << endl << "Content of unordered_map:"<< endl;
    for( auto & el : um)
    {
       cout << el.first << ":" << el.second << " ";
    }    
    cout << endl << "Content of unordered_multimap:"<< endl;
    for( auto & el : umm)
    {
       cout << el.first << ":" << el.second << " ";
    }    
    
    
    //************* EX 2 *************//
    cout << endl << endl << "************* EX 2 *************" << endl;
    // 2.a) Create a map, where:
    // - key is a name of a country
    // - value is the name of capital of that country
    
    map<string, string> countries;
    
    // 2.b) Insert 3 key-value elements into the map using insert method (including {"Poland", "Warsaw"} pair)
    countries.insert({"Poland","Warsaw"});
    countries.insert({"England","London"});
    countries.insert({"France","Paris"});
    // 2.c) Insert 3 key-value elements into the map using operator[]
    countries["Spain"] = "Madrid";
    countries["Italy"] = "Rome";
    countries["Germany"] = "Berlin";
    // 2.d) Display all elements of the map (country-capital pairs)
    cout << "Country-Capital map:"<< endl;
    for( auto & el : countries)
    {
       cout << el.first << ":" << el.second << " ";
    } 
    // 2.e) Change the capital of Poland to "Cracow".
    countries["Poland"] = "Cracow";
    
    // 2.f) Use operator[] to display capital of Poland and capital of some country that is not in the map.
    cout << countries["Poland"] << countries["Russia"];
    
    // 2.g) Display all elements of the map again (country-capital pairs).
    cout << endl << "Country-Capital map after changes:"<< endl;
    for( auto & el : countries)
    {
        cout << el.first << ":" << el.second << " ";
    }
    // 2.h) Construct another map using range constructor and copying elements of the country-capital map up to "Poland" (country-capital pairs). Display it.
    map<string, string> another_countries_map (countries.begin(), countries.find("Poland"));
    cout << endl << "Another Country-Capital map:"<< endl;
    for( auto & el : another_countries_map)
    {
        cout << el.first << ":" << el.second << " ";
    }
    
}

