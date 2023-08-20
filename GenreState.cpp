#include "GenreState.h"

void GenreState::initFonts()
{
}

GenreState::GenreState(sf::RenderWindow* window, std::stack<State*>* states) : State (window, states)
{
	this->font.loadFromFile("Fonts/ALGER.ttf");
	this->initButtons();
	this->initText();

	//this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	//this->background.setFillColor(sf::Color::Magenta);
}

GenreState::~GenreState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}

}

void GenreState::initButtons()
{
	this->buttons["AllGenre"] = new Button(250, 100, 150, 50, &this->font, "All Genre", sf::Color::Red,
		sf::Color::Blue, sf::Color::White);
	this->buttons["Technology"] = new Button(250, 200, 150, 50, &this->font, "Technology", sf::Color::Red,
		sf::Color::Blue, sf::Color::White);
	this->buttons["History"] = new Button(250, 300, 150, 50, &this->font, "HIstory", sf::Color::Red,
		sf::Color::Blue, sf::Color::White);
}

void GenreState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update(this->mousePosView);
	}
	//quit the state

	if (this->buttons["AllGenre"]->isPressed())
	{

		file.open("ProgramFile/files.dat", std::ios::out);
		if (file)
		{
			file << "Qns/allgenre.dat";
			file.close();
		}
		this->text2.setString("All Genre Selected");
		file.open("ProgramFile/highscorefile.dat", std::ios::out);
		if (file)
		{
			file << "Highscore/allgenrehighscore.txt";
			file.close();
		}
	}
	if (this->buttons["Technology"]->isPressed())
	{
		file.open("ProgramFile/files.dat", std::ios::out);
		if (file)
		{
			file << "Qns/tech.dat";
			file.close();
		}
		this->text2.setString("Technology Selected");
		file.open("ProgramFile/highscorefile.dat", std::ios::out);
		if (file)
		{
			file << "Highscore/techhighscore.txt";
			file.close();
		}
	}
	if (this->buttons["History"]->isPressed())
	{

		file.open("ProgramFile/files.dat", std::ios::out);
		if (file)
		{
			file << "Qns/history.dat";
			file.close();
		}
		this->text2.setString("History Selected");
		file.open("ProgramFile/highscorefile.dat", std::ios::out);
		if (file)
		{
			file << "Highscore/historyhighscore.txt";
			file.close();
		}
	}
}

void GenreState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : buttons)
	{
		it.second->render(target);
	}
}

 void GenreState::initText()
{
	this->text1.setFont(this->font);
	this->text1.setString("Press esc to exit");
	this->text1.setCharacterSize(15);
	this->text1.setPosition(10, 10);
	this->text1.setFillColor(sf::Color::White);

	this->text2.setFont(this->font);
	this->text2.setString("Select a Genre");
	this->text2.setCharacterSize(15);
	this->text2.setPosition(250, 50);
	this->text2.setFillColor(sf::Color::White);
}

void GenreState::renderText(sf::RenderTarget *target)
{
	target->draw(this->text1);
	target->draw(this->text2);
}

void GenreState::endState()
{
}

void GenreState::updateInput(const float& dt)
{
	this->checkForQuit();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		this->states->pop();
	}
}

void GenreState::update(const float& dt)
{
	this->updateInput(dt);
	this->updateMousePosition();

	this->updateButtons();
}

void GenreState::render(sf::RenderTarget* target)
{
	if (!target)
		target = (this->window);

	//target->draw(this->background);

	this->renderButtons(target);
	this->renderText(target);
}
