#include "compat/ptr.h"
#include "decls/data/engine/movie.h"

class Ref_337890 {
  public:
    virtual void F(int);
};
class Obj_337890 {
  public:
    hulk_uintptr a;
    unsigned b;
    Ref_337890* member;
    void Go();
};
void Obj_337890::Go() {
    a = ((hulk_intptr)((char*)&DAT_00434578));
    if (member)
        member->F(1);
}