#include "doomgeneric.h"
#include "../stdlib/syscall.h"
#include <stdio.h>
#include "i_video.h"
#include "doomkeys.h"

void DG_Init() 
{
    clear_screen(COLOR_BLACK);
    DG_ScreenBuffer = (uint32_t*)malloc(640 * 400 * 4);

}


void DG_SleepMs(uint32_t ms)
{}

void DG_SetWindowTitle(const char *title)
{}

uint32_t DG_GetTicksMs() 
{
    return get_ticks_doom();
}

void DG_DrawFrame() 
{

    
    draw_frame_doom(I_VideoBuffer, 320);
}

static unsigned char convertToDoomKey(uint32_t scancode)
{
    unsigned char key = 0;

    switch (scancode)
    {
    case 0xFFFFFFBF:
        key = KEY_ENTER;
        break;
    case 0xFFFFFFE1:
        key = KEY_ESCAPE;
        break;
    case 0xFFFFFFF5:
        key = KEY_LEFTARROW;
        break;
    case 0xFFFFFFF6:
        key = KEY_RIGHTARROW;
        break;
    case 0xFFFFFFF4:
        key = KEY_UPARROW;
        break;
    case 0xFFFFFFF7:
        key = KEY_DOWNARROW;
        break;
    case 0xFFFFFFE4:
        key = KEY_RSHIFT;
        break;
    default:
        break;
    }

    return key;
}





int DG_GetKey(int* pressed, unsigned char* key)
{
    uint32_t k = get_key_from_buffer();
    if (k == 0) {

        return 0;
    }

    *pressed = 1;

    //normal asci, doom can use this directly
    if (k < 0x80) {
        *key = (unsigned char)k;
        return 1;
    }else
    {
        *key  = convertToDoomKey(k);
        return 1;
    }

    
}




int doom_main(void)
{
    char* argv[] = {"doomgeneric", "0:/doom1.wad", NULL};
    int argc = 2;
    printf("starting doomgeneric on senob\n");
    doomgeneric_Create(argc, argv);


    for (int i = 0; ; i++)
    {
        doomgeneric_Tick();
    }

    return 0;
}

