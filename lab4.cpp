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

// *******************************************************
// Functions used in exercise 3
int N = 1000000;
// Returns random number
int random_num()
{
    static std::default_random_engine gen(std::random_device{}());
    static std::uniform_int_distribution<int> dist;
    return dist(gen, std::uniform_int_distribution<int>::param_type{});
}
// Returns dynamically allocated array of integers, filled with random numbers
int * random_num_tab(int n)
{
    int * tab = new int[n];
    for (int i = 0; i < n; i++)
        tab[i] = random_num();
    return tab;
}
// Measures and returns time of execution of func(tab,n)
double measure_time(void(*func)(int *, int), int * tab, int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    func(tab, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}
// Measures and returns time of 3 executions of func(tab,n)
double measure_time_avg3(void(*func)(int *, int), int * tab, int n)
{
    double c;
    c = measure_time(func, tab, n);
    c += measure_time(func, tab, n);
    c += measure_time(func, tab, n);
    return c/3;
}

void vector_fill1(int * data, int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(data[i]);
    }
}

void vector_fill2(int * data, int n)
{
    // ...
}

void vector_fill3(int * data, int n)
{
    // ...
}

//...


// *******************************************************


// *******************************************************
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


// *******************************************************

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
    
    // ...
    
    // 1.b) Display all elements from each container
    cout << endl << "Content of vector:"<< endl;
    // ...
    cout << endl << "Content of set:"<< endl;
    // ...
    cout << endl << "Content of multiset:"<< endl;
    // ...
    cout << endl << "Content of unordered_set:"<< endl;
    // ...
    cout << endl << "Content of unordered_multiset:"<< endl;
    // ...
    cout << endl << "Content of map:"<< endl;
    // ...
    cout << endl << "Content of multimap:"<< endl;
    // ...
    cout << endl << "Content of unordered_map:"<< endl;
    // ...
    cout << endl << "Content of unordered_multimap:"<< endl;
    // ...
    
    
    //************* EX 2 *************//
    cout << endl << endl << "************* EX 2 *************" << endl;
    // 2.a) Create a map, where:
    // - key is a name of a country
    // - value is the name of capital of that country
    
    // ...
    
    // 2.b) Insert 3 key-value elements into the map using insert method (including {"Poland", "Warsaw"} pair)
    // ...
    
    // 2.c) Insert 3 key-value elements into the map using operator[]
    // ...
    
    // 2.d) Display all elements of the map (country-capital pairs)
    cout << "Country-Capital map:"<< endl;
    // ...
    
    // 2.e) Change the capital of Poland to "Cracow".
    // ...
    
    // 2.f) Use operator[] to display capital of Poland and capital of some country that is not in the map.
    // ...
    
    // 2.g) Display all elements of the map again (country-capital pairs).
    cout << endl << "Country-Capital map after changes:"<< endl;
    // ...
    // 2.h) Construct another map using range constructor and copying elements of the country-capital map up to "Poland" (country-capital pairs). Display it.
    // ...
    cout << endl << "Another Country-Capital map:"<< endl;
    // ...
    
    //************* EX 3 *************//
    cout << endl << endl << "************* EX 3 *************" << endl;
    int n = N;
    int * data = random_num_tab(n); //data: dynamically allocated array of integers
   // 3. Measure time of initializing containers and filling it with numbers from data array. Containers that should be used for test (uncomment code and define appropriate functions):
    // -vector (using push_back()) [DONE]
    // -vector (with reserve(N) used before push_back())
    // -vector (with initial size N and operator[] used)
    // -vector (with range constructor used)
    // -list
    // -stack
    // -forward_list
    // -deque
    // -queue
    // -priority_queue
    // -dynamically allocated array
    // -set
    // -multiset
    // -map
    // -multimap
    // -unordered_set
    // -unordered_multiset
    // -unordered_map
    // For all *map containers use char as the value and set character 'a' for all elements
    
    cout.precision(6);
    cout << fixed;
    cout << "-------------------" << endl;
    cout << "Data size: " <<  n << endl;
    cout << "Initialization and filling with numbers"<< endl;
    cout << "-------------------" << endl;
    cout << "Time(s)\t\tContainer" << endl;
    cout << "-------------------" << endl;
    cout << measure_time_avg3(vector_fill1, data, n) <<  "\tvector" << endl;
    cout << measure_time_avg3(vector_fill2, data, n) <<  "\tvector + reserve" <<endl;
    cout << measure_time_avg3(vector_fill3, data, n) <<  "\tvector with initial size n + []" << endl;
    //cout << measure_time_avg3(vector_fill4, data, n) <<  "\tvector with range constructor" << endl;
    //cout << measure_time_avg3(lista_fill, data, n) <<  "\tlist" << endl;
    //cout << measure_time_avg3(stack_fill, data, n) <<  "\tstack" << endl;
    //cout << measure_time_avg3(forward_lista_fill, data, n) <<  "\tforward_list" << endl;
    //cout << measure_time_avg3(deque_fill, data, n) <<  "\tdeque" << endl;
    //cout << measure_time_avg3(queue_fill, data, n) <<  "\tqueue" << endl;
    //cout << measure_time_avg3(p_queue_fill, data, n) <<  "\tpriority_queue" << endl;
    //cout << measure_time_avg3(tab_fill, data, n) <<  "\tdynamically allocated array" <<endl;
    cout << "--Associative containers--" << endl;
    //cout << measure_time_avg3(set_fill, data, n) <<  "\tset" <<endl;
    //cout << measure_time_avg3(multiset_fill, data, n) <<  "\tmultiset" <<endl;
    //cout << measure_time_avg3(map_fill, data, n) <<  "\tmap" <<endl;
    //cout << measure_time_avg3(multimap_fill, data, n) <<  "\tmultimap" <<endl;
    //cout << measure_time_avg3(unordered_set_fill, data, n) <<  "\tunordered_set" <<endl;
    //cout << measure_time_avg3(unordered_multiset_fill, data, n) <<  "\tunordered_multiset" <<endl;
    //cout << measure_time_avg3(unordered_map_fill, data, n) <<  "\tunordered_map" <<endl;
    //cout << measure_time_avg3(unordered_multimap_fill, data, n) <<  "\tunordered_multimap" <<endl;
    

    //************* EX 4 *************//
    cout << endl << endl << "************* EX 4 *************" << endl;
    cout.precision(10);
    cout << fixed;
   // 4.a) Use numbers in data to create:
    // - vector v
    // - priority_queue q
    // - set s
    // - unordered_set us
    
    //...
    
    // 4.b) Measure time of finding maximum in all these structures
    // (as in 3., complete sunctions)
    cout <<endl << endl;
    cout << "-------------------" << endl;
    cout << "Data size: " <<  n << endl;
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
    cout << "Data size: " <<  n << endl;
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
