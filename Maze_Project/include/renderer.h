#ifndef _RENDERING_H_
#define _RENDERING_H_

/* Constants for rendering */
#define MINIMAP_DIVIDER 16          // Divider for minimap size reduction
#define MINIMAP_PLAYER_WIDTH 4      // Width divider for minimap player
#define MINIMAP_PLAYER_HEIGHT 4     // Height divider for minimap player

/* Function prototypes */
void render_walls(SDL_Renderer *renderer, int wall_top, int wall_bottom,
                  int wall_code, int side, int x);

#endif /* _RENDERING_H_ */
