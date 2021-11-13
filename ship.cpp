//
// Created by aniru on 11/12/2021.
//


#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.hpp"

using namespace std;

/// SHIP
ship::ship(sf::RenderWindow & win) {
    // Set the radius and create the shape
    radius = 50.f;
    theShip = sf::CircleShape(radius, 3);

    //Set the color
    red = rand() % 255;
    blue = rand() % 255;
    green = rand() % 255;
    theShip.setFillColor(sf::Color(red, blue, green));

    //Set the position
    dx = 25;
    dy = 1;
    x = (win.getSize().x / 2) - 50;
    y = (win.getSize().y - 100);
    xmax = x + (radius * 2.f);
    ymax = y + (radius * 2.f);
    theShip.setPosition(x, y);
} // Constructor


void ship::interact(sf::RenderWindow & win) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (x - dx > 10) {
            x -= dx;
            theShip.setPosition(x, y);
        } // Move Left
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (x + dx < win.getSize().x - 110) {
            x += dx;
            theShip.setPosition(x, y);
        } // Move Right
    }
    xmax = x + (radius * 2.f);
    ymax = y + (radius * 2.f);
} // User Interaction Logic

void ship::draw(sf::RenderWindow & win) {
    win.draw(theShip);
} // Draw the ship

sf::CircleShape ship::getShape() {
    return theShip;
} // Get the sf::Shape type from class.

