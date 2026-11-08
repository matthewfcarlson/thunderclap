#include "compat/ptr.h"
#include "decls/data/records.h"

class Sub_272880 {
  public:
    virtual void A();
    virtual void B();
};
// core::Drive (records.h CoreDrive): the last error, under the IMutable lock at +0xc
class Obj_272880 : public CoreDrive {
  public:
    int Run();
};
int Obj_272880::Run() {
    ((Sub_272880*)&vftableMutable)->A();
    int v = error;
    ((Sub_272880*)&vftableMutable)->B();
    return v;
}
