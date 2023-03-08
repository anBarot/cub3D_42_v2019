# cub3D_42_v2019

## Presentation

### cub3D is a 3D labyrinth coded in C, using the 42 mlx library, a simple X-Window (X11R6) programming API in C suitable for X-beginners.
### The program is compiled using make and takes one mandatory parameter, the path to the map, 
### and an optional parameter --save, which creates a screenshot of the first image the player see.

```
make
./Cub3d map/map2.cub --save
./Cub3d map/map2.cub
```

![Screenshot from 2023-03-08 15-22-55](https://user-images.githubusercontent.com/46645713/223741248-534f2503-2ae2-4a94-af34-a3a69a91ab19.png)

## Changing the map

### You can create your own custom map with a .cub extension.
### The R is the resolution of the window, 5 textures have to be given : the South (SO), West (WE), Est (EA) and North (N) walls and the sprite (S).
### The floor and ceiling colors are configured with rgb values.
### Then the map is drawned : (1) represent walls, (0) is empty, (2) is to create a sprite.
### The player is displayed inside the map with N/E/S or W, wich is the direction the player is turned to.

```
R 1200 900

S texture/aliencartoon_sprite.xpm 
SO texture/space_wall_1.xpm 
NO texture/space_wall_2.xpm
WE texture/space_wall_3.xpm
EA texture/space_wall_4.xpm

F 50,0,50
C 0,0,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000002000001
        10010000000000000S0000001
111111111011000001110000000000001
100000000001000001110111111111111
11110111112111011100000010001
11110111110111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
1100000111010101111101111000111
11110111 1110101 101111010001
11111111 1111111 111111111111
111
101
111
```
