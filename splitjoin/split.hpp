#pragma once

#include <vector>
#include <string>

template<typename Char_T>
std::vector<std::basic_string<Char_T>> split( const std::basic_string<Char_T>& str, Char_T delimiter )
{
    auto result = std::vector < std::basic_string<Char_T>>();

    auto begin = str.cbegin();
    while (true)
    {
        auto pos = std::find(begin, str.cend(), delimiter );

        result.emplace_back( begin, pos );

        if ( str.cend() == pos )
        {
            break;
        }
        else
        {
            begin = std::next( pos );
        }
    }

    return result;
}
