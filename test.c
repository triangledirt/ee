#include <stddef.h>
#include "ee.h"
#include "ee_morph.h"

#define TICKS 64

int main(int argc, char *argv[])
{
  void *context = NULL;
  ee_start(context, ee_morph_start, ee_morph_stop, ee_morph_mod, ee_morph_unmod, ee_morph_exp);
  ee_tick(TICKS);
  ee_stop();
  ;;  /*  save the exp + the eval  */
  return 0;
}
