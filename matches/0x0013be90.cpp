// Same code shape as 0x0013bde0 (propagated; names are from that function)
extern "C" {
void* g_anim_vtable;
void __cdecl opdel(void*);
void _ReadWriteBarrier();
}

class RefObj_13be90 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};

namespace hulkfight {
namespace motion {

class AnimationAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    AnimationAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    void Cleanup();

    char pad[0x18];
    int m1c;
    RefObj_13be90* m20;
    RefObj_13be90* m24;
};

AnimationAction* AnimationAction::vfunc_2(unsigned char param) {
    *(int*)this = (int)&g_anim_vtable;
    _ReadWriteBarrier();
    RefObj_13be90* a = m20;
    if (a) {
        a->Release();
        m20 = 0;
    }
    int v = m1c;
    if (v) {
        m1c = 0;
    }
    RefObj_13be90* b = m24;
    if (b) {
        b->Release();
        m24 = 0;
    }
    this->Cleanup();
    if (param & 1) {
        opdel(this);
    }
    return this;
}

} // namespace motion
} // namespace hulkfight
