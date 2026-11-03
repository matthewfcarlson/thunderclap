#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void* __cdecl alloc(hulk_uintptr);
class CRenderableCharacter_1c60f0 {
  public:
    CRenderableCharacter_1c60f0* Init(int, int);
};
class Owner {
  public:
    CRenderableCharacter_1c60f0* Create(int, int);
};
CRenderableCharacter_1c60f0* Owner::Create(int a, int b) {
    CRenderableCharacter_1c60f0* p = (CRenderableCharacter_1c60f0*)alloc(0x18);
    if (p) {
        CRenderableCharacter_1c60f0* q = p->Init(a, b);
        if (q) {
            ((owners::Thing_1c5f30 *)this)->FUN_001c5f30((hulk_uintptr)(CRenderableCharacter_1c60f0 *)q);
            return q;
        }
    }
    return 0;
}