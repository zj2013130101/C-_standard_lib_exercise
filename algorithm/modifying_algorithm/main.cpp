//#include <iostream>
//#include <vector>
//#include <deque>
//#include <array>
//#include <list>
//#include <forward_list>
//
//using namespace std;
//
//int main() {
//    vector<int> coll;
//    deque<float > coll_deque;
//    array<string, 5> coll_arr = {"hello", "world"};
//    list<char> coll_list;
//    forward_list<long> coll_flist = {2, 3, 5, 7, 11, 13, 17};
//
//    //resize two times
//    //note: poor performance
//    coll_flist.resize(9);
//    coll_flist.resize(10, 99);
//
//    for( int i=1; i<=5; i++)
//    {
//        coll.push_back(i);
//        coll_deque.push_front(i*1.1);   //insert at the front
//        coll_list.push_back(i+'a');
//    }
//
//    for(int i=0; i<coll.size(); i++)
//    {
//        cout << coll[i] << ' ';
//        cout << coll_deque[i] << ' ';
//        cout << i << ": " << coll_arr[i] << endl;
//    }
//
//    // use range-based for loop
//    for(auto elem: coll_list)
//    {
//        cout << elem << ' ';
//    }
//    for(auto elem: coll_flist)
//    {
//        cout << elem << ' ';
//    }
//    cout << endl;
//
//    return 0;
//}

//#include <iostream>
//#include <unordered_map>
//#include <string>
//using namespace std;
//
//int main(int argc, char* arg[])
//{
//    unordered_map<string, float> coll;
//    //insert some elements into the collection
//    //using the syntax of an associative array
//    coll["VAT1"] = 0.16;
//    coll["VAT2"] = 0.07;
//    coll["pi"] = 3.1415;
//
//    //change value
//    coll["VAT1"] += 0.03;
//
//    //print difference of VAT values
//    cout << "VAT difference: " << coll["VAT1"] - coll["VAT2"] << endl;
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//    vector<int> coll = { 2, 5, 4, 1, 6, 3}; //initial list
//
//    //find and print minimum and maximum elements
////    vector<int>::const_iterator minpos = min_element(coll.begin(), coll.end());
//    auto minpos = min_element(coll.cbegin(), coll.cend());
//    cout << "min: " << *minpos << endl;
////    vector<int>::const_iterator maxpos = max_element(coll.begin(), coll.end());
//    auto maxpos = max_element(coll.cbegin(), coll.cend());
//    cout << "max: " << *maxpos << endl;
//
//    //sort all elements
//    sort(coll.begin(), coll.end());
//
//    //find the first element with value 3
//    //vector<int>::iterator pos3;
//    auto pos3 = find(coll.begin(), coll.end(), 3);
//
//    //reverse the order of the found element with value 3 and all following elements
//    reverse(pos3, coll.end());
//
//    for(auto elem : coll)
//    {   cout << elem << endl; }
//    return 0;
//}

//
//#include <iostream>
//#include <algorithm>
//#include <list>
//#include <vector>
//#include <deque>
//#include <iterator>
//#include <set>
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//    list<int> coll1 = { 1,  2, 3, 4, 5, 6, 8, 9 };
//
//    //copy the element of coll1 into coll2 by appending them
//    vector<int> coll2;
//    copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));
//    for(auto elem: coll2)
//    {   cout << elem << " "; }
//    cout << endl;
//
//    //copy the elements of coll1 into coll3 by inserting them at the front
//    //-reverse the order of the elements
//    deque<int>  coll3;
//    copy(coll1.begin(), coll1.end(), front_inserter(coll3));
//    for(auto elem: coll3)
//    {   cout << elem << " "; }
//    cout << endl;
//
//    //copy elements of coll1 into coll4
//    //-only inserter that works for associative collections
//    set<int> coll4;
//    copy(coll1.cbegin(), coll1.cend(), inserter(coll4, coll4.begin()));
//    for(auto elem: coll4)
//    {   cout << elem << " "; }
//    cout << endl;
//
//    return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <list>
//#include <cstdlib>  //for abs()
//using namespace std;
//
////predicate,which return whether an integer is a prime number
//bool isPrime(int number)
//{
//    //ignore negative sign
//    number = abs(number);
//
//    //0 or 1 are no prime numbers
//    if(number == 0 || number == 1)
//    {
//        return false;
//    }
//
//    //find divisor that divides without a remainder
//    int divisor;
//    for( divisor = number/2; number%divisor != 0; --divisor)
//    { ; }
//
//    //if no divisor greater than 1 is found, it is a prime number
//    return divisor == 1;
//}
//
//int main(int argc, char* argv[])
//{
//    list<int> coll;
//    for(int i=24; i<= 30; i++)
//    {   coll.push_back(i); }
//
//    //search for prime number
//    auto pos = find_if(coll.cbegin(), coll.cend(), isPrime);    //predicate
//
//    if(pos != coll.end())
//    {
//        cout << *pos << "is first prime number found " <<endl;  //found
//    }else{
//        cout <<"no prime number found " <<endl;  //not found
//    }
//}



//#include <iostream>
//#include <algorithm>
//#include <deque>
//#include <set>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//    string firstName() const;
//    string lastName() const;
//};
//
//int main(int argc, char* argv[])
//{
//    deque<Person> coll;
//
//    sort(coll.begin(), coll.end(),
//            [](const Person& p1, const Person& p2){     //sort criterion
//        return p1.lastName() < p2.lastName() ||
//               ( p1.lastName() == p2.lastName() && p1.firstName() < p2.firstName());
//    });
//
//    //transfrom all elements to the power of 3
//    std::transform(coll.begin(), coll.end(), coll.begin(),
//            [](double d){
//        return d*d*d;
//    });
//}

//#include <algorithm>
//#include <deque>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    deque<int> coll = {1, 3, 19, 5, 7, 11, 2, 17};
//    int x = 5;
//    int y = 12;
//    auto pos = find_if(coll.cbegin(), coll.cend(),  //range
//            [=](int i){     //search criterion
//        return i> x && i< y;
//    });
//
//    cout << "firest elem > 5 and <12: " << *pos << endl;
//
//    //find the first element > x and < y
//    vector<int>::iterator pos;
//    for(pos= coll.begin(); pos!= coll.end(); ++pos)
//    {
//        if( *pos > x && *pos < y)
//            break;  //the loop
//    }
//}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//class PrintInt{
//public:
//    void operator() (int elem) const {
//        cout << elem << ' ';
//    }
//};
//
//int main(int argc, char* argv[])
//{
//    vector<int> coll;
//
//    for(int i=1; i<= 9; ++i)
//    {   coll.push_back(i); }
//
//    for_each(coll.cbegin(), coll.cend(), PrintInt());   //operation
//    cout << endl;
//}

//#include <iostream>
//#include <list>
//#include <algorithm>
//using namespace std;
//
////function object that adds the value with
//class AddValue{
//private:
//    int theValue;   // the value to add
//
//public:
//    //constructor initializes the value to add
//    AddValue(int v): theValue(v){ }
//
//    //the function call for the element adds the value
//    void operator() (int& elem) const{
//        elem += theValue;
//    }
//};
//
//int main(int argc, char* argv[])
//{
//    list<int> coll;
//    for(int i=1; i<=9; i++)
//    {   coll.push_back(i); }
//
//    //add value 10 to each element
//    for_each(coll.begin(), coll.end(), AddValue(10));
//
//    //add value of first element to each element
//    for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));
//}


//#include <deque>
//#include <algorithm>
//#include <functional>
//#include <iostream>
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//    deque<int> coll = {1, 2, 3, 5, 7, 11, 13, 17, 19};
//
//    //negate all values in coll
//    transform(coll.cbegin(), coll.cend(),  //source
//            coll.begin(),    //destination
//            negate<int>()); //operation
//
//    //square all values in coll
//    transform(coll.cbegin(), coll.cend(), //first source
//             coll.cbegin(), //second source
//             coll.begin(), //destination
//             multiplies<int>());    //operation
//}


#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>
using namespace std;
using namespace std::placeholders;

int main()
{
    set<int, greater<int>> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> coll2;

    //transform all elements into coll2 by multiplying them with 10
    transform(coll1.cbegin(), coll1.cend(), //source
            back_inserter(coll2),   //destination
            bind(multiplies<int>(), _1, 10) ); //operation

    //replace value equal to 70 with 42
    replace_if(coll2.begin(), coll2.end(), //range
            bind(equal_to<int>(), _1, 70), //replace criterion
            42);    //new value

    //remove all elements with values between 50 and 80
    coll2.erase(remove_if(coll2.begin(), coll2.end(),
                            bind(logical_and<bool>(),
                                    bind(greater_equal<int>(), _1, 50),
                                    bind(less_equal<int>(), _1, 80))),
                 coll2.end());
}