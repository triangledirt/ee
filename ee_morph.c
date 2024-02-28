#include <stdio.h>
#include <stdlib.h>
#include "../obj/game3.h"
#include "../obj/obj.h"
#include "ee_morph.h"

obj_t obj;
obj_game3_t game = 110;
long modbit;

void ee_morph_start(void *ctx)
{
  obj_randomize(&obj);
}

void ee_morph_stop(void *ctx) {}

void ee_morph_mod(void *ctx)
{
  modbit = obj_randomindex();
  obj_flipattr(&obj, modbit);
}

void ee_morph_unmod(void *ctx)
{
  obj_flipattr(&obj, modbit);
}

double ee_morph_exp(void *ctx)
{
  double eval;
  obj_t xobj = obj;
  struct obj_stat_t stat;
  obj_morph3(&xobj, game, OBJ);
  stat = obj_stat(xobj);
  eval = stat.ones / (double) OBJ;
  return eval;
}

void ee_morph_print()
{
  obj_t xobj = obj;
  struct obj_stat_t stat;
  long tick;
  for (tick = 0; tick < OBJ; tick++) {
    obj_morph3(&xobj, game, 1);
    obj_print(xobj);
    printf("\n");
  }
}
