#include "decls/data/game/global.h"
// data: zero = DAT_004c6068

struct Vec {
    float x, y, z;
};
struct View {
    char bytes[64];
    void calc(const float*, Vec*);
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
    local.calc(((float*)&DAT_004c6068), &v);
    output(&v);
}