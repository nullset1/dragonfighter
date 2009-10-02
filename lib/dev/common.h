/****
 * Main header file for Dragon Fighter. 
 * Copyright (c) 2009 Brian S. Moriya
 * See LICENSE and COPYING for licence information.
 ****/

#ifndef _COMMON_H
#define _COMMON_H

#include <allegro.h>

/* Allegro constants */
#define MODE GFX_AUTODETECT_WINDOWED
#define WIDTH 640
#define HEIGHT 480

/* map constants */
#define TILEW 32
#define TILEH 32
#define COLS 10
#define DOWN 0
#define UP 1
#define RIGHT 2
#define LEFT 3

/* game constants */
#define NORM_SPEED 1
#define HALF_SPEED NORM_SPEED/2

/* Tantagel castle courtyard */
#define TCB_ACROSS 32
#define TCB_DOWN 32
#define TCBW TCB_ACROSS*TILEW
#define TCBH TCB_DOWN*TILEH
extern int TCBLALB[];

/* bitmaps */
BITMAP *bufferbmp;
BITMAP *scrollbmp;
BITMAP *tilesbmp;
BITMAP *playerupbmp[2];
BITMAP *playerdnbmp[2];
BITMAP *playerltbmp[2];
BITMAP *playerrtbmp[2];

/* typedefs */
typedef struct SPRITE {
  int x; /* x position of sprite's center */
  int y; /* y position of sprite's center */
  int direction;
  int width;
  int height;
  int xspeed;
  int yspeed;
  int curframe; /* current animation frame */
  int maxframe; /* number of animation frames */
  int framecount;
  int framedelay;
  /* track distance from starting point. */
  int distancex;
  int distancey;
}SPRITE;

/* sprites */
SPRITE *player;

/* position variables */
int scrollx;
int scrolly;
int startx; /* tracks the player's starting position considered point 0 */
int starty;
int tilex, tiley;

/* function prototypes */

void setup_allegro (int mode, int screenw, int screenh, int cdepth);
void setup_bmps (void);
void destroy_bmps (void);
void draw_frame (BITMAP *source, BITMAP *destination, int x, int y, int width, 
		int height, int startx, int starty, int columns, int frame);
/*
 * Taken from Game Programming All in One 3rd ed.
 */
BITMAP *grab_frame (BITMAP *source, int width, int height, int startx, 
		    int starty, int columns, int frame);
/*
 * Taken from Game Programming All in One 3rd ed.
 */
void draw_TCBLALB (void);
void setup_player (void);
void draw_player (void);
void animate_player (void);
void move_player (void);
void scroll_window (void);
void refresh_screen (void);
void print_scroll_debug_messages (void);
void print_player_debug_messages (void);

#endif