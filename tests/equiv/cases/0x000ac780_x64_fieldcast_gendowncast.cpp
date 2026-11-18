// eq64 (integ2, D93 F4): a real downcast with evidence: the field's declared pointee is gen's pure3d::Image and the
// code casts it to gen's pure3d::Image32 (RTTI-derived, its vftable and sizeof checked by gen_headers --probe): the
// object is Image32 outright, no view taken on trust: equivalent.
#include "gen/pure3d.h"
struct Holder_ac780 {
    pure3d::Image* obj;
};
class Target_ac780 {
    char pad[0x14];

  public:
    int value;
    Holder_ac780* in;
    void Set(int x);
};
void Target_ac780::Set(int x) {
    value = ((pure3d::Image32*)in->obj)->f_10 + x;
}
