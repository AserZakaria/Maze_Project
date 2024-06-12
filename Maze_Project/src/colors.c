#include "../include/main.h"

/**
 * rgba_color_code - Returns the RGBA code of the requested color.
 *
 * @color: The color specified as a string
 * Return: ColorRGBA struct for the requested color
 */
ColorRGBA rgba_color_code(char *color)
{
    ColorRGBA RGB_Black = {0, 0, 0, 1.0};
    ColorRGBA RGB_Red = {255, 0, 0, 1.0};
    ColorRGBA RGB_Orange = {255, 165, 0, 1.0};
    ColorRGBA RGB_Yellow = {255, 255, 0, 1.0};
    ColorRGBA RGB_Green = {0, 128, 0, 1.0};
    ColorRGBA RGB_Blue = {0, 0, 255, 1.0};
    ColorRGBA RGB_Indigo = {75, 0, 130, 1.0};
    ColorRGBA RGB_Violet = {238, 130, 238, 1.0};
    ColorRGBA RGB_White = {255, 255, 255, 1.0};

    if (!strcmp(color, "red"))
        return RGB_Red;
    else if (!strcmp(color, "green"))
        return RGB_Green;
    else if (!strcmp(color, "blue"))
        return RGB_Blue;
    else if (!strcmp(color, "yellow"))
        return RGB_Yellow;
    else if (!strcmp(color, "orange"))
        return RGB_Orange;
    else if (!strcmp(color, "indigo"))
        return RGB_Indigo;
    else if (!strcmp(color, "violet"))
        return RGB_Violet;
    else if (!strcmp(color, "white"))
        return RGB_White;
    else if (!strcmp(color, "black"))
        return RGB_Black;
    else
        return RGB_Black; // Default to black
}

/**
 * color_wall - Assigns a color code to each integer case.
 *
 * @wall_code: Integer value for the wall
 * @side: Side of the wall that was hit (NS or EW)
 * Return: ColorRGBA for the requested color
 */
ColorRGBA color_wall(int wall_code, int side)
{
    ColorRGBA color;

    switch (wall_code)
    {
        case 1:
            color = rgba_color_code("red");
            break;
        case 2:
            color = rgba_color_code("green");
            break;
        case 3:
            color = rgba_color_code("blue");
            break;
        case 4:
            color = rgba_color_code("white");
            break;
        default:
            color = rgba_color_code("yellow");
            break;
    }

    // Adjust brightness for different sides
    if (side == 1)
        rgba_div(&color, 2, 1.0);

    return color;
}

/**
 * color_walls - Assigns a color code to each integer case.
 *
 * @worldMap: 2D array of integer values
 * @mapX: X-coordinate of the current map box
 * @mapY: Y-coordinate of the current map box
 * @color: ColorRGBA containing the RGBA value of given color
 * @side: Side of the wall that was hit (NS or EW)
 */
void color_walls(int (*worldMap)[MAP_WIDTH], int mapX, int mapY,
                ColorRGBA *color, int side)
{
    switch (worldMap[mapX][mapY])
    {
        case 1:
            *color = rgba_color_code("red");
            break;
        case 2:
            *color = rgba_color_code("green");
            break;
        case 3:
            *color = rgba_color_code("blue");
            break;
        case 4:
            *color = rgba_color_code("white");
            break;
        default:
            *color = rgba_color_code("yellow");
            break;
    }

    // Adjust brightness for different sides
    if (side == 1)
        rgba_div(color, 2, 1.0);
}
