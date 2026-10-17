// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<HUDOverlay,void,int,int,math::Vector>::vfunc_2 @ 0x000d0040
namespace math { struct Vector { float x,y,z; }; }
struct HUDOverlay { void invoked(int, int, math::Vector); };
struct Closure3 { char padding[0x1c]; void (HUDOverlay::*method)(int,int,math::Vector); HUDOverlay* object; void vfunc_2(void* unused, const int* args, void* unused2); };
void Closure3::vfunc_2(void* unused, const int* args, void* unused2) {
    math::Vector v;
    const math::Vector* source = (const math::Vector*)(args+2);
    v = *source;
    (object->*method)(args[0],args[1],v);
}