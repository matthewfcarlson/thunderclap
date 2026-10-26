#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/scenario.h"
// data: hulk_at_004e1768 = DAT_004e1768

#include "compat/ptr.h"
extern "C" void _atexit(void (*)());
class C {
  public:
    void Reg(const char*, void*);
};
void __cdecl Cleanup() throw();
void __cdecl Hook() {
    ((C*)((hulk_intptr)((char*)&DAT_004e1768)))->Reg(((char*)&DAT_003f3ea0), 0);
    _atexit(Cleanup);
}
