//
// Created by aniru on 11/12/2021.
//


#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.hpp"


using namespace std;

/// ASTEROID
asteroid::asteroid(sf::RenderWindow & win) {
    // Set the radius and create the asteroid.
    radius = (rand() % (win.getSize().x / 15)) + 70.f;
    theAsteroid = sf::CircleShape(radius, 10.f);

    //Assign a color
    red = rand() % 255;
    blue = rand() % 255;
    green = rand() % 255;
    dx = 0;
    dy = rand() % 10;
    theAsteroid.setFillColor(sf::Color(red, blue, green));

    //Set the position
    x = (rand() % win.getSize().x ) - radius;
    y = radius * -2.f;
    xmax = x + (radius * 2.f);
    ymax = y + (radius * 2.f);
    theAsteroid.setPosition(x, y);
}


void asteroid::draw(sf::RenderWindow & win) {
    win.draw(theAsteroid);
} // Draw the asteroids.

void asteroid::update() {
    y += dy;
    ymax = y + (radius * 2) ;
    theAsteroid.setPosition(x, y);
} // Move the asteroids down

void asteroid::destructColor(sf::RenderWindow & win) {
    green = 0;
    theAsteroid.setFillColor(sf::Color(red, green, blue));
    draw(win);
    theAsteroid.setFillColor(sf::Color(0, 0, 0));

}

bool checkCollision(asteroid &theAsteroid, bullet &theBullet) {
    if (theBullet.y <= theAsteroid.ymax and theBullet.x >= theAsteroid.x and theBullet.x <= theAsteroid.xmax) {
        return true;
    }
    return false;
} // Check collision between the asteroid and the bullet.

bool checkCollision(asteroid &theAsteroid, ship &theShip) {
    if ((theAsteroid.ymax >= theShip.y and theAsteroid.y <= theShip.y) and
        (theAsteroid.x <= theShip.x and theAsteroid.xmax >= theShip.xmax)) {
        return true;
    }
    return false;
} // Check collision between the asteroid and the bullet.


bool checkCollision(asteroid &theAsteroid, int height) {
    if (theAsteroid.ymax >= height) {
        return true;
    }
    return false;
} // Check collision between the asteroid and the bullet.


