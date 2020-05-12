#ifndef __COMPILADOR_H__
#define __COMPILADOR_H__
#include <stdbool.h>

bool interp(char input[10]);
bool verificaExpr(char expr[]);
bool hasSameVar(char var, int *index);

#endif