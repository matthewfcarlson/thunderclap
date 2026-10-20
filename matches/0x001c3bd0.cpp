#include "compat/ptr.h"
class Context {
  public:
    int* Lookup(int);
};
class Obj_1c3bd0 {
  public:
    char pad[0x0c];
    Context* mContext;
    hulk_intptr Target(int);
};
hulk_intptr Obj_1c3bd0::Target(int arg) {
    int* p = mContext->Lookup(arg);
    if (p)
        return (hulk_intptr)p + 0x30;
    return 0;
}