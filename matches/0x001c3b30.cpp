#include "compat/ptr.h"
class Helper_1c3b30 {
  public:
    int first(int);
    void second(int);
};
class Obj_1c3b30 {
  public:
    char pad[8];
    Helper_1c3b30* m;
    void target(hulk_intptr);
};
void Obj_1c3b30::target(hulk_intptr param) {
    int r = m->first(param);
    if (r)
        m->second(r);
}