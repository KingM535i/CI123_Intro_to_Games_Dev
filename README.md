# Modified by Martin King for CI123 Intro to Games Dev #



To build program with a terminal navigate to directory "/StarshipFontana-master"
Enter the following to a terminal:

g++ -c -std=c++11 src/*.cpp
g++ -o starship *.o -lSDL2 -lSDL2_image

To run program enter the following to the terminal:

./starship



Code::Blocks IDE v16.01 used to modify sample code
Unable to build & run program with Code::Blocks due to issues between Code::Blocks & SDL2



# Modifications #


1: Functions added to allow player object to move up & down.

2: Code for firing bullets commented out. Code left as it could be reinstated to create a tank style game.

3: Code modified to randomly generate starting positions of player, coins & aliens.
	True random generation attempted using "srand(time(NULL))" function, but all objects spawned in the same place
	due to function being called much faster than random number being updated. Using "SDL_Delay()" on each function call
	proved to cause genuine random starting positions, but with a total delay of ~8 seconds to program startup time.
	This should result in 14 objects on screen, but is not perfectly reliable. I think a longer SDL_Delay would fix this
	but startup delay would become unacceptably long.

4: Implement collision detection between player, coins & aliens - NOT IMPLEMENTED DUE TO TIME CONSTRAINTS

5: Change sprites for different items - NOT IMPLEMENTED DUE TO TIME CONSTRAINTS
	This would simply require changing the .png files within "StarshipFontana-master/assets"



Original README below

----------

# Starship Fontana #

This is an example C++ application using the SDL library.
It tries to be as nicely C++11 as possible but do keep in
mind that SDL is written in C and, at some stage, you have
to interface with it.

## Story ##
The evil b’Kuhn has stolen the code to Earth’s defence system.
With this code he can, at any time, defeat the entire human race.
Only one woman is brave enough to go after b’Kuhn. Will she be
Earth’s hero? Puzzle your way though the universe in the company
of Commander Fontana in **Starship Fontana**.

## Installation ##
You will have to have the SDL development libraries installed on
your system.  The easiest way to compile is to use a command-line

```bash
$ g++ -c -std=c++11 src/*.cpp
$ g++ -o starship *.o -lSDL2 -lSDL2_image
```

which will produce an executable file called "starship" in the
top-level directory.  To execute this file do the following

`$ ./starship`
 
from the top-level directory.  The game will expect to find the
`assets` directory under its current working directory.

## Credits ##
The sprites in this game come directly from 
[SpriteLib](http://www.widgetworx.com/widgetworx/portfolio/spritelib.html) and are used
under the terms of the [CPL 1.0](http://opensource.org/licenses/cpl1.0.php).
