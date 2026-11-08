#include "compat/ptr.h"
#include "decls/data/records.h"

class V {
  public:
    virtual void A();
    virtual void B();
};
// core::Drive (records.h CoreDrive): state 2 with a semaphore to release, under the IMutable lock at +0xc
class C_272990 : public CoreDrive {
  public:
    void F(hulk_uintptr*);
};
void C_272990::F(hulk_uintptr* x) {
    ((V*)&vftableMutable)->A();
    signal = x;
    state = 2;
    ((V*)&vftableMutable)->B();
}
