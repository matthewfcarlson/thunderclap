#include "compat/ptr.h"
struct Ref_e8980 {
    virtual void a();
    virtual void release();
};
extern int billboardVtable;
extern int animationVtable;
void thunk(hulk_uintptr);
struct Obj_e8980 {
    int* vptr;
    unsigned int resource;
    char pad[4];
    Ref_e8980* child;
    void cleanup();
};
void Obj_e8980::cleanup() {
    vptr = &billboardVtable;
    Ref_e8980* volatile* pc = &child;
    Ref_e8980* c = *pc;
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
