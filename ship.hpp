//
// Created by aniru on 11/12/2021.
//

#ifndef FINALPROJECTCS6010_SHIP_HPP
#define FINALPROJECTCS6010_SHIP_HPP

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "bullet.hpp"
#include "asteroids.hpp"

class ship {
private:
    sf::CircleShape theShip;
    int radius; // Radius of the ship

    // Color values
    int red;
    int green;
    int blue;



    // Velocity
    int dx;
    int dy;

public:
    // Positions
    int x;
    int y;
    int xmax;
    int ymax;

    ship(sf::RenderWindow & win); // Constructor

    // main functions
    void interact(sf::RenderWindow & win);
    void draw(sf::RenderWindow & win);

    // Helper functions
    sf::CircleShape getShape();
    int positionx() const { return x;}
    int positiony() const { return y;}
    int getRadius() const { return radius;}


};

#endif //FINALPROJECTCS6010_SHIP_HPP
