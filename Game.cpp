#include "Game.h"

//static function

//initialization function 

//Constructors and destructors

void Game::initWindows()
{
    /* Create an SFML Window using the parameters used in window.ini file. */

    std::ifstream ifs("configuration/window.ini");      //open the file

    std::string title = "Knowledgekicks";
    sf::VideoMode window_bounds(1920, 1080);
    unsigned framerate_limit = 30;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())      //getting the parameters from the file
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();        //Closing the file

	this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
    this->window->setKeyRepeatEnabled(false);
}

void Game::initStates()
{ 
    this->states.push(new MainMenuState(this->window, &this->states));
}

Game::Game()
{
    this->initWindows();

    this->initStates();

}

Game::~Game()
{
	delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

void Game::updatedt()
{
    /* Updates the dt vairiable with the time it takes to upadate and render a frame. */
    this->dt = this->dtClock.restart().asSeconds();

 /*   system("cls");
    std::cout << this->dt << std::endl;*/
}

void Game::updateSFMLevents()
{
    while (this->window->pollEvent(sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
 /*       if ()
        {
            this->window->close();
            std::cout << "henlo" << std::endl;
        }*/
        if (!this->states.empty())
            this->states.top()->update(this->dt);
    }
    
}

void Game::update()
{
    this->updateSFMLevents();


}

void Game::render()
{
    this->window->clear();

    //Render objects

    if (!this->states.empty())
        this->states.top()->render(this->window);

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updatedt();
        this->update();
        this->render();
    }
}
