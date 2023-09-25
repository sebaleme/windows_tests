# fps

## Description
This project is a first person shooter, with the goal of learning more about game engine. \
The rendering is going to be implemented manually. No existing lib will be used except the SDL 
for accessing the peripherics. This game engine will only rely on the CPU. The player will have 
a first person view (isometric projection) and a 2d minimap (Bird s Eye View)

## Integration
The SDL lib is required. Either build it from the github repo or download the binaries from the
release server. You should copy the headers in external/include and the binaries in external/Release.
Note that SDL3 is expected by the project files (part of the path). As of september 2023, no SDL3 release
was available, so build from source was required.

## References
I use this tutorial as inspiration: \
https://www.youtube.com/watch?v=fSjc8vLMg8c \
https://www.parallelrealities.co.uk/tutorials/shooter/shooter1.php
