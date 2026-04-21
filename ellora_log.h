#ifndef ELLORA_LOG_H
#define ELLORA_LOG_H

#include <stdio.h>
#include <stdlib.h>

#define Panic(_fmt_, ...) \
  do { \
    fprintf(stderr, _fmt_ "\n", ##__VA_ARGS__); \
    exit(1); \
  } while (0)

#endif