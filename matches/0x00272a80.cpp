#include "compat/ptr.h"
#include "decls/data/records.h"

class Inner_272a80 {
  public:
    virtual void A();
    virtual void B();
};
// core::Drive (records.h CoreDrive): the active flag, under the IMutable lock at +0xc
class Obj_272a80 : public CoreDrive {
  public:
    unsigned char target();
};
unsigned char Obj_272a80::target() {
    ((Inner_272a80*)&vftableMutable)->A();
    unsigned char v = active;
    ((Inner_272a80*)&vftableMutable)->B();
    return v;
}
