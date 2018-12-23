This is an SDL implementation of the previous oxo assignment. It uses the logic
taken from the oxo assignment and implements it with SDL to create a visual
representation of what is going on.
  To run the program you will need to have SDL2 and the SDL2_gfx library
installed and use the attached makefile to compile it. The program is split
into 3 files, main.c, draw.c, logic.c along with 3 header files, define.h,
draw.h and logic.h. This is to increase organisation and clarity.
  To play the game you simply have to run it and press anywhere in the grid.
When the game is over, the colour of all the elements will be the colour of the
result(Red if X won, Blue if O won, Grey if draw) and a popup will also tell you
who won. The game should automatically reset so you can play again.
