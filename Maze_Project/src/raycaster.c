#include "../include/main.h"

/**
 * calculate_distances - Calculates all important coordinates at a given point.
 *
 * @object: Vector containing object coordinates
 * @rayDirX: Ray position and direction in x-axis
 * @rayDirY: Ray position and direction in y-axis
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @stepX: Direction to step in x-axis (+1 or -1)
 * @stepY: Direction to step in y-axis (+1 or -1)
 * @mapX: x-coordinate of current box of the map
 * @mapY: y-coordinate of current box of the map
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 */
void calculate_distances(Vector object, double rayDirX, double rayDirY,
                         double *sideDistX, double *sideDistY, int *stepX,
                         int *stepY, int mapX, int mapY, double deltaDistX,
                         double deltaDistY)
{
    *stepX = (rayDirX < 0) ? -1 : 1;
    *stepY = (rayDirY < 0) ? -1 : 1;

    *sideDistX = (rayDirX < 0) ? (object.posX - mapX) * deltaDistX :
                                  (mapX + 1.0 - object.posX) * deltaDistX;

    *sideDistY = (rayDirY < 0) ? (object.posY - mapY) * deltaDistY :
                                  (mapY + 1.0 - object.posY) * deltaDistY;
}

/**
 * DDA - Digital Differential Analysis
 *
 * @hit: 1 if wall was hit else 0
 * @side: Side of the wall that was hit (NS or EW)
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 * @mapX: x-coordinate of current box of the map
 * @mapY: y-coordinate of current box of the map
 * @stepX: Direction to step in x-axis (+1 or -1)
 * @stepY: Direction to step in y-axis (+1 or -1)
 * @worldMap: 2-dimensional array of integer values
 * Return: Code of the wall if wall was hit else 0
 */
int DDA(int *hit, int *side, double *sideDistX, double *sideDistY,
        double deltaDistX, double deltaDistY, int *mapX, int *mapY, int stepX,
        int stepY, int (*worldMap)[MAP_WIDTH])
{
    while (*hit == 0)
    {
        if (*sideDistX < *sideDistY)
        {
            *sideDistX += deltaDistX;
            *mapX += stepX;
            *hit = worldMap[*mapX][*mapY];
            *side = 0;
        }
        else
        {
            *sideDistY += deltaDistY;
            *mapY += stepY;
            *hit = worldMap[*mapX][*mapY];
            *side = 1;
        }
    }

    return *hit;
}

/**
 * raycaster - Performs raycasting operations.
 *
 * @object: Vector containing object coordinates
 * @time: Time of current frame
 * @oldTime: Time of previous frame
 * @instance: SDL_Instance struct
 * @event: SDL Event
 * @delay: Delay flag (true or false)
 * @keys: Boolean array to store key states
 * Return: 0 on success
 */
int raycaster(Vector object, double *time, double *oldTime,
              SDL_Instance *instance, SDL_Event *event, bool delay,
              const unsigned char *keys)
{
    while (!Finish(event, delay, keys))
        break;

    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
        double rayDirX = object.dirX + object.planeX * cameraX;
        double rayDirY = object.dirY + object.planeY * cameraX;

        int mapX = floor(object.posX);
        int mapY = floor(object.posY);

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

        double sideDistX, sideDistY, perpWallDist;
        int stepX, stepY, wall_height, wall_top, wall_bottom;
        int hit = 0, side = 0;
        int worldMap[MAP_WIDTH][MAP_HEIGHT];
        Map_Generator(worldMap);

        calculate_distances(object, rayDirX, rayDirY, &sideDistX, &sideDistY,
                            &stepX, &stepY, mapX, mapY, deltaDistX, deltaDistY);

        int wall_code = DDA(&hit, &side, &sideDistX, &sideDistY, deltaDistX,
                            deltaDistY, &mapX, &mapY, stepX, stepY, worldMap);

        calcuate_projection(side, sideDistX, sideDistY, deltaDistX, deltaDistY,
                            &perpWallDist, &wall_height, &wall_top, &wall_bottom);

        render_walls(instance->renderer, wall_top, wall_bottom, wall_code, side, x);
    }

    fps_count(time, oldTime);

    return 0;
}
