// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Function2<void,int,math::Vector>::vfunc_2 @ 0x001b37e0
namespace math { struct Vector { float x,y,z; }; }
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Function2 : Function {
    virtual void vfunc_2(int unused, const math::Vector* value, int extra);
    char padding[0x18];
    void (__cdecl *callback)(int, math::Vector);
};
void Function2::vfunc_2(int unused, const math::Vector* value, int extra) {
    callback(*(const int*)value, *(const math::Vector*)((const char*)value+4));
}
