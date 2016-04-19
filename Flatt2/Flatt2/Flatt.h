#pragma once
//////////////////////////////////////////////////////////////////////////
// This program provides a class that accepts an arbitrarily-deep       //
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

class Flatt
{
private:
	std::string input;
	std::vector<std::string> result;
public:
	Flatt(std::string in) { input = in; }
	// enable chaning of input
	void setInput(std::string in) { input = in; }
	// do flatten
	void flatten();
	// fetch ouput vector
	std::vector<std::string> getResult() { return result; }
	// show results
	void show();
};


