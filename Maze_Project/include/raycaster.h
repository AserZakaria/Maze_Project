#ifndef _RAYCASTER_H_
#define _RAYCASTER_H_

/**
 * struct Vector - Represents an object's coordinates and direction vectors.
 * @posX: x-coordinate of the object
 * @posY: y-coordinate of the object
 * @dirX: x-coordinate direction vector
 * @dirY: y-coordinate direction vector
 * @planeX: x-coordinate of the object on the camera plane
 * @planeY: y-coordinate of the object on the camera plane
 *
 * Description: Contains coordinates and direction vectors of an object.
 */
typedef struct Vector
{
    int posX;
    int posY;
    int dirX;
    int dirY;
    int planeX;
    int planeY;
} Vector;

/**
 * struct Projection - Represents projection information for drawing.
 * @drawStart: Starting pixel coordinate for projection
 * @drawEnd: Ending pixel coordinate for projection
 *
 * Description: Contains projection information for rendering.
 */
typedef struct Projection
{
    int drawStart;
    int drawEnd;
} Projection;

/* Function prototypes */
void calculate_distances(Vector object, double rayDirX, double rayDirY,
                         double *sideDistX, double *sideDistY, int *stepX,
                         int *stepY, int mapX, int mapY, double deltaDistX,
                         double deltaDistY);
Projection calculate_projection(int side, double sideDistX, double sideDistY,
                                double deltaDistX, double deltaDistY,
                                double *perpWallDist, int *wall_height,
                                int *wall_top, int *wall_bottom);
int fps_count(double *time, double *oldTime);
unsigned long getTicks(void);
void cls(SDL_Surface *scr);

#endif /* _RAYCASTER_H_ */
