#include "ScoreCompare.h"

void ScoreCompare::getFile()
{
	file.open("ProgramFile/highscorefile.dat", std::ios::in);
	if (file)
	{
		str1 << file.rdbuf();
		filename = str1.str();
		file.close();
	}
}

void ScoreCompare::compareScore(int j)
{

	
	getFile();
	file.open(filename, std::ios::in);
	str << file.rdbuf();
	std::string current_high_score = str.str();
	file.close();
	highscore = std::stoi(current_high_score);
	if (j > highscore)
	{
		file.open(filename, std::ios::out);
		file << j;
		file.close();
	}
}