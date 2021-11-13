//
// Created by aniru on 11/12/2021.
//

#ifndef FINALPROJECTCS6010_BULLET_HPP
#define FINALPROJECTCS6010_BULLET_HPP


#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "ship.hpp"


class ship;

class bullet {
private:
    sf::RectangleShape theBullet; // The shape data

    // Color Data
    int red;
    int green;
    int blue;

    // Velocity
    int dx;
    int dy;


public:
    // Positional Data
    int x;
    int y;
    int xmax;
    int ymax;

    bullet(const ship & theShip); // Constructor

    //Main functions
    void interact(sf::RenderWindow & win);
    void draw(sf::RenderWindow & win);

    // Helper functions
    sf::RectangleShape getShape();
    void setBulletLocation(const int & xpos, const int & ypos);
    bool checkCollisionWindow(sf::RenderWindow & win);
    int xposition() const { return x;}
    int yposition() const { return y;}
};


#endif //FINALPROJECTCS6010_BULLET_HPP
