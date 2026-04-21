#define ELLORA_IMPL
#include "ellora_strings.h"
#include <assert.h>
#include <stdio.h>

#define Test(_label_, _stm_) if(!_stm_){fprintf(stderr, "[FAILED]: %s\n", _label_);}

int main ( void )
{
  Test(
    "Two strings are equal",
    StringEqual(
      GetStr("sailor"),
      GetStr("sailor")));

  {
    String a = GetStr("sailor");
    String b = StrCopy(a);

    Test(
      "Copy string \"a\" to string \"b\" and test if are equal",
      StringEqual(a, b));
  }
}