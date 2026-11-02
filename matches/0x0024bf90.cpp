#include "decls/data/engine/audio.h"

extern void F24bae0(void*, int);
extern "C" void FUN_00259b40(void*);
extern "C" void FUN_0025d300(void*);
extern "C" void FUN_0025e280(void*);
extern void* F25e070();
extern void F247550(void*, void*);
struct Obj_24bf90 {
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    void* f;
};
extern "C" void FUN_0024bf90(void * p) {
    F24bae0(((Obj_24bf90 *)p), 1);
    FUN_00259b40(((Obj_24bf90 *)p)->c);
    FUN_0025d300(((Obj_24bf90 *)p)->d);
    FUN_0025e280(((Obj_24bf90 *)p)->e);
    if (((Obj_24bf90 *)p)->e)
        F247550(F25e070(), ((Obj_24bf90 *)p)->e);
    if (((Obj_24bf90 *)p)->f) {
        FUN_0025e280(((Obj_24bf90 *)p)->f);
        if (((Obj_24bf90 *)p)->f)
            F247550(F25e070(), ((Obj_24bf90 *)p)->f);
    }
    if (!((Obj_24bf90 *)p)->b)
        (*(void**)&DAT_004e61e8) = ((Obj_24bf90 *)p)->a;
    else
        *(void**)((Obj_24bf90 *)p)->b = ((Obj_24bf90 *)p)->a;
    if (!((Obj_24bf90 *)p)->a)
        (*(void**)&DAT_004e61ec) = ((Obj_24bf90 *)p)->b;
    else
        *(void**)((char*)((Obj_24bf90 *)p)->a + 4) = ((Obj_24bf90 *)p)->b;
    F247550(((char*)&DAT_004e61a0), ((Obj_24bf90 *)p));
}