#ifndef ELLORA_ARRAY_H
#define ELLORA_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _ArrayHeader
{
  size_t capacity;
  size_t size;
}
_ArrayHeader;

#define _ArrayGetHeader(ptr) ((_ArrayHeader*)(ptr) - 1)
#define _ArrayGetPtr(header) ((header) + 1)
#define _ArrayPush(a, v) (_ArrayGetHeader(a)->size++, ((typeof(v)*)(a))[_ArrayGetHeader(a)->size - 1] = (v))
#define ArrayAppend(a, v) (_ArrayCheckGrow((void**)&(a), sizeof *(a)), _ArrayPush(a, v))
#define ArrayFree(a) free(_ArrayGetHeader(a))

#endif

#ifdef ELLORA_IMPL

static void
_ArrayCheckGrow(void **a, size_t vSize)
{
  _ArrayHeader *header;

  if (!*a) {
    header = malloc(sizeof(_ArrayHeader) + 4 * vSize);
    header->capacity = 4;
    header->size = 0;
    *a = _ArrayGetPtr(header);
    return;
  }

  header = _ArrayGetHeader(*a);
  while (header->size >= header->capacity) {
    header = realloc(header, sizeof(_ArrayHeader) + 2 * header->capacity * vSize);
    header->capacity *= 2;
    *a = _ArrayGetPtr(header);
  }
}

#endif