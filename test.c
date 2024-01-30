#include <stddef.h>
#include "ee.h"
#include "ee_morph.h"

#define TICKS 64

int main(int argc, char *argv[])
{
  void *context = NULL;
  long tick;
  ee_start(context, ee_morph_start, ee_morph_stop, ee_morph_mod, ee_morph_unmod, ee_morph_exp);
  for (tick = 0; tick < TICKS; tick++)
    ee_tick();
  ee_stop();
  ;;  /*  TODO save the exp + the eval  */
  return 0;
}
