// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<HUDOverlay,int,int,math::Vector>::vfunc_2 @ 0x000cfcb0
namespace math { struct Vector { float x,y,z; }; }
struct HUDOverlay { int FUN_00000000(int, math::Vector); };
struct Args { int number; math::Vector vector; };
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int ignored, Args* arguments, int* result);
    char padding[0x18];
    int (HUDOverlay::*method)(int, math::Vector);
    HUDOverlay* object;
};
void Closure2::vfunc_2(int ignored, Args* arguments, int* result) {
    int value = (object->*method)(arguments->number, arguments->vector);
    if (result) *result = value;
}