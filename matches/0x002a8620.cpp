extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a8620[];
class Ref_2a8620 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2a8620 {
  public:
    void* vptr;
    void Fin();
};
class ShaderAnimationController_2a8620 : public Base_2a8620 {
  public:
    char pad[60];
    Ref_2a8620* m;
    ~ShaderAnimationController_2a8620();
};
ShaderAnimationController_2a8620::~ShaderAnimationController_2a8620() {
    vptr = g_vftable_2a8620;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
