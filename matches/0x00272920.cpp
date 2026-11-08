#include "compat/ptr.h"
#include "decls/data/records.h"

class Sub_272920 {
  public:
    virtual void Begin();
    virtual void End();
};
extern "C" CoreThread* __cdecl FUN_0026dbb0();
// core::Drive (records.h CoreDrive): waits for a callback on the calling thread (state 2), under the IMutable lock
class Owner_272920 : public CoreDrive {
  public:
    void Run(hulk_intptr a, int b);
};
void Owner_272920::Run(hulk_intptr a, int b) {
    ((Sub_272920*)&vftableMutable)->Begin();
    thread = FUN_0026dbb0();
    callback = (void*)a;
    argument = b;
    state = 2;
    ((Sub_272920*)&vftableMutable)->End();
}
