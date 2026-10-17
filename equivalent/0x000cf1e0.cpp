// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<HUDOverlay,void,int,int,math::Vector>::vfunc_2 @ 0x000cf1e0
namespace math { struct Vector { float x, y, z; }; }
struct HUDOverlay {
    void FUN_00000000(int a, int b, math::Vector v);
};
struct Arguments { int a; int b; math::Vector v; };
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(HUDOverlay *, Arguments *, void *);
};
struct Method3 : Function {
    char reserved[24];
    void (HUDOverlay::*callback)(int,int,math::Vector);
    virtual void vfunc_2(HUDOverlay *object, Arguments *args, void *unused);
};
void Method3::vfunc_2(HUDOverlay *object, Arguments *args, void *unused) {
    (object->*callback)(args->a, args->b, args->v);
}
