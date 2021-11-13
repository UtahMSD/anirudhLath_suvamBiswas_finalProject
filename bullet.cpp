//
// Created by aniru on 11/12/2021.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.hpp"


using namespace std;

/// BULLET

bullet::bullet(const ship & theShip) {

    sf::RectangleShape temp(sf::Vector2f(10.f,10.f));
    theBullet = temp;

    //Assign Color
    red = rand() % 255;
    blue = rand() % 255;
    green = rand() % 255;
    theBullet.setFillColor(sf::Color(red, blue, green));

    //Assign Position
    x = theShip.positionx() + theShip.getRadius() - 5.f;
    y = theShip.positiony() - 10.f;
    xmax = x + 10.f;
    ymax = y + 10.f;
    theBullet.setPosition(x, y);
    dx = 1.f;
    dy = 25.f;
}

void bullet::interact(sf::RenderWindow &win) {
    if (!checkCollisionWindow(win)) {
        y -= dy;
        ymax = y + 10.f;
        theBullet.setPosition(x, y);
    }
} // Move the bullet along the y axis when the user shoots.

void bullet::draw(sf::RenderWindow & win) {
    win.draw(theBullet);
} // Draw the bullets.

sf::RectangleShape bullet::getShape() {
    return theBullet;
} //Return sf::Shape of the bullet.

void bullet::setBulletLocation(const int & xpos, const int & ypos) {
    x = xpos;
    y = ypos;
    theBullet.setPosition(x, y);
} // Set the position in SFML library. Just a shortcut function.

bool bullet::checkCollisionWindow(sf::RenderWindow & win) {
    return (x >= win.getSize().x or
            y >= win.getSize().y or
            x <= 0 or
            y <= 0);
} // Check if the bullet hits the the top of the window.

