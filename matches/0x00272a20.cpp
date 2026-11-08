#include "compat/ptr.h"
#include "decls/data/records.h"

class Inner_272a20 {
  public:
    virtual void A();
    virtual void B();
};
// core::Drive (records.h CoreDrive): the state, under the IMutable lock at +0xc
class Obj_272a20 : public CoreDrive {
  public:
    int target();
};
int Obj_272a20::target() {
    ((Inner_272a20*)&vftableMutable)->A();
    int v = state;
    ((Inner_272a20*)&vftableMutable)->B();
    return v;
}
