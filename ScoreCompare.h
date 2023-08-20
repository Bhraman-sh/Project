#pragma once
#include<iostream>
#include<fstream>
#include<sstream>

class ScoreCompare
{
	std::stringstream str, str1;
	std::string filename;
	std::fstream file;
	int highscore;
public:
	void getFile();
	void compareScore(int j);
};

