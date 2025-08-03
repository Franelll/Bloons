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

    Monkey monkey{ 100, 10, 500, 50, 50, 100, 100, 100 };
    Ballon balon{ 100, 0, 5, 50, 50, 200, 0 };

    std::vector<Bullet> bullets;
    sf::Clock shootClock;
	

	


public:


    void update() {
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                window.close();
        }

        balon.update();
        monkey.update();

        if (shootClock.getElapsedTime().asMilliseconds() > monkey.getReloadTime()) {
            sf::Vector2f monkeyPos = monkey.getPosition();
            sf::Vector2f balonPos = balon.getPosition();

            if (Bullet::shouldShoot(monkeyPos.x, monkeyPos.y, balonPos.x, balonPos.y, monkey.getRadius())) {
                bullets.emplace_back(
                    monkey.getDamage(),
                    monkeyPos.x,
                    monkeyPos.y,
                    balonPos.x,
                    balonPos.y,
                    20
                );
                shootClock.restart();
            }
        }

        for (auto& bullet : bullets)
            bullet.update();
    }


    const sf::RenderWindow& getWindow() const {
        return this->window;
    }


    void render() {
        window.clear();

        monkey.render(window);
        balon.render(window);

        for (auto& bullet : bullets)
            bullet.render(window);

        window.display();
    }


    void run() {
        while (window.isOpen()) {
            update();
            render();
        }
    }
	Game() : window(sf::VideoMode(1200, 800), "Monkey Game") {
		window.setFramerateLimit(60);
	}
}; 
