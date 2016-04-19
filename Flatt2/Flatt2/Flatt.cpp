//////////////////////////////////////////////////////////////////////////
// This program provides a function that accepts an arbitrarily-deep    //
// nested Array-like structure and returns a flattened structure with   //
// any null values removed.												//
// Platform:  Windows 10, X64, TOSHIBA Satellite						//
// Author:    Will Zhang, Computer Engineering, Syracuse University     //
// Contact:   tzhan116@syr.edu											//
//////////////////////////////////////////////////////////////////////////

/*************************************************************************
* Program input: A deep nested arry-like structure in std::string, containing 
*                tokens comma,blanks, angle brackets and reverse-angle brackets.
* Program output: A vector of all int values, in the form of std::string.
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Flatt.h"

#define COMMA 44
#define ANGLEBRACKET 91
#define RANGLEBRACKET 93
#define BLANK 32

void Flatt::flatten()
{
	result.clear();
	for (int i = 0; i < input.length(); )
	{
		if (input[i] == COMMA || input[i] == ANGLEBRACKET || input[i] == BLANK)
		{
			if (input[i + 1] == 45 || (input[i + 1] > 47 && input[i + 1] < 58))
			{
				std::string str;
				i++;
				while (input[i] != COMMA && input[i] != RANGLEBRACKET && input[i] != BLANK)
				{
					str.append(1, input[i]);
					i++;
				}
				result.push_back(str);
			}
			else
				i++;
		}
		else
			i++;
	}
}

void Flatt::show()
{
	std::cout << "Input array is: \n";
	std::cout << input << "\n";
	std::cout << "Output is: \n";
	for each(std::string i in result)
	{
		std::cout << i << "\n";
	}
	std::cout << "\n";
}

void main()
{
	std::string input1 = "[0, 2, [[2, 3], 8, 100, null, [[null]]], -2]";
	std::string input2 = "[[1], 3, [null], [101], [100], [null], [90], [123156467897456123156468], [[[[[null]]]]]]";

	Flatt* f1 = new Flatt(input1);
	f1->flatten();
	f1->show();

	f1->setInput(input2);
	f1->flatten();
	f1->show();

	Flatt* f2 = new Flatt(input2);
	f2->flatten();
	f2->show();
	system("pause");
}