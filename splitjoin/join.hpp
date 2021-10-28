#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>

template<typename Char_T>
std::basic_string<Char_T> join( const std::vector<std::basic_string<Char_T>>& strings, Char_T delimiter )
{
    switch ( strings.size() )
    {
    case 0:
        return std::basic_string<Char_T>();
    case 1:
        return strings.front();
    default:;   // Fall through to main body of function.
    }

    const auto size = std::accumulate( strings.cbegin(), strings.cend(), size_t( 0 ), []( const auto& curr, const auto& str ) {
        return curr + str.length();
        } ) + strings.size() - 1;

    std::basic_string<Char_T> result( size, Char_T( 0 ) );
    auto pos = std::copy( strings.front().cbegin(), strings.front().cend(), result.begin() );
    std::for_each( std::next( strings.cbegin() ), strings.cend(), [&pos, delimiter]( const auto& s ) {
        *pos++ = delimiter;
        pos = std::copy( s.cbegin(), s.cend(), pos );
        } );

    return result;
}
