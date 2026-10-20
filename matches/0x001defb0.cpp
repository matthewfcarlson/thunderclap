#include "compat/ptr.h"
class Item {
  public:
    int Find();
};
class Obj {
  public:
    unsigned char Go(Item*, int);
    unsigned char Run(hulk_intptr, int);
};
unsigned char Obj::Run(hulk_intptr a, int b) {
    unsigned char result = 0;
    hulk_intptr n = ((Item*)a)->Find();
    if (n >= 0)
        result = Go((Item*)n, b);
    return result;
}