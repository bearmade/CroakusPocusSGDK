#ifndef ENEMY_H
#define ENEMY_H

#include <genesis.h>

Sprite* cat;
Sprite* bee;
Sprite* rolypoly;
Sprite* rolypoly2;
Sprite* fly;
Sprite* ant;
u16 bugPosX;
u16 bugPosY;

void displayEnemy(u16 x, u16 y);
void updateEnemyPos();
void moveEnemy();

#endif