#include "compat/ptr.h"
class Item {
  public:
    char Valid();
    int Value();
};
class Owner {
  public:
    char Do(int, int);
    char Run(hulk_intptr x, Item* p);
};
char Owner::Run(hulk_intptr x, Item* p) {
    char ok = p->Valid();
    if (!ok)
        return ok;
    return Do(x, p->Value());
}