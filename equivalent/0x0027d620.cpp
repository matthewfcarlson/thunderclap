// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// pure3d::prop::StateProp::vfunc_12 @ 0x0027d620
namespace pure3d { namespace prop {
struct Source {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12();
    char pad[0x10];
    unsigned int position[6];
    unsigned int bounds[4];
};
struct StateProp {
    char pad0[0x14];
    unsigned int position[6];
    unsigned int bounds[4];
    char pad1[0x60];
    Source *source;
    void vfunc_12();
};
void StateProp::vfunc_12() {
    source->vfunc_12();
    Source *s = source;
    for (int i = 0; i < 6; ++i) position[i] = s->position[i];
    s = source;
    for (int i = 0; i < 4; ++i) bounds[i] = s->bounds[i];
}
}}