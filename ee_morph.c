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
  modbit = random() % OBJ;
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
  obj_morph3ticks(&xobj, game, OBJ);
  eval = 1.0;  /*  TODO  */
  return eval;
}
