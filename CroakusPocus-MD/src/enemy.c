#include "../inc/debuginfo.h"
#include "../inc/level.h"
#include "../inc/player.h"
#include "../inc/globals.h"
#include "../inc/camera.h"
#include "../inc/enemy.h"
#include "../inc/makemap.h"
#include <resources.h>

Sprite* cat;
Sprite* bee;
Sprite* rolypoly;
Sprite* rolypoly2;
Sprite* fly;
Sprite* ant;
u16 bugPosX = 0;
u16 bugPosY = 0;


void displayEnemy(u16 x, u16 y){
    PAL_setPalette(PAL3,bee_sprite.palette->data, DMA);
	//PAL_setPalette(PAL3,cat_sprite.palette->data, DMA);

	// cat = SPR_addSprite(&cat_sprite, fix32ToInt(bugPosX) - 96, fix32ToInt(bugPosY)- 48, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
	// SPR_setAnim(cat, 0);

	bee = SPR_addSprite(&bee_sprite, x, y, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
	SPR_setAnim(bee, 1);

	// rolypoly = SPR_addSprite(&rolypoly_sprite, fix32ToInt(bugPosX) + 16, fix32ToInt(bugPosY), TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
	// SPR_setAnim(rolypoly, 1);

	//rolypoly2 = SPR_addSprite(&rolypoly_sprite, fix32ToInt(bugPosX) + 16, fix32ToInt(bugPosY)+32, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
	//SPR_setAnim(rolypoly2, 0);

	// fly = SPR_addSprite(&fly_sprite, fix32ToInt(bugPosX)+32, fix32ToInt(bugPosY), TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
	// SPR_setAnim(fly, 0);

	// ant = SPR_addSprite(&ant_sprite, fix32ToInt(bugPosX), fix32ToInt(bugPosY), TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
	// SPR_setAnim(ant, 1);	
}
void updateEnemyPos(){
	bugPosX = SPR_getPositionX(bee);
	bugPosY =  SPR_getPositionY(bee);


}
void moveEnemy(){
	int dir = randSet(1,2,3,4);
	updateEnemyPos();
	switch(dir){
		case 1:
		SPR_setPosition(bee, bugPosX+4, bugPosY);

		break;
		case 2:
		SPR_setPosition(bee, bugPosX-4, bugPosY);

		break;
		case 3:
		SPR_setPosition(bee, bugPosX, bugPosY+4);

		break;
		case 4:
		SPR_setPosition(bee, bugPosX, bugPosY-4);

		break;

	}
}
