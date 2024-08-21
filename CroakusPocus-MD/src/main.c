#include <genesis.h>
#include <resources.h>
#include "../inc/level.h"
#include "../inc/debuginfo.h"
#include "../inc/player.h"
#include "../inc/camera.h"
#include "../inc/collision.h"
#include "../inc/globals.h"
#include "../inc/titlescreen.h"
#include "../inc/enemy.h"
#include "../inc/makemap.h"
#include "../inc/gamemanager.h"


#define SFX_SWOOSH 64




bool enemyFaceLeft = TRUE;
int hscrollOffset = 0;
fix32 enemySpeed = FIX32(0.1);

int main()
{
	VDP_setScreenWidth256();
	VDP_setScreenHeight224();
	JOY_setEventHandler(joyEvent);
	displayTitle();
	VDP_loadFontData(tileset_Font_Namco_Gradient.tiles, 96, CPU);
	PAL_setPalette(PAL3,palette_Font_Namco_Gradient.data, DMA);
	makeMap();
	bigMapCA();
	SPR_init();
	displayPlayer();
	XGM_setPCM(SFX_SWOOSH, sfx_swoosh, sizeof(sfx_swoosh));
	//XGM_startPlay(test_vgm);
	while(1)
	{
		if (attack_timer == 0) handleInput();
		else if (attack_timer > 0 && attack_timer < attack_duration) attack_timer += 1;
		else if (attack_timer == attack_duration) attack_timer = 0;

		collision();
		camera();

		char numberString[3];
		sprintf(numberString, "%u", currentWorldX);
		VDP_drawText(numberString, 24, 8);
		sprintf(numberString, "%u", currentWorldY);
		VDP_drawText(numberString, 26, 8);
		sprintf(numberString, "%u", WORLD_LAYOUT[currentWorldY][currentWorldX]);
		VDP_drawText(numberString, 28, 8);

		SPR_update();
		SYS_doVBlankProcess();
	}
	return (0);
}

