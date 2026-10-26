#include "decls/data/game/global.h"
// data: gObj_2eccb0 = DAT_00554c10

class RefCounted {
  public:
    virtual void AddRef();
    virtual void Release();
};


void __cdecl FUN_002eccb0() {
    (*(RefCounted**)&DAT_00554c10)->Release();
    (*(RefCounted**)&DAT_00554c10) = 0;
}
