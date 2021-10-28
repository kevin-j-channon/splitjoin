#pragma once

#include <string>
#include <cctype>
#include <cwctype>
#include <algorithm>

namespace
{
template<typename Char_T>
struct IsNotWhitespace;

template<>
struct IsNotWhitespace<char>
{
    bool operator()( const char ch ) { return !std::isspace( ch ); }
};

template<>
struct IsNotWhitespace<wchar_t>
{
    bool operator()( const wchar_t ch ) { return !std::iswspace( ch ); }
};
}

template<typename Char_T>
std::basic_string<Char_T> strip( const std::basic_string<Char_T>& str )
{
    const auto begin = std::find_if( str.cbegin(), str.cend(), IsNotWhitespace<Char_T>() );
    const auto end = std::find_if( str.crbegin(), str.crend(), IsNotWhitespace<Char_T>() ).base();

    return std::basic_string<Char_T>( begin, end );
}
