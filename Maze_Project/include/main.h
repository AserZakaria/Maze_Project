#ifndef _MAIN_H_
#define _MAIN_H_

#include "colors.h"
#include "raycaster.h"
#include "renderer.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include "applied_math.h"

/* Screen and map dimensions */
#define SCREEN_WIDTH 650
#define SCREEN_HEIGHT 490
#define MAP_WIDTH 25
#define MAP_HEIGHT 25
#define BLOCK_HEIGHT 65
#define PLAYER_HEIGHT 33
#define TILE_SIZE 17

/* Game settings */
#define FOV 66
#define COLOR_DEPTH 32
#define KEYS 322

/* Boolean values */
#define false 0
#define true 1
typedef _Bool bool;

/**
 * struct SDL_Instance - Represents an SDL instance with window, renderer, surface, and image.
 * @window: SDL Window to render to
 * @renderer: SDL Renderer
 * @screenSurface: SDL Screen Surface contained by the window
 * @image: Image to load and display on the screen
 */
typedef struct SDL_Instance
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *screenSurface;
    SDL_Surface *image;
} SDL_Instance;

/* SDL management functions */
void Color_filler(SDL_Instance *instance, char *color_name);
void END(SDL_Instance *instance);
_Bool Media_loader(SDL_Instance *instance, char *media_path);
_Bool Finish(SDL_Event *event, bool delay, const unsigned char *keys);
void Keys_READ(const unsigned char *keys);
int Events_POLL(void);
_Bool Init_SDL(SDL_Instance *instance);
void Window_Tool(bool *quit);

/* Drawing functions */
void Image_drawer(SDL_Instance *instance);
void MiniMap_draw(int (*WorldMap)[MAP_WIDTH], SDL_Instance *instance, Vector player);
void Random_Draw(SDL_Instance *instance);

/* Map generation function */
void Map_Generator(int (*worldMap)[MAP_WIDTH]);

/* Raycasting functions */
int raycaster(Vector object, double *time, double *oldTime, SDL_Instance *instance, SDL_Event *event, bool delay, const unsigned char *keys);
int DDA(int *hit, int *side, double *sideDistX, double *sideDistY, double deltaDistX, double deltaDistY, int *mapX, int *mapY, int stepX, int stepY, int (*worldMap)[MAP_WIDTH]);
int Ver_Line(int x, int y1, int y2, ColorRGBA *color, SDL_Instance *instance);

/**
 * color_walls - Assigns a color code to each map case based on wall side hit.
 * @worldMap: 2D array representing the map
 * @mapX: x-coordinate of the current map box
 * @mapY: y-coordinate of the current map box
 * @color: ColorRGBA structure for the wall's color
 * @side: Side of the wall that was hit (NS or EW)
 */
void color_walls(int (*worldMap)[MAP_WIDTH], int mapX, int mapY, ColorRGBA *color, int side);

#endif /* _MAIN_H_ */
