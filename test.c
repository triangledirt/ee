#include <stddef.h>
#include <stdio.h>
#include "ee.h"
#include "ee_morph.h"

int main(int argc, char *argv[])
{
  void *context = NULL;
  ee_start(context, ee_morph_start, ee_morph_stop, ee_morph_mod, ee_morph_unmod, ee_morph_exp);
  ee_exp(1024);
  ee_stop();

  printf("%f\n", ee_eval());
  ;;  /*  TODO save the exp + the eval  */

  return 0;
}
