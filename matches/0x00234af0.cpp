#include "compat/ptr.h"
extern int vtBase_234af0;
extern int vtList;
class Part_234af0 {
  public:
    void Init(int);
};
class ParamValueStringList {
  public:
    int vptr;
    int pad;
    Part_234af0 part;
    ParamValueStringList(int);
};
ParamValueStringList::ParamValueStringList(int x) {
    int* p = &vptr;
    *(hulk_intptr*)p = (hulk_intptr)&vtBase_234af0;
    part.Init(x);
    *(hulk_intptr*)p = (hulk_intptr)&vtList;
}
