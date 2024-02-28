#ifndef ee_h
#define ee_h

typedef void (*ee_start_f)(void *ctx);
typedef void (*ee_stop_f)(void *ctx);
typedef void (*ee_mod_f)(void *ctx);
typedef void (*ee_unmod_f)(void *ctx);
typedef double (*ee_exp_f)(void *ctx);

void ee_start(void *ctx, ee_start_f start, ee_stop_f stop, ee_mod_f mod, ee_unmod_f unmod, ee_exp_f exp);
void ee_exp(long times);
void ee_stop();

double ee_eval();

#endif
