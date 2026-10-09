// Same code shape as 0x0013ad70 (propagated; names are from that function)
extern char AnimAction_vt;

namespace hulkfight {
namespace motion {

class MemObj {
  public:
    virtual void f0();
    virtual void Release();
};

class Base {
  public:
    virtual void vf();
    void Cleanup();
    char pad[0x18];
};

class AnimationAction : public Base {
  public:
    void Destroy();
    MemObj* m1c;
    MemObj* m20;
    MemObj* m24;
};

void AnimationAction::Destroy() {
    volatile int* v = (volatile int*)this;
    v[0] = (int)&AnimAction_vt;
    MemObj* a = (MemObj*)v[8];
    if (a) {
        a->Release();
        v[8] = 0;
    }
    int b = v[7];
    if (b) {
        v[7] = 0;
    }
    MemObj* c = (MemObj*)v[9];
    if (c) {
        c->Release();
        v[9] = 0;
    }
    Base::Cleanup();
}

} // namespace motion
} // namespace hulkfight
