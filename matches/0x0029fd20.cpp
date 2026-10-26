#include "decls/data/engine/unknown.h"
// data: gObject_29fd20 = DAT_0052cba0

struct Obj_29fd20 {
    void Method(int v, void* self);
};
struct Caller_29fd20 {
    void Target(int value);
};
void Caller_29fd20::Target(int value) {
    (*(Obj_29fd20**)&DAT_0052cba0)->Method(value, this);
}
