#include "decls/data/engine/choreo2.h"
// data: gMinusOne = DAT_004c9e98, gZeroA = DAT_004c9e90, gZeroB = DAT_004c9e94

extern "C" void __cdecl Work(int, int*);
struct V {
    int a, b, c;
};
class Obj_228640 {
  public:
    char pad[0x8a8];
    int value;
    V* Get(V*);
};
V* Obj_228640::Get(V* out) {
    V local;
    local.a = DAT_004c9e90;
    local.b = DAT_004c9e94;
    local.c = DAT_004c9e98;
    Work(value, (int*)&local);
    *out = local;
    return out;
}
