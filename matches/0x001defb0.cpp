#include "compat/ptr.h"
#include "gen/owners.h"
class Item {
  public:
};
class Obj {
  public:
    unsigned char Go(Item*, int);
    unsigned char Run(hulk_intptr, int);
};
unsigned char Obj::Run(hulk_intptr a, int b) {
    unsigned char result = 0;
    hulk_intptr n = ((owners::C_1d6c70 *)(((Item*)a)))->FUN_001d6c70();
    if (n >= 0)
        result = Go((Item*)n, b);
    return result;
}