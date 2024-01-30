#include <stddef.h>
#include "ee.h"

double eval = 0.0;

void *context;
ee_start_f startfunc;
ee_stop_f stopfunc;
ee_mod_f modfunc;
ee_unmod_f unmodfunc;
ee_exp_f expfunc;

void ee_start(void *ctx, ee_start_f start, ee_stop_f stop, ee_mod_f mod, ee_unmod_f unmod, ee_exp_f exp)
{
  context = ctx;
  startfunc = start;
  stopfunc = stop;
  modfunc = mod;
  unmodfunc = unmod;
  expfunc = exp;
  startfunc(context);
}

void ee_stop()
{
  stopfunc(context);
}

void ee_tick()
{
  double neweval;
  modfunc(context);
  neweval = expfunc(context);
  if (neweval > eval) {
    eval = neweval;
  } else {
    unmodfunc(context);
  }
}
