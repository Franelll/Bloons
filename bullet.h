#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <windows.h> // U¿ywaj z rozwag¹, Sleep jest blokuj¹cy!

class Bullet {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int damage;
    int speedX;
    int speedY;
    int size;
    float x;
    float y;
	float targetX;
	float targetY;
	float startX;
	float startY;

public:
	Bullet(int damage, float startX, float startY, float targetX, float targetY, int size)
		: damage(damage), startX(startX), startY(startY), targetX(targetX), targetY(targetY), size(size), x(startX), y(startY){

        sf::Image image;
        image.create(size, size, sf::Color::Transparent);

        int radius = size / 2;
        int center = radius;

        for (int j = 0; j < size; ++j)
        {
            for (int i = 0; i < size; ++i)
            {
                int dx = i - center;
                int dy = j - center;
                if (dx * dx + dy * dy <= radius * radius)
                {
                    image.setPixel(i, j, sf::Color::Yellow);
                }
            }
        }

        sf::Vector2f dir(targetX - startX, targetY - startY);
        float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
        if (length != 0.f) {
            dir /= length;
        }

        float speed = 5.f;
        speedX = dir.x * speed;
        speedY = dir.y * speed;
        
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
    }

    Bullet(const Bullet&) = delete;
    Bullet& operator=(const Bullet&) = delete;

    Bullet(Bullet&&) = default;
    Bullet& operator=(Bullet&&) = default;

    void update() {
        sprite.move(static_cast<float>(speedX), static_cast<float>(speedY));
        x += speedX;
        y += speedY;
        Sleep(100); // NIE u¿ywaj w grze!
    }

    void render(sf::RenderWindow& window) {
        window.draw(sprite);
    }
};