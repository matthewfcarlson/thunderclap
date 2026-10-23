#include "gen/pure3d.h"

#include "decls/data/engine/pure3d/prop.h"

struct Device_2a2af0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void bind(unsigned, unsigned);
    virtual void begin(unsigned);
    virtual void end(unsigned);
};
struct Material_2a2af0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual unsigned get();
    virtual void set(unsigned);
    virtual unsigned char test();
};
struct Wrapper_2a2af0 {
    Material_2a2af0* material;
    void FUN_002a4060();
};
struct Modifier_2a2af0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual unsigned apply(unsigned);
    virtual unsigned restore(unsigned);
};
struct ItemData_2a2af0 {
    char pad[16];
    Modifier_2a2af0* modifier;
    char pad2[48];
    void* value;
};
struct Entry_2a2af0 {
    unsigned value;
    Wrapper_2a2af0* wrapper;
    ItemData_2a2af0* data;
};
struct Callback_2a2af0 {
    void FUN_002a06d0(void*);
};
namespace pure3d {
} // namespace pure3d
void pure3d::OpaqueTraversal::vfunc_4() {
    (*(*(Device_2a2af0***)&DAT_0052c2ac))->begin(0);
    for (unsigned i = 0; i < (*(unsigned int *)&this->f_18); ++i) {
        Entry_2a2af0* e = (*(Entry_2a2af0 ** *)&this->f_2c)[i];
        Wrapper_2a2af0* w = e->wrapper;
        ItemData_2a2af0* data = e->data;
        (*(*(Device_2a2af0***)&DAT_0052c2ac))->bind(0, e->value);
        if (w->material->test() == 1 && (*(Callback_2a2af0 * *)&this->f_14) && data->value)
            (*(Callback_2a2af0 * *)&this->f_14)->FUN_002a06d0(data->value);
        Modifier_2a2af0* mod = data->modifier;
        if (mod) {
            Material_2a2af0* m = w->material;
            m->set(mod->apply(m->get()));
            w->FUN_002a4060();
            m->set(mod->restore(m->get()));
        } else
            w->FUN_002a4060();
    }
    (*(*(Device_2a2af0***)&DAT_0052c2ac))->end(0);
}
