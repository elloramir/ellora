#ifndef ELLORA_STRINGS_H
#define ELLORA_STRINGS_H

#include <stdint.h>

typedef struct String
{
  size_t size;
  char  *c_str;
}
String;

#define GetStr(_str_) ((String){.size=sizeof(_str_), .c_str=_str_})
#endif

#ifdef ELLORA_IMPL

#include <stdbool.h>
#include <strings.h>
#include "ellora_log.h"

bool StringEqual(String s1, String s2)
{
  // Check if same size and same pointer.
  if (s1.size != s2.size) return false;
  if (s1.c_str == s2.c_str) return true;

  // If not same pointer, let's check if all characters
  // are equal. For now We are using std string header,
  // so the strcmp is null terminated.
  return strcmp(s1.c_str, s2.c_str) == 0;
}

String StringNew(size_t size)
{
  void *ptr = calloc(size, sizeof(char));
  if (!ptr) {
    Panic("Buy more ram!");
  }
  // The string will start with 0 initialized memory
  return (String){.size=size, .c_str=ptr};
}

// Important note: since we are allocating memory for this,
// we are creating a non-interned string, which is generally slower.
String StrCopy(String str)
{
  String copy = StringNew(str.size);
  memcpy(copy.c_str, str.c_str, str.size);
  return copy;
}

#endif