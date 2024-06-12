#include "../include/main.h"

/**
 * Ver_Line - Draw a vertical line from (x,y1) to (x,y2) with given color.
 *
 * @x: Column iterator
 * @y1: Start coordinate of the line
 * @y2: End coordinate of the line
 * @color: Color of the line
 * @instance: SDL_Instance struct
 * Return: 1 on success, 0 on failure
 */
int Ver_Line(int x, int y1, int y2, ColorRGBA *color, SDL_Instance *instance)
{
    SDL_Surface *scr = instance->screenSurface;

    // Ensure y1 is less than y2
    if (y2 < y1)
    {
        y1 += y2;
        y2 = y1 - y2;
        y1 -= y2;
    }
    // Check if line is out of screen bounds
    if (y2 < 0 || y1 >= SCREEN_HEIGHT || x < 0 || x >= SCREEN_WIDTH)
        return 0;
    if (y1 < 0)
        y1 = 0;
    if (y2 >= SCREEN_WIDTH)
        y2 = SCREEN_HEIGHT - 1;

    Uint32 colorSDL = SDL_MapRGBA(scr->format, color->red, color->green,
                                  color->blue, (Uint8)(255 * color->alpha));
    Uint32 *bufp;

    bufp = (Uint32 *)scr->pixels + y1 * scr->pitch / 4 + x;
    unsigned int add = scr->pitch / 4;

    for (int y = y1; y <= y2; y++)
    {
        *bufp = colorSDL;
        bufp += add;
    }
    return 1;
}

/**
 * render_walls - Render the walls on the screen.
 *
 * @renderer: SDL renderer
 * @wall_top: Top coordinate of the wall
 * @wall_bottom: Bottom coordinate of the wall
 * @wall_code: Code of the wall
 * @side: Side of the wall (NS or EW)
 * @x: Column iterator
 */
void render_walls(SDL_Renderer *renderer, int wall_top, int wall_bottom,
                  int wall_code, int side, int x)
{
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        if (y < wall_top || y >= wall_bottom)
            continue;

        ColorRGBA color = color_wall(wall_code, side);

        SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue,
                               (Uint8)(255 * color.alpha));
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

/**
 * cls - Clear the screen and set its color to black.
 *
 * @scr: SDL Screen Surface
 */
void cls(SDL_Surface *scr)
{
    ColorRGBA color = rgba_color_code("black");
    Uint32 color_value = SDL_MapRGBA(scr->format, color.red, color.green,
                                     color.blue, (Uint8)(255 * color.alpha));

    SDL_FillRect(scr, NULL, color_value);
}

/**
 * fps_count - Calculate the frame rate and return its value.
 *
 * @time: Time of current frame in seconds
 * @oldTime: Time of previous frame in seconds
 * Return: Value of frame rate (FPS)
 */
int fps_count(double *time, double *oldTime)
{
    *oldTime = *time;
    *time = getTicks();

    double frameTime = (*time - *oldTime) / 1000.0;

    fprintf(stderr, "Frame rate: %lf FPS\n", 1.0 / frameTime);

    return frameTime;
}
