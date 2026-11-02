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
void FUN_0024bf90(Obj_24bf90* p) {
    F24bae0(p, 1);
    FUN_00259b40(p->c);
    FUN_0025d300(p->d);
    FUN_0025e280(p->e);
    if (p->e)
        F247550(F25e070(), p->e);
    if (p->f) {
        FUN_0025e280(p->f);
        if (p->f)
            F247550(F25e070(), p->f);
    }
    if (!p->b)
        (*(void**)&DAT_004e61e8) = p->a;
    else
        *(void**)p->b = p->a;
    if (!p->a)
        (*(void**)&DAT_004e61ec) = p->b;
    else
        *(void**)((char*)p->a + 4) = p->b;
    F247550(((char*)&DAT_004e61a0), p);
}