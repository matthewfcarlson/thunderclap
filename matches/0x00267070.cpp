#include "compat/ptr.h"
#include "decls/data/records.h"

struct Obj_267070 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h(int);
};
struct Handle_267070 {
    Obj_267070* p;
};
extern "C" Handle_267070* __cdecl FUN_00266f90(void*, int);
extern "C" void __cdecl FUN_00267070(int x) {
    Handle_267070* h = FUN_00266f90((void*)((hulk_intptr)((char*)&DAT_00527f40)), x);
    h->p->h(x);
}