struct Device {
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
extern Device** DAT_0052c2ac;
struct Material {
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
struct Wrapper {
    Material* material;
    void FUN_002a4060();
};
struct Modifier {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual unsigned apply(unsigned);
    virtual unsigned restore(unsigned);
};
struct ItemData {
    char pad[16];
    Modifier* modifier;
    char pad2[48];
    void* value;
};
struct Entry {
    unsigned value;
    Wrapper* wrapper;
    ItemData* data;
};
struct Callback {
    void FUN_002a06d0(void*);
};
namespace pure3d {
struct OpaqueTraversal {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[16];
    Callback* callback;
    unsigned count;
    char pad2[16];
    Entry** entries;
};
} // namespace pure3d
void pure3d::OpaqueTraversal::vfunc_4() {
    (*DAT_0052c2ac)->begin(0);
    for (unsigned i = 0; i < count; ++i) {
        Entry* e = entries[i];
        Wrapper* w = e->wrapper;
        ItemData* data = e->data;
        (*DAT_0052c2ac)->bind(0, e->value);
        if (w->material->test() == 1 && callback && data->value)
            callback->FUN_002a06d0(data->value);
        Modifier* mod = data->modifier;
        if (mod) {
            Material* m = w->material;
            m->set(mod->apply(m->get()));
            w->FUN_002a4060();
            m->set(mod->restore(m->get()));
        } else
            w->FUN_002a4060();
    }
    (*DAT_0052c2ac)->end(0);
}