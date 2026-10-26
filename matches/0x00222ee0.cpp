#include "decls/data/game/global.h"
// data: zeroValue_222ee0 = DAT_003f32e0

#include "compat/ptr.h"
class Item_222ee0 {
  public:
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
    virtual void m();
    virtual bool Check();
};
struct Entry_222ee0 {
    Item_222ee0* obj;
    float value;
    char flag;
    char pad[31];
};
class Owner_222ee0 {
  public:
    char pad[0x68];
    unsigned count;
    Entry_222ee0 entries[1];
    hulk_intptr target(int index);
};
hulk_intptr Owner_222ee0::target(int index) {
    int found = 0;
    for (unsigned i = 0; i < count; ++i) {
        Entry_222ee0* e = &entries[i];
        if (!e->obj->Check() && (e->value >= DAT_003f32e0 || e->flag)) {
            if (index == found)
                return (hulk_intptr)e->obj;
            ++found;
        }
    }
    return 0;
}