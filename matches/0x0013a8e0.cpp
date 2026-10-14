typedef unsigned char byte_13a8e0;
class Sub_13a8e0 {
  public:
    void f();
};
class Base_13a8e0 {
  public:
    void g();
};
extern void cdel(void*);
extern int vftable_13a8e0;
class AnimationChargeTrack {
  public:
    int vf;
    char pad1[0x18 - 4];
    Sub_13a8e0 a;
    char pad2[0x28 - 0x18 - 1];
    Sub_13a8e0 b;
    AnimationChargeTrack* vfunc_5(byte_13a8e0 param);
};
AnimationChargeTrack* AnimationChargeTrack::vfunc_5(byte_13a8e0 param) {
    vf = (int)&vftable_13a8e0;
    b.f();
    a.f();
    ((Base_13a8e0*)this)->g();
    if (param & 1)
        cdel(this);
    return this;
}
