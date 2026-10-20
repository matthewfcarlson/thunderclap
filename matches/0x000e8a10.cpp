// Same code shape as 0x000e8980 (propagated; names are from that function)
#include "compat/ptr.h"
struct Ref_e8a10 {
    virtual void a();
    virtual void release();
};
extern int billboardVtable;
extern int animationVtable;
void thunk(hulk_uintptr);
struct Obj_e8a10 {
    int* vptr;
    unsigned int resource;
    char pad[4];
    Ref_e8a10* child;
    void cleanup();
};
void Obj_e8a10::cleanup() {
    vptr = &billboardVtable;
    Ref_e8a10* volatile* pc = &child;
    Ref_e8a10* c = *pc;
    if (c) {
        c->release();
        child = 0;
    }
    vptr = &animationVtable;
    c = *pc;
    if (c) {
        c->release();
        child = 0;
    }
    if (resource) {
        thunk(resource);
        resource = 0;
    }
}
