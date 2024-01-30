#ifndef ee_h
#define ee_h

typedef void (*ee_start_f)(void *ctx);
typedef void (*ee_stop_f)(void *ctx);
typedef void (*ee_mod_f)(void *ctx);
typedef void (*ee_unmod_f)(void *ctx);
typedef double (*ee_exp_f)(void *ctx);

double eval = 0.0;

void *context;
ee_start_f startfunc;
ee_stop_f stopfunc;
ee_mod_f modfunc;
ee_unmod_f unmodfunc;
ee_exp_f expfunc;

void ee_start(void *ctx, ee_start_f start, ee_stop_f stop, ee_mod_f mod, ee_unmod_f unmod, ee_eval_f eval, ee_exp_f exp);
void ee_tick();
void ee_stop();

void ee_start(void *ctx, ee_start_f start, ee_stop_f stop, ee_mod_f mod, ee_unmod_f unmod, ee_eval_f eval, ee_exp_f exp)
{
  context = ctx;
  startfunc = start;
  stopfunc = stop;
  modfunc = mod;
  unmodfunc = unmod;
  expfunc = exp;
  startfunc();
}

void ee_stop()
{
  ee_istop();
}

void ee_tick()
{
  double neweval;
  modfunc(context);
  neweval = expfunc(context);
  if (neweval > eval) {
    eval = neweval;
  } else {
    unmodfunc();
  }
}

#endif
