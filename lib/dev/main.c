/****
 * Main program file for Dragon Fighter.
 * Copyright (c) 2009 Brian S. Moriya
 * See LICENSE and COPYING for important license information.
 ****/

#include "common.h"

int main (void) {
  /* initialize the game. */
  setup_allegro (MODE, WIDTH, HEIGHT, 16);
  setup_bmps();
  setup_player();
  scrollx = 0;
  scrolly = 0;
  
  draw_TCBLALB();

  while (!key[KEY_ESC]) {
    if (key[KEY_RIGHT]) {
      player->direction = RIGHT;
      player->xspeed = 1;
    
    } else if (key[KEY_LEFT]) {
      player->direction = LEFT;
      player->xspeed = -1;

    } else if (key[KEY_DOWN]) {
      player->direction = DOWN;
      player->yspeed = 1;

    } else if (key[KEY_UP]) {
      player->direction = UP;
      player->yspeed = -1;

    } else {
      player->xspeed = 0;
      player->yspeed = 0;
    }

    scroll_window();
    
    blit (scrollbmp, bufferbmp, scrollx, scrolly, 0, 0, WIDTH-1, HEIGHT-1);
    print_scroll_debug_messages();
    print_player_debug_messages();
    draw_player();
    animate_player();

    acquire_screen();
    blit (bufferbmp, screen, 0, 0, 0, 0, WIDTH-1, HEIGHT-1);
    release_screen();

    rest (20);
  }
  destroy_bmps();
  allegro_exit();
  return 0;
}
END_OF_MAIN()

void setup_allegro (int mode, int screenw, int screenh, int cdepth) {
  allegro_init();
  install_keyboard();
  install_timer();
  srand (time (NULL));
  set_color_depth (cdepth);
  set_gfx_mode (mode, screenw, screenh, 0, 0);
}

void setup_bmps (void) {
  int i;
  BITMAP *tempbmp;

  bufferbmp = create_bitmap (WIDTH, HEIGHT);
  scrollbmp = create_bitmap (TCBW, TCBH);
  tilesbmp = load_bitmap ("maptiles.bmp", NULL);

  /* load bitmaps for the player animations */
  tempbmp = load_bitmap ("chars.bmp", NULL);
  for (i = 0; i < 2; i++) {
    playerdnbmp[i] = grab_frame (tempbmp, 32, 32, 0, 0, 32, i);
    playerupbmp[i] = grab_frame (tempbmp, 32, 32, 0, 0, 32, i+2);
    playerrtbmp[i] = grab_frame (tempbmp, 32, 32, 0, 0, 32, i+4);
    playerltbmp[i] = grab_frame (tempbmp, 32, 32, 0, 0, 32, i+6);
  }
  destroy_bitmap (tempbmp);
}

void destroy_bmps (void) {
  destroy_bitmap (bufferbmp);
  destroy_bitmap (scrollbmp);
  destroy_bitmap (tilesbmp);
}

void draw_frame (BITMAP *source, BITMAP *destination, int x, int y, int width,
                int height, int startx, int starty, int columns, int frame) {
  /* calculate frame position */
  int framex = startx + (frame%columns)*width;
  int framey = starty + (frame/columns)*height;
  /* draw frame to destination bitmap. */
  masked_blit (source, destination, framex, framey, x, y, width, height);
}

BITMAP *grab_frame (BITMAP *source, int width, int height, int startx,
		    int starty, int columns, int frame) {
  BITMAP *tempbmp = create_bitmap (width, height);
  int x = startx + (frame%columns)*width;
  int y = starty + (frame/columns)*height;
  blit (source, tempbmp, x, y, 0, 0, width, height);
  return tempbmp;
}

void draw_TCBLALB (void) {
  int i = 0;
  for (tiley = 0; tiley < scrollbmp->h; tiley += TILEH) {
    for (tilex = 0; tilex < scrollbmp->w; tilex += TILEW) {
      draw_frame (tilesbmp, scrollbmp, tilex, tiley, TILEW, TILEH, 0, 0,
                  COLS, TCBLALB[i++]);
    }
  }
}

void setup_player (void) {
  player = (SPRITE*)malloc (sizeof (SPRITE));
  player->x = 0; /* player center x */
  player->y = 0; /* player center y */
  player->direction = DOWN;
  player->width = 32;
  player->height = 32;
  player->xspeed = 0;
  player->yspeed = 0;
  player->curframe = 0;
  player->maxframe = 1;
  player->framecount = 0;
  player->framedelay = 10;
}

void draw_player (void) {
  switch (player->direction) {
  case DOWN:
    draw_sprite (bufferbmp, playerdnbmp[player->curframe],
		 player->x, player->y);
    break;

  case UP:
    draw_sprite (bufferbmp, playerupbmp[player->curframe],
		 player->x, player->y);
    break;

  case LEFT:
    draw_sprite (bufferbmp, playerltbmp[player->curframe],
		 player->x, player->y);
    break;

  case RIGHT:
    draw_sprite (bufferbmp, playerrtbmp[player->curframe],
		 player->x, player->y);
    break;
  }
}

void animate_player (void) {
  /* prevent animation if the sprite is not moving. */
  if (player->xspeed > 0 || player->yspeed > 0) {
    
    /* animate the sprite */
    if (player->framecount++ > player->framedelay) {
      player->framecount = 0;
      player->curframe++;
      if (player->curframe > player->maxframe) player->curframe = 0;
    }
  }
}

void move_player (void) {
  
}

void scroll_window (void) {
  switch (player->direction) {
  case RIGHT:
    if (player->xspeed != 0)
      if ((scrollx+=1) > scrollbmp->w-WIDTH) scrollx = scrollbmp->w - WIDTH;
    break;

  case LEFT:
    if (player->xspeed != 0) if ((scrollx-=1) < 0) scrollx = 0;
    break;

  case UP:
    if (player->yspeed != 0) if ((scrolly-=1) < 0) scrolly = 0;
    break;

  case DOWN:
    if (player->yspeed !=0)
      if ((scrolly+=1) > scrollbmp->h-HEIGHT) scrolly = scrollbmp->h - HEIGHT;
    break;
  }
}

void print_scroll_debug_messages (void) {
  textprintf_ex (bufferbmp, font, 0, 0, makecol (0,0,0), -1,
		 "Scroll Window Position:");
  textprintf_ex (bufferbmp, font, 0, 10, makecol (0,0,0), -1,
		 "tl = (%d,%d)", scrollx, scrolly);
  textprintf_ex (bufferbmp, font, 0, 20, makecol (0,0,0), -1,
		 "tr = (%d,%d)", scrollx+WIDTH, scrolly);
  textprintf_ex (bufferbmp, font, 0, 30, makecol (0,0,0), -1,
		 "bl = (%d,%d)", scrollx, scrolly+HEIGHT);
  textprintf_ex (bufferbmp, font, 0, 40, makecol (0,0,0), -1,
		 "br = (%d,%d)", scrollx+WIDTH, scrolly+HEIGHT);
  textprintf_ex (bufferbmp, font, 0, 50, makecol (0,0,0), -1,
		 "center = (%d,%d)", scrollx+WIDTH/2, scrolly+HEIGHT/2);
}

void print_player_debug_messages (void) {
  textprintf_ex (bufferbmp, font, 200, 0, makecol (0,0,0), -1,
		 "Player Position:");
  textprintf_ex (bufferbmp, font, 200, 10, makecol (0,0,0), -1,
		 "tl = (%d,%d)", player->x, player->y);
  textprintf_ex (bufferbmp, font, 200, 20, makecol (0,0,0), -1,
		 "bl = (%d,%d)", player->x, player->y+32);
  textprintf_ex (bufferbmp, font, 200, 30, makecol (0,0,0), -1,
		 "tr = (%d,%d)", player->x+32, player->y);
  textprintf_ex (bufferbmp, font, 200, 40, makecol (0,0,0), -1,
		 "br = (%d,%d)", player->x+32, player->y+32);
  textprintf_ex (bufferbmp, font, 200, 50, makecol (0,0,0), -1,
		 "center = (%d,%d)", player->x+16, player->y+16);
}
