#ifndef ee_h
#define ee_h

typedef void (*ee_start_f)(void *ctx);
typedef void (*ee_stop_f)(void *ctx);
typedef void (*ee_mod_f)(void *ctx);
typedef void (*ee_unmod_f)(void *ctx);
typedef double (*ee_eval_f)(void *ctx);
typedef double (*ee_sim_f)(void *ctx);

double eval;
long first = 1;

void *context;
ee_start_f startfunc;
ee_stop_f stopfunc;
ee_mod_f modfunc;
ee_unmod_f unmodfunc;
ee_eval_f evalfunc;
ee_sim_f simfunc;

void ee_start(void *ctx, ee_start_f start, ee_stop_f stop, ee_mod_f mod, ee_unmod_f unmod, ee_eval_f eval, ee_sim_f sim);
void ee_tick();
void ee_stop();

void ee_start(void *ctx, ee_start_f start, ee_stop_f stop, ee_mod_f mod, ee_unmod_f unmod, ee_eval_f eval, ee_sim_f sim)
{
  context = ctx;
  startfunc = start;
  stopfunc = stop;
  modfunc = mod;
  unmodfunc = unmod;
  evalfunc = eval;
  simfunc = sim;
  startfunc();
}

void ee_stop()
{
  ee_istop();
}

void ee_tick()
{
  double neweval;
  double oldeval = eval;
  if (first) {
    eval = evalfunc(context);
    first = 0;
  }
  modfunc(context);
  simfunc(context);
  neweval = evalfunc(context);
  if (neweval > eval) {
    eval = neweval;
  } else {
    unmodfunc();
    eval = oldeval;
  }
}

#endif
