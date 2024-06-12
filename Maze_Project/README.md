# alx-maze_project
This is Maze project for ALX Software Engineering program.

# **Maze Project**

## Background Context

The goal of this project is to create a game in 3D using raycasting!

## Tasks

### 0. Walls!

In this first part, you’ll have to:
* Create a window with SDL2
* Use [raycasting](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) to draw walls on your window!
* You don’t need to be able to rotate the camera during the execution in this part, but you must provide a way to change the angle of the camera in your code to see if it works after recompiling it
* The color of the walls must be different from the color of the ground/ceil
* The map doesn’t need to be parsed from a file, but you must provide a way to modify it in your code to see if it works after recompiling it (e.g., using an array of arrays of integers or characters)

### 1. Orientation

In this part, you must draw a different color depending on the orientation of the walls.
* You must at least draw walls facing `NORTH and SOUTH` in a different color from walls facing `EAST and WEST`

### 2. Rotation

You must provide a way to rotate the camera during the execution.
* For example, you can rotate the camera when the `left, right` arrows are pressed on the keyboard
* Or you can rotate the camera when the mouse moves, just like in an FPS game!

### 3. Move

You must provide a way to move the camera during the execution.
* For example, you can move the camera when the `w, a, s, d` keys are pressed on the keyboard

### 4. Ouch!

In this part, you must handle the collisions of the player (yes, let’s call the camera `player` now, it’s getting serious) with the walls.
* The player must not be able to enter walls
* You can make the player slide on the walls instead of just stop it

### 5. Parser

In this part you must implement a parser to get the map from a file.
* You are free to define the standards of your map (The character for a wall, the character for nothing, the extension of the file if you want, …)
* Your program will need a parameter to run which will be the path to the map file

### 6. Draw the Map

In this part, you must draw the map on the window.
* You’re free to draw the map where you want, with the color you want, …
* You must provide a way to enable/disable it during the execution
* Include the player’s line of sight in the map

### 7. Coding Style + Documentation

* Check if your code fits the [Holberton School coding style](https://github.com/holbertonschool/Betty/wiki)
* Check if your code is well documented and respects the [Holberton School documentation format](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)

You can check all of this by yourself, just follow the instructions on this [repository](https://github.com/holbertonschool/Betty).

**Be careful:**

The check will be done on each file present in your repository. Even the files that were not required. So don’t forget to always keep your directory clean.

### 8. Textures

In this part, you have to add textures to your walls!

### 9. Multi-task!

Add a way to move in several directions and rotate at the same time. Basically, in this part, you’ll have to handle multiple events in the same frame.

For example, if the keys to move are `w, a, s, d`:
* If the keys `w` and `s` are pressed at the same time, the player shouldn’t move
* If the keys `w` and `d` are pressed at the same time, the player should move forward and right at the same time
* …

### 10. Ground Textures

In this part, you have to add textures to the ground and/or the ceiling!

### 11. Weapons

Add weapon textures!

### 12. Enemies

Add some enemies!

### 13. Make It Rain

Add rain and a possibility to stop/start the rain with a key.

### 14. Extra Options

Shadows, special lighting, etc… get creative!
