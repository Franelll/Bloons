#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <windows.h> // U¿ywaj z rozwag¹, Sleep jest blokuj¹cy!

class Bullet {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speedX;
    float speedY;
    float x;
    float y;
    int size;


public:
    Bullet(int damage, float startX, float startY, float targetX, float targetY, int size)
        : x(startX), y(startY), size(size) {
        sf::Image image;
        image.create(size, size, sf::Color::Transparent);

        int radius = size / 2;
        int center = radius;

        for (int j = 0; j < size; ++j) {
            for (int i = 0; i < size; ++i) {
                int dx = i - center;
                int dy = j - center;
                if (dx * dx + dy * dy <= radius * radius) {
                    image.setPixel(i, j, sf::Color::Yellow);
                }
            }
        }

        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setPosition(x, y);

        float dx = targetX - startX;
        float dy = targetY - startY;
        float distance = std::sqrt(dx * dx + dy * dy);
        float speed = 50.f;

        if (distance != 0) {
            speedX = (dx / distance) * speed;
            speedY = (dy / distance) * speed;
        }
        else {
            speedX = 0;
            speedY = 0;
        }
    }

    static bool shouldShoot(float startX, float startY, float targetX, float targetY, float range) {
        float dx = targetX - startX;
        float dy = targetY - startY;
        float distance = std::sqrt(dx * dx + dy * dy);
        return distance <= range;
    }

    Bullet(const Bullet&) = delete;
    Bullet& operator=(const Bullet&) = delete;

    Bullet(Bullet&&) = default;
    Bullet& operator=(Bullet&&) = default;

    void update() {
        x += speedX;
        y += speedY;
        sprite.setPosition(x, y);
    }

    void render(sf::RenderWindow& window) {
        window.draw(sprite);
    }
    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }




};