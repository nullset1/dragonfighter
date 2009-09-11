#include "common.h"

int ttrl0[] = {
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,3,3,3,3,3,3,3,3,3,3,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,3,2,2,2,2,2,2,2,2,3,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,3,2,1,1,1,1,1,1,2,3,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,3,2,1,2,1,1,2,1,2,3,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,3,2,2,2,2,2,2,2,2,3,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,3,2,2,2,2,2,2,2,2,3,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,3,2,2,2,2,2,2,2,2,3,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,3,3,3,3,11,3,3,3,3,3,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,3,2,2,2,2,2,2,2,12,3,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,3,3,3,3,3,3,3,3,3,3,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5
};

int main(void) {
  int errorcode;
  setup_game();
  
  while(!gameover) {
    errorcode = move_player(TTRL0);
    animate_player();
    
    blit(scroll, buffer, scrollx, scrolly, startx, starty, SCROLLW, SCROLLH);
    draw_player();
    
    /* refresh the screen */
    acquire_screen();
    blit(buffer, screen, 0, 0, 0, 0, WIDTH-1, HEIGHT-1);
    release_screen();
    
    if (keypressed()) get_input(errorcode);
    
    rest (20);
  }
  teardown_ttrl0();
  teardown_game();
  return 0;
}
END_OF_MAIN()
