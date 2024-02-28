#include <stdio.h>
#include <stdlib.h>
#include "../obj/game3.h"
#include "../obj/obj.h"
#include "ee_morph.h"

#define MODBITS 8

obj_t obj;
obj_game3_t game = 110;
long modbits[MODBITS];

void ee_morph_start(void *ctx)
{
  obj_randomize(&obj);
}

void ee_morph_stop(void *ctx) {}

void ee_morph_mod(void *ctx)
{
  long i;
  for (i = 0; i < MODBITS; i++) {
    modbits[i] = obj_randomindex();
    obj_flipattr(&obj, modbits[i]);
  }
}

void ee_morph_unmod(void *ctx)
{
  long i;
  for (i = 0; i < MODBITS; i++)
    obj_flipattr(&obj, modbits[i]);
}

double ee_morph_exp(void *ctx)
{
  double eval;
  obj_t xobj = obj;
  struct obj_stat_t stat;
  obj_morph3(&xobj, game, OBJ);
  stat = obj_stat(xobj);
  eval = labs(stat.zeroes - stat.ones) / (double) OBJ;
  return eval;
}

void ee_morph_print()
{
  obj_t xobj = obj;
  struct obj_stat_t stat;
  long tick;
  obj_print(xobj);
  printf("\n");
  for (tick = 0; tick < OBJ; tick++) {
    obj_morph3(&xobj, game, 1);
    obj_print(xobj);
    printf("\n");
  }
}
