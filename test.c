#include <stddef.h>
#include <stdio.h>
#include "ee.h"
#include "ee_morph.h"

int main(int argc, char *argv[])
{
  void *context = NULL;
  ee_start(context, ee_morph_start, ee_morph_stop, ee_morph_mod, ee_morph_unmod, ee_morph_exp);
  ee_exp(32);
  ee_morph_print();
  printf("%f\n", ee_eval());
  ee_stop();
  return 0;
}
