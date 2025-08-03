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
	float radius;

public:
	Monkey(int range, int damage, int reloadTime, int sizeX, int  sizeY, int x, int y, int radius)
		: range(range), damage(damage), reloadTime(reloadTime), sizeX(sizeX), sizeY(sizeY), x(x), y(y), radius(radius) {

		sf::Image image;
		image.create(sizeX, sizeY, sf::Color::Green);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
	}

	void update() {

	}
	void render(sf::RenderWindow & window ) {
		
			window.draw(sprite);

	}

	int getRadius() const { 
		return range; 
	}


	sf::Vector2f getPosition() const { 
		return sprite.getPosition(); 
	}


	int getDamage() const { 
		return damage; 
	}


	int getReloadTime() const { 
		return reloadTime; 
	}



	void fillColor(sf::Image& image) {
		for (int y = 0; y < sizeY; ++y) {
			for (int x = 0; x < sizeX; ++x) {
				image.setPixel(x, y, sf::Color::Green);
			}
		}
	}
};
