# FPS: a Ray tracing implementation

The file "map_rendering_fv.cpp" implements a pseudo 3D rendering as in the early games from the 90's. Dispite the fact that the game itself is still 2D, it creates an isometric view of the environment which give the impression of a 3D view. The rendering is done through a pixel array. The role of the construct_world() function is to fill this array with the obstacle visible in the current Field Of View (FoV).

The function is organized as follow:

Compute current player cell \
loop over each column:
* Get the ray angle for current column
* Check which are the cell candidates for the current ray direction
* As long as it is empty, get the next cell and the intersection coordinates
* Once an obstacle has been reached, get the total ray distance
* Correct this distance against fish eye effect
* convert this distance into screen size
* Fill pixel array

The important point is that the intersection can only occurs in the cells intersections. That s the main reason why this design is fast, we don t need to test a lot of points. All the intersections can be computed through trigonometric formulas. \
Another aspect regarding the ray trajectory is that we always have 2 possibilities for the next cell. If the ray angle is in the quadrant [0,Pi/2], then next cell can only be the one above or the one to the right.

The object size is obtained through a geometric relation beween the player distance to the projection screen, the object distance, the projected object size and the real object size:









