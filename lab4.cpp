#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <chrono>

/*For details see:
 https://www.cplusplus.com/reference/stl/
 https://en.cppreference.com/w/cpp/container
 */

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

// Functions used in exercise 4
template <class T>
double measure_time(int(*func)(const T&),const  T &t)
{
    auto start = std::chrono::high_resolution_clock::now();
    int w = func(t);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    //cout << w << endl; //uncomment for debugging (value returned by func)
    return duration.count();
    
}

template <class T>
double measure_time_avg3(int(*func)(const T&),const T &t)
{
    double c;
    c = measure_time(func,t);
    c += measure_time(func,t);
    c += measure_time(func,t);
    return c/3;
}

int vector_max(const vector<int>& v)
{
    int max = 0;
    
    // ...
    return max;
}

// ...


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
    // In case of *map containers (last four containers) use number from num array as key and its index in num array as value
     
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
    

    //************* EX 4 *************//
    cout << endl << endl << "************* EX 4 *************" << endl;
    cout.precision(10);
    cout << fixed;
   // 4.a) Use numbers in data to create:
    // - vector v1
    // - priority_queue q1
    // - set s1
    // - unordered_set us1
    
    //...
    
    // 4.b) Measure time of finding maximum in all these structures
    // (as in 3., complete sunctions)
    cout <<endl << endl;
    cout << "-------------------" << endl;
    //cout << "Data size: " <<  n << endl;
    cout << "Finding max"<< endl;
    cout << "-------------------" << endl;
    cout << "Time(s)\tStructure" << endl;
    cout << "-------------------" << endl;
   // cout << measure_time_avg3(vector_max, v) <<  "\tvector" << endl;
   // cout << measure_time_avg3(p_queue_max, q) <<  "\tpriority_queue" << endl;
   // cout << mierz_czmeasure_time_avg3as_sr3(set_max, s) <<  "\tset" << endl;
   // cout << measure_time_avg3(unordered_set_max, us) <<  "\tunordered_set" << endl;
    
    cout << "-------------------" << endl;
    
    cout <<endl << endl;
    // 4.c) Measure time of finding number "-1" in vector, set, unordered_set
    
    cout << "-------------------" << endl;
    //cout << "Data size: " <<  n << endl;
    cout << "Finding element"<< endl;
    cout << "-------------------" << endl;
    cout << "Tiome(s)\tStruscture" << endl;
    cout << "-------------------" << endl;
 //   cout << measure_time_avg3(vector_find, v) <<  "\tvector" << endl;
 //   cout << measure_time_avg3(set_find, s) <<  "\tset" << endl;
 //   cout << measure_time_avg3(u_set_find, us) <<  "\tunordered_set" << endl;
    cout << "-------------------" << endl;
    
}



//szukanie max + mierz czas
//szukanie -1 + mierz czas
