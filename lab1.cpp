#include <iostream>
#include <string>
#include <cstring>
/*
template <typename T> //template <class T>
T minimum(T a, T b) { return a < b ? a : b; }
*/

template <typename first>
first smaller(first a, first b) {
if (a<b){
    return a;
}
else
    return b;
}

template <>
char* smaller<char*>(char* a, char* b) {
return (strcmp(a, b) < 0) ? a : b;
}

struct Player{
std::string name;
int height;
Player(): name(""), height(0){};
Player(std::string n, int h): name(n), height(h){};
};


template <class T>
class Top3{
    T first, second, third;
public:
    Top3() = default;
    Top3(T a , T b , T c) : first(a), second(b), third(c){};
    ~Top3(){};
    void print() { std::cout<< first << " " << second << " " << third << std::endl;}
};



template <class T2, int T3>
class Top{
    double top[T3];
    bool set[]

};















int main(){
    //Task A
    /*
    int a =  smaller<int>(8,7);                       //number 7 is smaller than number 8
    std::string b = smaller<std::string>("ab","ac");  //"ab" is smaller than "ac"
    float c = smaller<float>(7.4,7.8);                  //7.4 is smaller than 7.8
    std::cout<<a<<std::endl;
    */

    //Task B
   
    Player z1("Brown",166);
    Player z2("Smith",182);
    Player z3("Jones",173);
    //int z4 = smaller(z2.height,z3.height);
    //std::string z5 = smaller(z1.name,z2.name);
    //std::cout<<z4<<std::endl;
   
    //Task C

    Top3 <int> FavoritesNumbers (19,15,3);
    //FavoritesNumbers.print();
    Top3 <std::string> FavoritesPlayers (z1.name, z2.name, z3.name);
    //FavoritesPlayers.print();

    //Task D



    return 0;
}