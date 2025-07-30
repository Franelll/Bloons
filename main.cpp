#include <SFML/Graphics.hpp>
#include <iostream>
#include "monkey.h"
#include "game.h"
#include "balony.h"
int main() {
	Game game;

    while (game.getWindow().isOpen()) {
        game.update();
        game.render();
    }

    return 0;
}