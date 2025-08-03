#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h> // For Sleep function


class Ballon {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int health;
    int speedX;
    int speedY;
    int sizeX;
    int sizeY;
    int x;
    int y;

public:
    Ballon(int health, int speedX, int speedY, int sizeX, int sizeY, int x, int y)
        : health(health), speedX(speedX), speedY(speedY), sizeX(sizeX), sizeY(sizeY), x(x), y(y)
    {
        sf::Image image;
        image.create(sizeX, sizeY, sf::Color::Red);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    }

    void update() {
        x += speedX;
        y += speedY;
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));

		if (y > 300) {
			speedY = 0;
            speedX = 5;

            // Stop moving down if it goes below a certain point
		}
        if (x > 800) {
            speedY = -5;
            speedX = 0; // Change direction if it goes too far right

        }




    }

    void render(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    void setDirection(int newSpeedX, int newSpeedY) {
        speedX = newSpeedX;
        speedY = newSpeedY;
    }

    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }

    int getHealth() const {
        return health;
    }

    void takeDamage(int dmg) {
        health -= dmg;
    }

    bool isDestroyed() const {
        return health <= 0;
    }
};