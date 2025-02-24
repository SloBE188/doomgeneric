#include "doomgeneric.h"
#include "../stdlib/syscall.h"
#include <stdio.h>

void DG_Init() 
{
    clear_screen(COLOR_BLACK);

}


void DG_SleepMs(uint32_t ms)
{}

void DG_SetWindowTitle(const char *title)
{}

uint32_t DG_GetTicksMs() 
{
    return get_ticks_doom();
}

void DG_DrawFrame(const uint8_t* buffer, int pitch) 
{
    if (!buffer) 
    {
        printf("ERROR: DG_DrawFrame received NULL buffer!\n");
        return;
    }
    if (pitch <= 0 || pitch > 4096) 
    {
        //printf("ERROR: DG_DrawFrame received invalid pitch: %d\n", pitch);
        return;
    }
    draw_frame_doom(buffer, pitch);
}





int DG_GetKey(int* pressed, unsigned char* key)
{
    uint32_t k = get_key_from_buffer();

    if (k == 0 || k > 0x7F)
    {
        return 0;
    }

    *pressed = 1;
    *key = (unsigned char) key;
    return 1;
    
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

