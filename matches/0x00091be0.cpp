#include "compat/ptr.h"
extern "C" char DAT_0040449c[];
class CUnlockable {
  public:
    int pad[6];
    void* m18;
    void Destroy();
};
extern void __cdecl thunk_FUN_00267090(void*);
struct Tail_91be0 {
    void f();
};
void CUnlockable::Destroy() {
    *(void**)this = (void*)((hulk_intptr)DAT_0040449c);
    if (m18) {
        thunk_FUN_00267090(m18);
        m18 = 0;
    }
    ((Tail_91be0*)((char*)this + 0x10))->f();
}
