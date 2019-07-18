
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

#include "../../include/printElem.h"
using namespace std;

typedef int ElementType;

void print_elem(ElementType elem)
{
    cout << elem << " ";
}

template <typename T>
class AddValue{
private:
    int theValue;
public:
    AddValue(T val) : theValue(val){}

    void operator()(T& elem) const
    {
        elem += theValue;
    }
};


class MeanValue{
private:
    int sum;
    int elemCount;
public:
    MeanValue(): sum(0), elemCount(0) { }

    void operator()(const ElementType& elem)
    {
        sum += elem;
        elemCount += 1;
    }

    operator double()
    {
        return static_cast<double>(sum)/static_cast<double>(elemCount);
    }
};



int main()
{

    vector<ElementType> coll1;
    for(int i=0; i<10; i++)
    {
        coll1.push_back(i);
    }

    for_each(coll1.cbegin(), coll1.cend(), [](int elem){
        std::cout << elem << " ";
    });

    cout << "\n";

    list<ElementType> coll2(coll1.begin(), coll1.end());
    auto temp = for_each(coll2.cbegin(), coll2.cend(), print_elem);
    cout << "\n " << is_pointer<decltype(temp)>::value << endl;

    cout << "\n";

    forward_list<ElementType> coll3 = { 1, 3, 5, 6, 18, 29, 30, 92};
    for_each(coll3.begin(), coll3.end(), AddValue<ElementType>(10));
    Print_Elem(coll3, "coll3 elem: \n");

    forward_list<ElementType> coll4 = coll3;
    for_each(coll4.begin(), coll4.end(), [&](ElementType& elem){
        elem += coll4.front();
    });
    Print_Elem(coll4, "coll4 elem: \n");


    deque<ElementType> coll5{12, 45, 78, 76, 2, 5, 60};
    /*Foreach会返回其函数对象*/
    double meanVal = for_each(coll5.cbegin(), coll5.cend(), MeanValue());
    Print_Elem(coll5, "coll5 elem: \n");
    cout << "meanVal : " << meanVal << endl;

    /*The second lambda way*/
/*
    int sum=0;
    int elemCount = coll5.size();
    for_each(coll5.cbegin(), coll5.cend(), [&](const ElementType & elem){
        sum += elem;
    });
//    double meanVal2 = static_cast<double>(sum)/ static_cast<double>(elemCount);
    double meanVal2 = static_cast<double>(sum/elemCount);
    Print_Elem(coll5, "coll5 elem: \n");
    cout << "meanVal2 : " << meanVal << endl;
*/


    return 0;
}