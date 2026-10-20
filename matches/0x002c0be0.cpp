#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042eb0c[];
typedef unsigned int u32_2c0be0;
struct Obj_2c0be0 {
    void ReleaseThing();
};
struct ImageLoader {
    u32_2c0be0 vptr;
    u32_2c0be0 pad[4];
    Obj_2c0be0* mPtr;
    void Destroy();
};
void __cdecl DropThing(Obj_2c0be0*);
void ImageLoader::Destroy() {
    Obj_2c0be0* p = mPtr;
    vptr = ((hulk_intptr)DAT_0042eb0c);
    if (p) {
        p->ReleaseThing();
        DropThing(p);
    }
    vptr = ((hulk_intptr)DAT_003f6098);
}