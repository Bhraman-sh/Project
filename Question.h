#pragma once
#include<iostream>

class Question
{
private:
	int qn_no;
	char qn[200], optn_a[100], optn_b[100], optn_c[100], optn_d[100];
	char correct;
public:
	Question(int a = 0, std::string = "", std::string = "", std::string = "", std::string = "", std::string = "", char = 'a');

	void setQnNo(int a);
	void setQuestion(std::string s);
	void setOptionA(std::string s);
	void setOptionB(std::string s);
	void setOptionC(std::string s);
	void setOptionD(std::string s);
	void setCorrectOption(char c);

	int getQnNO();
	std::string getQuestion();
	std::string getOptionA();
	std::string getOptionB();
	std::string getOptionC();
	std::string getOptionD();
	char getCorrectOption();
};
