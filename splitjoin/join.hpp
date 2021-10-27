#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

template<typename Char_T>
std::basic_string<Char_T> join( const std::vector<std::basic_string<Char_T>>& strings, Char_T delimiter )
{
    std::basic_stringstream<Char_T> result;
    if ( strings.empty() )
    {
        return result.str();
    }

    result << strings.front();

    std::for_each( std::next( strings.cbegin() ), strings.cend(), [&result, delimiter]( const auto& s ) {
        result << delimiter << s;
        } );

    return result.str();
}
