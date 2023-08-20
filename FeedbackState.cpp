#include "FeedbackState.h"

FeedbackState::FeedbackState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	this->font.loadFromFile("Fonts/ALGER.ttf");
	this->initButtons();
	this->loadData();
	this->loadText();
}

FeedbackState::~FeedbackState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void FeedbackState::initButtons()
{
	this->buttons["Continue"] = new Button(300, 640, 250, 50, &this->font, "Continue", sf::Color::Red,
		sf::Color::Blue, sf::Color::White);
}

void FeedbackState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update(this->mousePosView);
	}
	if (this->buttons["Continue"]->isPressed())
	{
		this->states->pop();
	}
}

void FeedbackState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : buttons)
	{
		it.second->render(target);
	}
}

void FeedbackState::loadData()
{
	std::fstream file;
	file.open("ProgramFile/questionnumber.txt", std::ios::in);
	if (file)
	{
		std::stringstream buffer;
		buffer << file.rdbuf();
		std::string num = buffer.str();
		question_num = std::stoi(num) - 1;
		file.close();
	}
	file.open("ProgramFile/chosenoption.txt", std::ios::in);
	if (file)
	{
		std::stringstream buffer;
		buffer << file.rdbuf();
		std::string op = buffer.str();
		u_opt = op[0];
		file.close();
	};
	file.open("ProgramFile/files.dat", std::ios::in);
	if (file)
	{
		std::stringstream buffer;
		buffer << file.rdbuf();
		genre = buffer.str();
	}
}


void FeedbackState::initCorrectOptionText()
{
	feedback.setFont(this->font);
	feedback.setCharacterSize(30);
	feedback.setString("Correct!!");
	feedback.setPosition(300, 540);
	feedback.setFillColor(sf::Color::White);

	sf::FloatRect textpos;
	textpos = feedback.getLocalBounds();

	correct_option.setFont(this->font);
	correct_option.setCharacterSize(30);
	correct_option.setPosition(315 + textpos.width,540);
	correct_option.setFillColor(sf::Color::White);

	sf::FloatRect textpos1 = correct_option.getLocalBounds();

	correct.setFont(this->font);
	correct.setCharacterSize(30);
	correct.setString("is the correct Answer");
	correct.setPosition(330 + textpos.width + textpos1.width, 540);
	correct.setFillColor(sf::Color::White);
}

void FeedbackState::initInCorrectOptionText()
{
	feedback.setFont(this->font);
	feedback.setCharacterSize(30);
	feedback.setString("Incorrect!!");
	feedback.setPosition(300, 540);
	feedback.setFillColor(sf::Color::White);

	sf::FloatRect textpos;
	textpos = feedback.getLocalBounds();

	correct_option.setFont(this->font);
	correct_option.setCharacterSize(30);
	correct_option.setPosition(315 + textpos.width, 540);
	correct_option.setFillColor(sf::Color::White);

	sf::FloatRect textpos1 = correct_option.getLocalBounds();

	correct.setFont(this->font);
	correct.setCharacterSize(30);
	correct.setString("is the correct Answer");
	correct.setPosition(330 + textpos.width + textpos1.width, 540);
	correct.setFillColor(sf::Color::White);
}

void FeedbackState::renderText(sf::RenderTarget* target)
{
	target->draw(this->text1);
	target->draw(this->correct_option);
	target->draw(this->feedback);
	target->draw(this->correct);
}

void FeedbackState::loadText()
{
	std::fstream file;
	file.open(genre, std::ios::in | std::ios::binary);
	file.seekp((question_num - 1) * sizeof(q));
	file.read(reinterpret_cast<char*>(&q), sizeof(q));
	char a = q.getCorrectOption();

	switch (a)
	{
	case 'a':
		correct_option.setString(q.getOptionA());
		break;
	case 'b':
		correct_option.setString(q.getOptionB());
		break;
	case 'c':
		correct_option.setString(q.getOptionC());
		break;
	case 'd':
		correct_option.setString(q.getOptionD());
		break;
	}

	if (u_opt == q.getCorrectOption())
	{
		this->initCorrectOptionText();
	}
	else
	{
		this->initInCorrectOptionText();
	}
}

void FeedbackState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateButtons();
}

void FeedbackState::updateInput(const float& dt)
{
}

void FeedbackState::render(sf::RenderTarget* target)
{
	this->renderButtons(target);
	this->renderText(target);
}
