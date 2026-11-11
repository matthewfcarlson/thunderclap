// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000edf60..0x000ee9b0 (kind game, layer game, confidence high), dominant class ImageSelector
// (tree_prelude.h: not needed)


// 0x000edfe0 ImageSelector::vfunc_9 (26 B): matches/0x000edfe0.cpp [isolated: compile error C2664: 'fn_000edfe0::Inner_edfe0::f15' : cannot convert parameter 2 from 'fn_000edfe0::ImageSelector *const ' to 'ImageSelector]
// sym: ?v9@ImageSelector@fn_f6440f64@@UAEMXZ
namespace fn_f6440f64 {} using namespace fn_f6440f64;
namespace fn_f6440f64 {
class Inner_edfe0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15(void*, class ImageSelector*);
};
struct Vec3_edfe0 {
    float x, y, z;
};
class ImageSelector {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    char pad[0x10];
    Inner_edfe0* mInner;
};
float ImageSelector::v9() {
    Vec3_edfe0 t;
    mInner->f15(&t, this);
    return t.x;
}
} // namespace fn_f6440f64

