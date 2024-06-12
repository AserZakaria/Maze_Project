#include "../include/main.h"

/**
 * handle_mod1 - Handles modulo operation by 1.
 *
 * @target: The target value for the modulo operation
 * Return: Float value of the operation
 */
float handle_mod1(float target)
{
    if (target >= 1.0)
        return (target - (fabs(target)));
    else if (target <= -1.0)
        return (target + (fabs(target)) + 1);
    else
        return (target);
}

/**
 * rgba_add - Adds given values to the RGBA components of color.
 *
 * @color: Pointer to the target color
 * @r: Float value to add to the Red component
 * @g: Float value to add to the Green component
 * @b: Float value to add to the Blue component
 * @a: Float value to add to the Alpha component
 */
void rgba_add(ColorRGBA *color, float r, float g, float b, float a)
{
    color->red += r;
    color->green += g;
    color->blue += b;
    color->alpha += a;
    color->alpha = handle_mod1(color->alpha);
}

/**
 * rgba_sub - Subtracts given values from the RGBA components of color.
 *
 * @color: Pointer to the target color
 * @r: Float value to subtract from the Red component
 * @g: Float value to subtract from the Green component
 * @b: Float value to subtract from the Blue component
 * @a: Float value to subtract from the Alpha component
 */
void rgba_sub(ColorRGBA *color, float r, float g, float b, float a)
{
    color->red -= r;
    color->green -= g;
    color->blue -= b;
    color->alpha -= a;
    color->alpha = handle_mod1(color->alpha);
}

/**
 * rgba_mul - Multiplies RGBA components by given values.
 *
 * @color: Pointer to the target color
 * @r: Float value to multiply the Red component
 * @g: Float value to multiply the Green component
 * @b: Float value to multiply the Blue component
 * @a: Float value to multiply the Alpha component
 */
void rgba_mul(ColorRGBA *color, float r, float g, float b, float a)
{
    color->red *= r;
    color->green *= g;
    color->blue *= b;
    color->alpha *= a;
    color->alpha = handle_mod1(color->alpha);
}

/**
 * rgba_div - Divides RGBA components by given values.
 *
 * @color: Pointer to the target color
 * @r: Float value to divide the Red component
 * @g: Float value to divide the Green component
 * @b: Float value to divide the Blue component
 * @a: Float value to divide the Alpha component
 */
void rgba_div(ColorRGBA *color, float r, float g, float b, float a)
{
    color->red /= r;
    color->green /= g;
    color->blue /= b;
    color->alpha /= a;
    color->alpha = handle_mod1(color->alpha);
}
