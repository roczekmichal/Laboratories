#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{

    /* ===================================TASK 1=================================*/
    list<int> my_list = { 11, 1, 2, 3, 4, 5};
    cout << "\t\t================== TASK 1 ==================\n";
    cout << "\ta) Regular iterator \n";
    /* 1.a) Display on the screen all elements of my_list (use regular iterator)*/
    for (std::list<int>::iterator it=my_list.begin(); it != my_list.end(); ++it)
    std::cout << ' ' << *it;


    
    std::list<int>::reverse_iterator r_it = my_list.rbegin();
    cout << "\n\tb) Reverse iterator \n";
    /* 1.b) Display on the screen all elements of my_list in the reverse order (use reverse iterator) */
    for (r_it=my_list.rbegin(); r_it!= my_list.rend(); ++r_it)
    std::cout << ' ' << *r_it;
    
    
 
    cout << "\n\tc) Again last one:\n";
    /* 1.c) Display last element once again. Do not declare new iterator, use the one from b). */
   std::cout << *--r_it;
    

    std::list<int>::iterator base = --r_it.base();
    cout << "\n\td) Base:\n";
    /* 1. d) Create regular iterator and assign to it the base iterator of reverse iterator from c). Display it.*/
    std::cout<< *base;
    


    /*===================================== TASK 2=================================================================*/
    cout << "\n\n\t\t================== TASK 2 ==================\n";
    /* 2. Use only inserting iterators in task 2! */

    std::list<int> v = {1, 2, 3};
    cout << "a) Inserting at the beginning\n";
    /*2.a) Insert '-1' '0' at the beginning and display the list (as in 1.a)*/
    /*front_insert_iterator <list<int>> it(v);
    for(int i  = 0; i > -2;i--){it=i;}
    for(std::list<int>::iterator it=v.begin();it!=v.end();++it)
    std::cout << ' ' << *it;*/
   
    
    cout << "\nANSWER:\n-1 0 1 2 3 \n";


    cout << "\n\nb) Inserting at the end\n";
    //2.b)Insert '4' '5' at the end and display the list (as in 1.a)*/
    back_insert_iterator <list<int>> it(v);
    for(int i = 4; i < 6; i++){it=i;}
    for(std::list<int>::iterator it=v.begin();it!=v.end();++it)
    std::cout << ' ' << *it;
   

    cout << "\nANSWER:\n1 2 3 4 5 \n";


    cout << "\n\nc) Inserting in the middle\n";
    /* 2.c) Insert '8' '8' '8' after third element in the list and display the list (as in 1.a) */
    std::list<int>::iterator iter = v.begin();
    advance(iter,3);
    insert_iterator <list<int> > itc(v, iter);
    for (int i = 0; i < 3; ++i){itc = 8;}

    for (std::list<int>::iterator it=v.begin(); it != v.end(); ++it)
    std::cout << ' ' << *it;
   
    
    cout << "\nANSWER:\n-1 0 1 8 8 8 2 3 4 5\n";





    /*====================================== TASK 3 =====================================================*/
    cout << "\n\n\t\t================== TASK 3 ==================\n";
    
    vector<string> my_vec = {"one", "two"};
    /* 3.a) Use copy algorithm and stream iterators, to read words from the user (cin) into the vector my_vec.
    Use back_inserter (3rd argument). To stop reading from cin use ctrl+z (some systems: ctrl+d) */
    vector<string> col((istream_iterator<string>(cin)),
    istream_iterator<string>());
  
    std::back_insert_iterator< std::vector<string> > back_it (my_vec);
    std::copy (col.begin(),col.end(),back_it);

    cout << "\na):\n";
    for (std::vector<string>::iterator it=my_vec.begin(); it != my_vec.end(); ++it)
    std::cout << ' ' << *it;
   

     /* 3.b) Sort the vector  */
    sort(my_vec.begin(), my_vec.end());

    cout << "\nb):\n";
    for (std::vector<string>::iterator it=my_vec.begin(); it != my_vec.end(); ++it)
    std::cout << ' ' << *it;    


    /* 3.c) Copy sorted vector my_vec to the standard output - use ostream_iterator, putting "***" between strings;*/
    cout << "\nc):\n";
    ostream_iterator < string > out_it(cout, " *** "); 
    copy(my_vec.begin(), my_vec.end(), out_it);
    //...
    return 0;
}
