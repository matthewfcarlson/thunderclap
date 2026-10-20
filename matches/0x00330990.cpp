#include "gen/pure3d.h"
struct Obj_330990 {
    virtual void f();
    virtual void release();
};
struct d3dToonVertexShader_nv_330990 {
    void destroy();
};
struct Toon {
    void* vptr;
    char pad[0x90];
    Obj_330990* b;
    Obj_330990* a;
};
extern int toonVtable;
void __fastcall target(Toon* self) {
    self->vptr = &toonVtable;
    if (self->a)
        self->a->release();
    if (self->b)
        self->b->release();
    ((d3dToonVertexShader_nv_330990*)(((pure3d::d3dToonVertexShader*)self)))->destroy();
}
