// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<HUDOverlay,void,const_char_*,float,float,math::Vector>::vfunc_2 @ 0x000ceb30
struct Vector { float x,y,z; };
struct HUDOverlay {};
struct Method4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(HUDOverlay* object, const unsigned int* args, void* unused);
    char pad[0x18];
    void (HUDOverlay::*handler)(const char*, float, float, Vector);
};
void Method4::vfunc_2(HUDOverlay* object, const unsigned int* args, void* unused)
{
    union Bits { unsigned int u; float f; } a, b, x, y, z;
    a.u=args[1]; b.u=args[2];
    x.u=args[3]; y.u=args[4]; z.u=args[5];
    Vector v; v.x=x.f; v.y=y.f; v.z=z.f;
    (object->*handler)((const char*)args[0], a.f, b.f, v);
}
