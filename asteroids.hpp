//
// Created by aniru on 11/12/2021.
//

#ifndef FINALPROJECTCS6010_ASTEROIDS_HPP
#define FINALPROJECTCS6010_ASTEROIDS_HPP


#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "ship.hpp"
#include "bullet.hpp"

class bullet;
class ship;

class asteroid {
private:
    sf::CircleShape theAsteroid; // Shape data
    int radius; // Radius of the asteroid

    // Color Data
    int red;
    int green;
    int blue;

    // Velocity
    int dx;
    int dy;

public:
    // Public variables to check collisions
    int x;
    int xmax;
    int y;
    int ymax;
    asteroid(sf::RenderWindow & win); // Constructor

    // Main functions
    void draw(sf::RenderWindow & win);
    void update();
    void destructColor(sf::RenderWindow & win);

    //Helper functions
    sf::CircleShape getShape() const { return theAsteroid;}
};

bool checkCollision(asteroid &theAsteroid, bullet &theBullet); // Check collisions declarations
bool checkCollision(asteroid &theAsteroid, ship &theShip); // Check collisions declarations
bool checkCollision(asteroid &theAsteroid, int height); // Check collisions with the edge of screen


#endif //FINALPROJECTCS6010_ASTEROIDS_HPP
