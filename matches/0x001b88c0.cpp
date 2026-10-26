#include "decls/data/game/global.h"
// data: zero = DAT_003f32e0

class A {
  public:
    void run(float, float);
};
struct Holder {
    A* p;
};
Holder* __cdecl get();
void __stdcall FUN(float a, float b) {
    if (a <= (*(float*)&DAT_003f32e0) || b <= a)
        return;
    Holder* h = get();
    h->p->run(a, b);
}