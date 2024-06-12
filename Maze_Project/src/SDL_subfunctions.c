#include "../include/main.h"

/**
 * Events_POLL - Polls for SDL events and returns if there's any.
 *
 * Returns:
 *     0 if no events, 1 if events
 */
int Events_POLL(void)
{
    SDL_Event event;
    SDL_KeyboardEvent key;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                return 1;
            case SDL_KEYDOWN:
                key = event.key;
                if (key.keysym.sym == SDLK_ESCAPE)
                    return 1;
                break;
        }
    }
    return 0;
}

/**
 * getTicks - Returns the time in milliseconds since the program started.
 *
 * Returns:
 *     Unsigned long value of the time in milliseconds
 */
unsigned long getTicks(void)
{
    return SDL_GetTicks();
}
