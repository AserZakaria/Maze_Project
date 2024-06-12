#include "../include/main.h"

/**
 * rgba_color_add - Add two ColorRGBA structs.
 *
 * @color1: The first ColorRGBA struct
 * @color2: The second ColorRGBA struct
 * Return: Sum ColorRGBA struct
 */
ColorRGBA rgba_color_add(ColorRGBA color1, ColorRGBA color2)
{
    ColorRGBA color;

    color.red = (color1.red + color2.red) % 255;
    color.green = (color1.green + color2.green) % 255;
    color.blue = (color1.blue + color2.blue) % 255;
    color.alpha = handle_mod1(color1.alpha + color2.alpha);

    return color;
}

/**
 * rgba_color_sub - Subtract two ColorRGBA structs.
 *
 * @color1: The first ColorRGBA struct
 * @color2: The second ColorRGBA struct
 * Return: Difference ColorRGBA struct
 */
ColorRGBA rgba_color_sub(ColorRGBA color1, ColorRGBA color2)
{
    ColorRGBA color;

    color.red = (color1.red - color2.red) % 255;
    color.green = (color1.green - color2.green) % 255;
    color.blue = (color1.blue - color2.blue) % 255;
    color.alpha = handle_mod1(color1.alpha - color2.alpha);

    return color;
}

/**
 * rgba_color_mul - Multiply two ColorRGBA structs.
 *
 * @color1: The first ColorRGBA struct
 * @color2: The second ColorRGBA struct
 * Return: Product ColorRGBA struct
 */
ColorRGBA rgba_color_mul(ColorRGBA color1, ColorRGBA color2)
{
    ColorRGBA color;

    color.red = (color1.red * color2.red) % 255;
    color.green = (color1.green * color2.green) % 255;
    color.blue = (color1.blue * color2.blue) % 255;
    color.alpha = handle_mod1(color1.alpha * color2.alpha);

    return color;
}

/**
 * rgba_color_div - Divide two ColorRGBA structs.
 *
 * @color1: The first ColorRGBA struct
 * @color2: The second ColorRGBA struct
 * Return: Quotient ColorRGBA struct
 */
ColorRGBA rgba_color_div(ColorRGBA color1, ColorRGBA color2)
{
    ColorRGBA color;

    color.red = (color1.red / color2.red) % 255;
    color.green = (color1.green / color2.green) % 255;
    color.blue = (color1.blue / color2.blue) % 255;
    color.alpha = handle_mod1(color1.alpha / color2.alpha);

    return color;
}

/**
 * rgba_color_comp - Compare two ColorRGBA structs.
 *
 * @color1: The first ColorRGBA struct
 * @color2: The second ColorRGBA struct
 * Return: 1 if equal, else -1
 */
int rgba_color_comp(ColorRGBA color1, ColorRGBA color2)
{
    if (!(color1.red == color2.red && color1.green == color2.green &&
          color1.blue == color2.blue && color1.alpha == color2.alpha))
        return -1;

    return 1;
}