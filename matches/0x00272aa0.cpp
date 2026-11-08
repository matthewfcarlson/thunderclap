#include "compat/ptr.h"
#include "decls/data/records.h"

class Inner_272aa0 {
  public:
    virtual void A();
    virtual void B();
};
// core::Drive (records.h CoreDrive): the drive thread completed a request: keep it, mark the drive active and
// release the waiting thread's semaphore if there is one (under the IMutable lock at +0xc)
class Obj_272aa0 : public CoreDrive {
  public:
    void Run(hulk_intptr);
};
extern "C" void __cdecl FUN_0026d8a0(hulk_uintptr*);
void Obj_272aa0::Run(hulk_intptr arg) {
    ((Inner_272aa0*)&vftableMutable)->A();
    request = (void*)arg;
    active = 1;
    if (signal != 0) {
        ((Inner_272aa0*)&vftableMutable)->B();
        FUN_0026d8a0(signal);
    } else {
        ((Inner_272aa0*)&vftableMutable)->B();
    }
}
