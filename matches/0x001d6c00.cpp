#include "decls/data/game/global.h"
// data: zero = DAT_004c6068
#include "gen/owners.h"

struct Vec {
    float x, y, z;
};
struct View {
    char bytes[64];
};
struct Obj {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual View* get();
};
struct Owner {
    char pad[0x11c];
    Obj* obj;
    void fn();
};
void __cdecl output(Vec*);
void Owner::fn() {
    View local = *obj->get();
    Vec v;
    ((owners::M_22c3b0 *)&local)->FUN_0022c3b0((float *)(((float*)&DAT_004c6068)), (float *)(Vec *)(&v));
    output(&v);
}