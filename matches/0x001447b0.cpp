// Same code shape as 0x0013a8e0 (propagated; names are from that function)
typedef unsigned char byte_1447b0;
class Sub_1447b0 {
  public:
    void f();
};
class Base_1447b0 {
  public:
    void g();
};
extern void cdel(void*);
extern int vftable_1447b0;
class AnimationChargeTrack {
  public:
    int vf;
    char pad1[0x18 - 4];
    Sub_1447b0 a;
    char pad2[0x28 - 0x18 - 1];
    Sub_1447b0 b;
    AnimationChargeTrack* vfunc_5(byte_1447b0 param);
};
AnimationChargeTrack* AnimationChargeTrack::vfunc_5(byte_1447b0 param) {
    vf = (int)&vftable_1447b0;
    b.f();
    a.f();
    ((Base_1447b0*)this)->g();
    if (param & 1)
        cdel(this);
    return this;
}
