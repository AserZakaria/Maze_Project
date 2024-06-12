#include "../include/main.h"

/**
 * deg - Convert a value from Gradients or Radians to Degrees.
 *
 * @val: Value in Gradients or Radians
 * @format: 'g' for Gradients, 'r' for Radians
 * Return: Value in Degrees, or -1 if the format is invalid
 */
double deg(float val, char format)
{
    if (format == 'g')
        val *= 0.9;
    else if (format == 'r')
        val = val * 180 / PI;
    else
        return -1;

    return val;
}

/**
 * rad - Convert a value from Degrees or Gradients to Radians.
 *
 * @val: Value in Degrees or Gradients
 * @format: 'd' for Degrees, 'g' for Gradients
 * Return: Value in Radians, or -1 if the format is invalid
 */
double rad(float val, char format)
{
    if (format == 'd')
        val = val * PI / 180;
    else if (format == 'g')
        val = val * PI / 200;
    else
        return -1;

    return val;
}

/**
 * grd - Convert a value from Degrees or Radians to Gradients.
 *
 * @val: Value in Degrees or Radians
 * @format: 'd' for Degrees, 'r' for Radians
 * Return: Value in Gradients, or -1 if the format is invalid
 */
double grd(float val, char format)
{
    if (format == 'd')
        val /= 0.9;
    else if (format == 'r')
        val = val * 200 / PI;
    else
        return -1;

    return val;
}
