# pragma once
#include <SFML/Graphics.hpp>



class Monkey {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int range;
	int damage;
	int reloadTime;
	int sizeX;
	int sizeY;
	int x;
	int y;


public:
	Monkey(int range, int damage, int reloadTime, int sizeX, int  sizeY, int x, int y)
		: range(range), damage(damage), reloadTime(reloadTime), sizeX(sizeX), sizeY(sizeY), x(x), y(y) {

		sf::Image image;
		image.create(sizeX, sizeY, sf::Color::Transparent);

		fillColor(image);

	
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
	}

	void update() {

	}
	void render(sf::RenderWindow & window ) {
		
			window.draw(sprite);

	}
	void fillColor(sf::Image& image) {
		for (int y = 0; y < sizeY; ++y) {
			for (int x = 0; x < sizeX; ++x) {
				image.setPixel(x, y, sf::Color::Green);
			}
		}
	}
};
