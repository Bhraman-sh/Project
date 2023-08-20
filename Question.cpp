#include "Question.h"

Question::Question(int a, std::string qn, std::string oa, std::string ob, std::string oc, std::string od, char c)
{
	setQnNo(a);
	setQuestion(qn);
	setOptionA(oa);
	setOptionB(ob);
	setOptionC(oc);
	setOptionD(od);
	setCorrectOption(c);
}

void Question::setQnNo(int a)
{
	qn_no = a;
}

void Question::setQuestion(std::string s)
{
	int length = s.size();
	length = (length < 200 ? length : 199);
	s.copy(qn, length);
	qn[length] = '\0';
}

void Question::setOptionA(std::string s)
{
	int length = s.size();
	length = (length < 100 ? length : 99);
	s.copy(optn_a, length);
	optn_a[length] = '\0';
}

void Question::setOptionB(std::string s)
{
	int length = s.size();
	length = (length < 100 ? length : 99);
	s.copy(optn_b, length);
	optn_b[length] = '\0';
}

void Question::setOptionC(std::string s)
{
	int length = s.size();
	length = (length < 100 ? length : 99);
	s.copy(optn_c, length);
	optn_c[length] = '\0';
}

void Question::setOptionD(std::string s)
{
	int length = s.size();
	length = (length < 100 ? length : 99);
	s.copy(optn_d, length);
	optn_d[length] = '\0';
}

void Question::setCorrectOption(char c)
{
	correct = c;
}

int Question::getQnNO()
{
	return qn_no;
}

std::string Question::getQuestion()
{
	return qn;
}

std::string Question::getOptionA()
{
	return optn_a;
}

std::string Question::getOptionB()
{
	return optn_b;
}

std::string Question::getOptionC()
{
	return optn_c;
}

std::string Question::getOptionD()
{
	return optn_d;
}

char Question::getCorrectOption()
{
	return correct;
}
