#include "../include/main.h"

/**
 * Finish - Handles events per frame and returns true if the window is closed or
 * the escape key is pressed.
 *
 * @event: An SDL Event
 * @delay: The delay flag (true or false)
 * @keys: A boolean array to store key states
 * Return: Boolean success flag (true or false)
 */
bool Finish(SDL_Event *event, bool delay, const unsigned char *keys)
{
    /* Delay gives CPU some free time */
    /* Use once per frame to avoid 100% usage of a CPU core */
    if (delay)
        SDL_Delay(5); /* So it consumes less processing power */
    SDL_PollEvent(event);
    /* Check if the window is closed or escape key is pressed */
    if (event->type == SDL_QUIT || keys[SDLK_ESCAPE])
        return true;

    return false;
}

/**
 * Keys_READ - Updates the keys array with the current state of the keyboard.
 *
 * @keys: A boolean array to store key states
 */
void Keys_READ(const unsigned char *keys)
{
    SDL_PumpEvents();
    keys = SDL_GetKeyboardState(NULL);
    for (int i = 0; i < 1; i++)
    {
        if (keys[i] == 1)
            break;
    }
}
