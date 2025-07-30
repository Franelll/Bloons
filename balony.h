#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

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
	Ballon(int health, int speedX,int speedY, int sizeX, int sizeY, int x, int y)
		: health(health), speedX(speedX), speedY(speedY), sizeX(sizeX), sizeY(sizeY), x(x), y(y) {

		sf::Image image;
		image.create(sizeX, sizeY, sf::Color::Red);

		fillColor(image);

		
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
	}

	void update() {
		sprite.move(speedX, speedY);
		Sleep(100); // Simulate some delay for movement, adjust as needed


	}

	void render(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	void fillColor(sf::Image& image) {
		for (int y = 0; y < sizeY; ++y) {
			for (int x = 0; x < sizeX; ++x) {
				image.setPixel(x, y, sf::Color::Red); 
			}
		}
	}

};