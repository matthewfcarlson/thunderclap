#include "decls/data/game/global.h"
// data: zero = DAT_003f32e0

class Obj {
  public:
    char pad[0x1b0c];
    float value;
};
class C {
  public:
    Obj* lookup(__int64);
    float get(int id);
};
extern "C" __int64 __cdecl find(int, int, int);
float C::get(int id) {
    __int64 x = find(id, 0, 0);
    Obj* p = lookup(x);
    if (!p)
        return DAT_003f32e0;
    return p->value;
}