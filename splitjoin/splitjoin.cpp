#include "pch.h"
#include "CppUnitTest.h"

#include "join.hpp"
#include "split.hpp"

#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::string_literals;

namespace splitjoin
{
	TEST_CLASS(Join)
	{
	public:
		
		TEST_METHOD(join_strings_with_spaces)
		{
            // Given: a vector of strings
            // When: I join with a space
            // Then: The result is a single string with the items separated by space characters.

            // GIVEN
            const auto items = std::vector<std::string>{ "One", "small", "step", "for", "man..." };

            // WHEN
            const auto sentence = join( items, ' ');

            // THEN
            Assert::AreEqual( "One small step for man..."s, sentence );
		}
        TEST_METHOD( join_strings_with_non_space_characters )
        {
            // Given: a vector of strings
            // When: I join with a non-space character (dash)
            // Then: The result is a single string with the items separated by dash characters.

            // GIVEN
            const auto items = std::vector<std::string>{ "One", "small", "step", "for", "man..." };

            // WHEN
            const auto sentence = join( items, '-' );

            // THEN
            Assert::AreEqual( "One-small-step-for-man..."s, sentence );
        }

        TEST_METHOD( join_wide_strings_with_spaces )
        {
            // Given: a vector of wide strings
            // When: I join with a space
            // Then: The result is a single wide string with the items separated by space characters.

            // GIVEN
            const auto items = std::vector<std::wstring>{ L"One", L"small", L"step", L"for", L"man..." };

            // WHEN
            const auto sentence = join( items, L' ' );

            // THEN
            Assert::AreEqual( L"One small step for man..."s, sentence );
        }

        TEST_METHOD( join_empty_vector_is_an_empty_string )
        {
            // Given: an empty vector of strings
            // When: I join with a space
            // Then: The result is an empty string

            // GIVEN
            const auto items = std::vector<std::string>{};

            // WHEN
            const auto sentence = join( items, ' ' );

            // THEN
            Assert::AreEqual( ""s, sentence );
        }

        TEST_METHOD( join_vector_of_empty_strings_is_only_delimiters )
        {
            // Given: a vector of N empty strings
            // When: I join with a space
            // Then: The result is a string with N - 1 spaces

            // GIVEN
            const auto items = std::vector<std::string>{"", "", "", ""};

            // WHEN
            const auto sentence = join( items, ' ' );

            // THEN
            Assert::AreEqual( "   "s, sentence );
        }
	};

    TEST_CLASS( Split )
    {
        TEST_METHOD( split_string_on_space )
        {
            // Given: A string containing a delimiter (space)
            // When: the string is split on space
            // Then: The result is a vector of words that were separated by spaces in the original string

            // GIVEN
            const auto str = "One small step for man..."s;

            // WHEN
            const auto words = split( str, ' ' );

            // THEN
            const auto expected = std::vector<std::string>{ "One", "small", "step", "for", "man..." };
            Assert::AreEqual( expected.size(), words.size() );

            for ( size_t i = 0; i < expected.size(); ++i)
            {
                Assert::AreEqual( expected[i], words[i] );
            }
        }

        TEST_METHOD( split_string_on_newline )
        {
            // Given: A string containing a delimiter (newline)
            // When: the string is split on newline ('\n')
            // Then: The result is a vector of words that were separated by newlines in the original string

            // GIVEN
            const auto str = "One small step for man...\nOne... giant leap... for Mankind"s;

            // WHEN
            const auto words = split( str, '\n' );

            // THEN
            const auto expected = std::vector<std::string>{ "One small step for man...", "One... giant leap... for Mankind" };
            Assert::AreEqual( expected.size(), words.size() );

            for ( size_t i = 0; i < expected.size(); ++i )
            {
                Assert::AreEqual( expected[i], words[i] );
            }
        }

        TEST_METHOD( split_without_delimiter_is_original_string )
        {
            // Given: A string that doesn't contain the target delimiter
            // When: The string is split
            // Then: The result is a vector that is a single element containing the original string

            // GIVEN
            const auto str = "No delimiters here!"s;

            // WHEN
            const auto result = split( str, '-' );

            Assert::AreEqual( size_t( 1 ), result.size() );
            Assert::AreEqual( str, result.front() );
        }

        TEST_METHOD( split_string_that_only_contains_delimiters )
        {
            // Given: A string that contains only N delimiting characters
            // When: The string is split
            // Then: The result is a vector of N+1 empty strings

            // GIVEN
            const auto str = "    "s;

            // WHEN
            const auto result = split( str, ' ' );

            // THEN
            Assert::AreEqual( str.length() + 1, result.size() );
            std::for_each( result.cbegin(), result.cend(), []( const auto& s ) { Assert::AreEqual( ""s, s ); } );
        }
    };
}
