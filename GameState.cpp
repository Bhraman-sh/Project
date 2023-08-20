#include "GameState.h"
#include<iomanip>

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color(128, 128, 128, 255));

	this->font.loadFromFile("Fonts/ALGER.ttf");
	this->initGui();
	this->initText();

	//buttons
	file.open("ProgramFile/files.dat", std::ios::in);
	if (file)
	{
		std::stringstream buffer;
		buffer << file.rdbuf();
		str = buffer.str();
		file.close();
	}
	this->askQuestion(file, q);
	
	
}

GameState::~GameState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void GameState::initButtons()
{
	this->buttons["OptionA"] = new Button(325, 350, 250, 50, &this->font, q.getOptionA() , sf::Color::Red,
		sf::Color::Blue, sf::Color::White);	
	this->buttons["OptionB"] = new Button(725, 350, 250, 50, &this->font, q.getOptionB(), sf::Color::Red,
		sf::Color::Blue, sf::Color::White);
	this->buttons["OptionC"] = new Button(325, 500, 250, 50, &this->font, q.getOptionC(), sf::Color::Red,
		sf::Color::Blue, sf::Color::White);
	this->buttons["OptionD"] = new Button(725, 500, 250, 50, &this->font, q.getOptionD(), sf::Color::Red,
		sf::Color::Blue, sf::Color::White);
}

void GameState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update(this->mousePosView);
	}
	if (this->buttons["OptionA"]->isPressed())
	{
		opt = 'a';
		this->verifyAnswer(file, q);
	}
	if (this->buttons["OptionB"]->isPressed())
	{
		opt = 'b';
		this->verifyAnswer(file, q);
	}
	if (this->buttons["OptionC"]->isPressed())
	{
		opt = 'c';
		this->verifyAnswer(file, q);
	}
	if (this->buttons["OptionD"]->isPressed())
	{
		opt = 'd';
		this->verifyAnswer(file, q);
	}
}

void GameState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : buttons)
	{
		it.second->render(target);
	}
}

void GameState::deleteButtons()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void GameState::initText()	
{


	this->text.setFont(this->font);
	/*this->text.setString("Load qn from file");*/
	this->text.setCharacterSize(30);	
	this->text.setPosition(650, 300);
	this->text.setFillColor(sf::Color::White);

	this->text1.setFont(this->font);
	this->text1.setString("Press esc to exit");
	this->text1.setCharacterSize(15);
	this->text1.setPosition(10, 10);
	this->text1.setFillColor(sf::Color::White);
}

void GameState::renderText(sf::RenderTarget* target)
{
	target->draw(this->text);
	target->draw(this->text1);
}

void GameState::initGui()
{
	brainTex.loadFromFile("Resources/brain.png");
	brain.setTexture(brainTex);
	brain.setScale(sf::Vector2f(1.1f, 1.1f));	
}

void GameState::renderGui(sf::RenderTarget* target)
{
	target->draw(background);
	//target->draw(this->brain);
}

void GameState::endstate()
{
}

void GameState::askQuestion(std::fstream &file, Question &q)
{
	i = getQnNumber();
	setQnNumber();
	file.open(str, std::ios::in | std::ios::binary);
	file.seekp((i-1) * sizeof(q));

	file.read(reinterpret_cast<char*>(&q), sizeof(Question));

		this->text.setString(q.getQuestion());

		this->setQuestionPos();

		this->initButtons();
	
	//if(i == 11)
	//{
	//	file.close();

	//	file.open("ProgramFile/Score.dat", std::ios::out);
	//	if (file)
	//	{
	//		std::cout << j;
	//		file << j;
	//		file.close();
	//	}
	//	this->states->push(new FinishState(this->window, this->states));
	//	ScoreCompare s;
	//	s.compareScore(j);
	//}
}

void GameState::setQuestionPos()
{
	sf::FloatRect position;
	position = this->text.getLocalBounds();
	std::cout << position.width << " " << position.height;
	this->text.setOrigin(position.width / 2, position.height);
}

void GameState::verifyAnswer(std::fstream& file, Question& q)
{
	uo[i - 1] = opt;
	if (q.getCorrectOption() == opt)
	{
		++j;
	}
	this->setOption();
	this->deleteButtons();
	this->file.close();
	if (i >= 11)
	{
		file.close();

		file.open("ProgramFile/Score.dat", std::ios::out);
		if (file)
		{
			std::cout << j;
			file << j;
			file.close();
		}
		this->states->push(new FinishState(this->window, this->states));
		ScoreCompare s;
		s.compareScore(j);
		this->states->pop();
	}
	else
	{
		this->states->push(new FeedbackState(this->window, this->states));
		this->askQuestion(file, q);
	}
}

int GameState::getQnNumber()
{
	std::fstream question;
	std::stringstream buffer;
	std::string number;
	question.open("ProgramFile/questionnumber.txt", std::ios::in);
	buffer << question.rdbuf();
	number = buffer.str();
	question.close();
	return std::stoi(number);
}

void GameState::setQnNumber()
{
	std::fstream question;
	std::stringstream buffer;
	std::string number;
	question.open("ProgramFile/questionnumber.txt", std::ios::in);
	buffer << question.rdbuf();
	number = buffer.str();
	int num = std::stoi(number);
	question.close();
	
	num++;
	question.open("ProgramFile/questionnumber.txt", std::ios::out);
	question << num;
	question.close();
}

void GameState::setOption()
{
	std::fstream option;
	option.open("ProgramFile/chosenoption.txt", std::ios::out);
	option << opt;
	option.close();
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		std::fstream question;
		int num = 1;
		question.open("ProgramFile/questionnumber.txt", std::ios::out);
		question << num;
		question.close();
		this->states->pop();
	}
	//update inputs of player
}

void GameState::update(const float& dt)
{
	this->updateInput(dt);
	this->updateMousePosition();
	this->updateButtons();
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	target = (this->window);
	
	this->renderGui(target);
	this->renderText(target);
	this->renderButtons(target);
	
}

