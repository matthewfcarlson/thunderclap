// Same code shape as 0x0023afb0 (propagated; names are from that function)
#include "gen/fight.h"

struct Reader_23b010 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void vfunc_12(int, int, int);
};
struct ScriptReader_nv_23b010 {
    int helper(int, int, int);
    int finish(int, int);
};

void fight::ScriptReader::vfunc_7(int a, int b, int c) {
    int x = ((ScriptReader_nv_23b010*)this)->helper(a, b, 4);
    ((ScriptReader_nv_23b010*)this)->finish(x, c);
}
