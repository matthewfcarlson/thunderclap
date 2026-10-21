#include "compat/ptr.h"
extern "C" __int64 __cdecl Lookup(int, int, int);
class Obj {
  public:
    char pad[0x328];
    unsigned int value;
};
class Holder {
  public:
    Obj* Get(__int64);
    hulk_freg Read(int);
};
hulk_freg Holder::Read(int id) {
    __int64 key = Lookup(id, 0, 0);
    Obj* p = Get(key);
    if (!p)
        return 0.0f;
    return (float)p->value;
}