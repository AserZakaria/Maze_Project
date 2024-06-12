#ifndef _COLORS_H_
#define _COLORS_H_

/**
 * struct ColorRGBA - Represents an RGBA color.
 * @red: The red component of the color (0-255).
 * @green: The green component of the color (0-255).
 * @blue: The blue component of the color (0-255).
 * @alpha: The alpha component of the color (0.0 fully transparent, 1.0 fully opaque).
 */
typedef struct ColorRGBA
{
    Uint8 red;
    Uint8 green;
    Uint8 blue;
    float alpha;
} ColorRGBA;

/* Function to convert a color code str to a ColorRGBA structure */
ColorRGBA rgba_color_code(char *color);

/* Functions to perform arithmetic operations on ColorRGBA structures */
ColorRGBA rgba_color_add(ColorRGBA color1, ColorRGBA color2);
void rgba_add(ColorRGBA *color, int n, float a);

ColorRGBA rgba_color_sub(ColorRGBA color1, ColorRGBA color2);
void rgba_sub(ColorRGBA *color, int n, float a);

ColorRGBA rgba_color_mul(ColorRGBA color1, ColorRGBA color2);
void rgba_mul(ColorRGBA *color, int n, float a);

ColorRGBA rgba_color_div(ColorRGBA color1, ColorRGBA color2);
void rgba_div(ColorRGBA *color, int n, float a);

/* Function to compare two ColorRGBA structures */
int rgba_color_comp(ColorRGBA color1, ColorRGBA color2);

/* Function to get the color of a wall based on its code and side */
ColorRGBA color_wall(int wall_code, int side);

#endif /* _COLORS_H_ */
