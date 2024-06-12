#include "../include/main.h"

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    SDL_Instance instance;
    SDL_Event event = {0};
    const unsigned char keys[KEYS];
    Vector player;
    double time = 0;    // Time of current frame
    double oldTime = 0; // Time of previous frame
    _Bool quit = false; // Quit flag

    // Initialize player position and direction
    player.dirX = -1;
    player.dirY = 0;
    player.posX = 22;
    player.posY = 12;
    player.planeX = 0;
    player.planeY = 0.66;

    // Start up SDL and create window
    if (!Init_SDL(&instance))
    {
        fprintf(stderr, "Failed to initialize SDL!\n");
    }
    else
    {
        while (!quit)
        {
            SDL_SetRenderDrawColor(instance.renderer, 0x0, 0x0, 0x0, 0x0);
            SDL_RenderClear(instance.renderer);

            // Poll events and break if needed
            if (Events_POLL() == 1)
                break;

            // Perform raycasting and render the scene
            raycaster(player, &time, &oldTime, &instance, &event, true, keys);
            SDL_RenderPresent(instance.renderer);

            // Hack to keep the window open
            Window_Tool(&quit);
        }
        // Clean up SDL
        END(&instance);
    }
    return 0;
}