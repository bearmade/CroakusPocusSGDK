#ifndef OPTION_H
#define OPTION_H

#include <genesis.h>

typedef struct
{
    u16 x;
    u16 y;
    char label[10];
} Option;

#define NUM_OPTIONS 3

Option options[];

u8 currentIndex;
Sprite *cursor;

void showCursor();
void updateCursorPosition();
void moveUp();
void moveDown();
void joyEventHandler(u16 joy, u16 changed, u16 state);
void select(u16 option);
void pickStart();
void pickOptions();
void pickExit();

#endif