#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "monkey.h"
#include "balony.h"
#include "bullet.h"
#include <windows.h> // U¿ywaj z rozwag¹, Sleep jest blokuj¹cy!
class Game
{
private:
    sf::RenderWindow window;
    sf::Event ev;
	Monkey monkey{ 100, 10, 5, 50, 50, 100, 100 };

	Ballon balon{ 100, 0, 5, 50, 50, 100, 100 };

	Bullet bullet{ 10, 5, 5, 10, 90, 100 };

	


public:
    void update() {
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                window.close();
            }
        }
        Sleep(100);
    }
    const sf::RenderWindow& getWindow() const {
        return this->window;
    }
    void render() {

        this->window.clear();
		monkey.update();
		monkey.render(this->window);
		balon.render(this->window);
        balon.update();
		bullet.update();
		bullet.render(this->window);

	

        this->window.display();

    }
    Game() {
        this->window.create(sf::VideoMode(1200, 1000), "SFML works!");
    }
}; 
