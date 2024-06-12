#include "../include/main.h"

/**
 * Random_Draw - Draw a basic line.
 *
 * @instance: SDL instance of type SDL_Instance
 */
void Random_Draw(SDL_Instance *instance)
{
    SDL_SetRenderDrawColor(instance->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(instance->renderer, 10, 10, 100, 100);
}

/**
 * MiniMap_draw - Draw the minimap.
 *
 * @WorldMap: The map to draw
 * @instance: The SDL_Instance to draw to
 * @player: The player to draw
 */
void MiniMap_draw(int (*WorldMap)[MAP_WIDTH], SDL_Instance *instance,
                 Vector player)
{
    SDL_Rect curRect;
    ColorRGBA color;

    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            SDL_Rect rect = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};

            color_walls(WorldMap, x, y, &color, 0);
            SDL_SetRenderDrawColor(instance->renderer, color.red, color.green,
                                   color.blue, (Uint8)(255 * color.alpha));
            SDL_RenderFillRect(instance->renderer, &rect);
        }
    }

    // Draw player
    curRect.x = player.posX * TILE_SIZE;
    curRect.y = player.posY * TILE_SIZE;
    curRect.w = TILE_SIZE;
    curRect.h = TILE_SIZE;
    color = rgba_color_code("indigo");
    SDL_SetRenderDrawColor(instance->renderer, color.red, color.green,
                           color.blue, (Uint8)(255 * color.alpha));
    SDL_RenderFillRect(instance->renderer, &curRect);

    // Update screen
    SDL_RenderPresent(instance->renderer);
}

/**
 * Image_drawer - Draw an image onto the SDL screen surface.
 *
 * @instance: SDL instance of type SDL_Instance
 */
void Image_drawer(SDL_Instance *instance)
{
    // Apply the image
    SDL_BlitSurface(instance->image, NULL, instance->screenSurface, NULL);
    // Update the surface
    SDL_UpdateWindowSurface(instance->window);
}
