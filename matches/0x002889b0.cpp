extern "C" void _ReadWriteBarrier();
extern int anim_vt;
class Base {
  public:
    virtual void B();
    int b[3];
    Base();
};
class Animation : public Base {
  public:
    virtual void B();
    Animation();
    int x10;
    float x14;
    unsigned char x18;
    char pad2[3];
    int x1c[8];
};
Animation::Animation() : Base() {
    x10 = 0;
    x18 = 0;
    x1c[0] = 0;
    x1c[1] = 0;
    x1c[2] = 0;
    x1c[3] = 0;
    x1c[4] = 0;
    x1c[5] = 0;
    x1c[6] = 0;
    x1c[7] = 0;
    *((int*)this) = (int)&anim_vt;
    _ReadWriteBarrier();
    x14 = 30.0f;
}
