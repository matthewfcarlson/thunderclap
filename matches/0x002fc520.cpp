#include "decls/data/game/global.h"
// data: global_2fc520 = DAT_00554c14

#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_00431898[];
class Ref_2fc520 {
  public:
    virtual void Dummy();
    virtual void Release();
};
class Obj_2fc520 {
  public:
    virtual void Dummy();
    virtual void Release();
};
class PhysicsInstance_2fc520 {
  public:
    void* vptr;
    char pad[12];
    Obj_2fc520* obj;
    Ref_2fc520* ref;
    void Destroy();
};
class Global_2fc520 {
  public:
    void call(int);
};
void PhysicsInstance_2fc520::Destroy() {
    vptr = (void*)((hulk_intptr)DAT_00431898);
    (*(Global_2fc520**)&DAT_00554c14)->call(*(int*)((char*)obj + 0x74));
    if (ref)
        ref->Release();
    obj->Release();
    Ref_2fc520* r = ref;
    if (r) {
        ref = 0;
        r->Release();
    }
    Obj_2fc520* o = obj;
    if (o) {
        obj = 0;
        o->Release();
    }
    vptr = (void*)((hulk_intptr)DAT_003f6098);
}