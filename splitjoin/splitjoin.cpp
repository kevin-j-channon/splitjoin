#include "pch.h"
#include "CppUnitTest.h"

#include "join.hpp"

#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace splitjoin
{
	TEST_CLASS(splitjoin)
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
            Assert::AreEqual( std::string( "One small step for man..."), sentence );
		}
	};
}
