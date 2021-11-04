#include <iostream> 
#include <algorithm>  
#include <vector> 

template<class T>
void print_v(const std::vector<T> &v)
{
 for(auto x: v)
 std::cout << x << " ";
 std::cout << std::endl;
}

int generate_v1(){return rand()%100;}
int generate_v2(int x){return rand()%100;}
//struct generate_v3{
//    int generate()(int x){return -x;}
//};

int isGreater50(std::vector<int> v1){
    int how_many = 0;
    for(auto i : v1){
        if ( i > 50)
            how_many++;
        else
            continue;
    } 
    return how_many;
}

struct person
{
    std::string name;
    int age;
    int id;
};

bool comparedName(const person &a, const person &b){
    return a.name.size() < b.name.size();
}

bool comparedAge(const person &a, const person &b){
    return a.age < b.age;
}

bool comparedId(const person &a, const person &b){
    return a.id < b.id;
}

int main(){

std::vector <int> v1(100);
std::vector <int> v2(100);
std::vector <int> v3(10);
std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//TASK 1 A)
//std::generate(v1.begin(), v1.end(), generate_v1);
//print_v(v1);

std::cout<<std::endl;

//TAKS 1 B)
//int t = 10;
//std::generate_n(back_inserter(v2), 100, [t](){return rand()%t;});
//print_v(v2);

std::cout<<std::endl;

//TASK 1 C)
//std::generate_n(back_inserter(v3), 10, generate_v3());
//print_v(v3);


//TASK 1 D)
//auto c = std::count(v1.begin(), v1.end(), 10);
//std::cout<<c<<std::endl;


//TASK 1 E)
//auto d = std::count(v1.begin() + 3, v1.begin() + 11, 10);
//std::cout<<d<<std::endl;


//TASK 1 F)
//auto e = std::count_if(v1.begin(), v1.end(), isGreater50);
//std::cout<<e<<std::endl;





//TASK 2
person student1 = {"Mark", 23, 345623};
person student2 = {"Frank", 21, 236543};

std::vector<person> vp;
vp.push_back(student1);
vp.push_back(student2);

std::sort(vp.begin(),vp.end(), comparedName);
std::sort(vp.begin(),vp.end(), comparedAge);
std::sort(vp.begin(),vp.end(), comparedId);

return 0;
}
