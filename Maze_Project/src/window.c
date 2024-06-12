#include "../include/main.h"

/**
 * Init_SDL - Initializes SDL and creates window and renderer.
 *
 * @instance: An SDL instance of type struct SDL_Instance
 * Return: Boolean success flag (true or false)
 */
bool Init_SDL(SDL_Instance *instance)
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Failed to initialize SDL! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        instance->window = SDL_CreateWindow("The Maze Project",
                                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (instance->window == NULL)
        {
            fprintf(stderr, "SDL failed to create Window! SDL_Error: %s\n", SDL_GetError());
            SDL_Quit();
            success = false;
        }
        else
        {
            instance->renderer = SDL_CreateRenderer(instance->window, -1,
                                                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (instance->renderer == NULL)
            {
                fprintf(stderr, "Failed to create Renderer! SDL_Error: %s\n", SDL_GetError());
                SDL_Quit();
                success = false;
            }
        }
    }
    return success;
}

/**
 * Media_loader - Loads media into an SDL_Surface.
 *
 * @instance: An SDL instance of type struct SDL_Instance
 * @media_path: The relative path to the media
 * Return: Boolean success flag (true or false)
 */
bool Media_loader(SDL_Instance *instance, char *media_path)
{
    bool success = true;
    instance->image = SDL_LoadBMP(media_path);
    if (instance->image == NULL)
    {
        fprintf(stderr, "Unable to load image %s! SDL Error: %s\n", media_path, SDL_GetError());
        success = false;
    }
    return success;
}

/**
 * Color_filler - Fills an SDL Screen Surface with a specified color.
 *
 * @instance: An SDL instance of type struct SDL_Instance
 * @color_name: The name of the color as a string
 */
void Color_filler(SDL_Instance *instance, char *color_name)
{
    ColorRGBA fill_color = rgba_color_code(color_name);
    SDL_FillRect(instance->screenSurface, NULL,
                 SDL_MapRGBA(instance->screenSurface->format,
                             fill_color.red, fill_color.green, fill_color.blue,
                             (Uint8)(255 * fill_color.alpha)));
    SDL_UpdateWindowSurface(instance->window);
}

/**
 * END - Frees resources and quits SDL subsystems.
 *
 * @instance: An SDL instance of type struct SDL_Instance
 */
void END(SDL_Instance *instance)
{
    SDL_FreeSurface(instance->image);
    instance->image = NULL;
    SDL_FreeSurface(instance->screenSurface);
    instance->screenSurface = NULL;
    SDL_DestroyRenderer(instance->renderer);
    instance->renderer = NULL;
    SDL_DestroyWindow(instance->window);
    instance->window = NULL;
    SDL_Quit();
}

/**
 * Window_Tool - Keeps the SDL window open until closed.
 *
 * @quit: A boolean flag to keep the window open
 */
void Window_Tool(bool *quit)
{
    SDL_Event event;
    while (*quit == false)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                *quit = true;
                break;
            }
        }
    }
}