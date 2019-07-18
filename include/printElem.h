//
// Created by joan on 19-7-17.
//

#ifndef C_STANDARD_LIB_PRINTELEM_H
#define C_STANDARD_LIB_PRINTELEM_H


#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <iterator>


/**
 *
 * Insert_Elements(collection, first, last)
 * -fill values from first to last into the collection
 * -NOTE: NO half-range
 * @tparam T
 * @param coll
 * @param first
 * @param last
 */
template <typename T>
inline void Insert_Elem(T& coll, int first, int last)
{
    for(;first <= last; first++)
    {
        coll.insert(coll.end(), first);
    }
}


/**
 * Print_Elem()
 * -prints optional string optStr followed by
 * -all elements of the collection coll
 * -separated by space;
 * @tparam T
 * @param coll
 * @param optStr
 */
template <typename T>
inline void Print_Elem(const T& coll, const std::string& optStr="")
{
    std::cout << optStr;
    for(auto& elem: coll)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}



/**
 * Print_Map_Elem()
 * -prints optional string optStr followed by
 * -all elements of the collection coll
 * -separated by space;
 * @tparam T
 * @param coll
 * @param optStr
 */
template <typename T>
inline void Print_Map_Elem(const T& coll, const std::string& optStr="")
{
    std::cout << optStr;
    for(auto& elem: coll)
    {
        std::cout << "[" << elem.first << ", " << elem.second << "] ";
    }
    std::cout << "\n";
}



#endif //C_STANDARD_LIB_PRINTELEM_H
