// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure2<CCameraManager,void,math::Vector,math::Vector>::vfunc_2 @ 0x0009cab0
namespace math { struct Vector { float x,y,z; }; }
struct CCameraManager { void FUN_0009cab0(math::Vector, math::Vector); };
struct VectorPair { math::Vector first, second; };
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused1, VectorPair *args, int unused2);
    char padding[0x18];
    void (CCameraManager::*method)(math::Vector, math::Vector);
    CCameraManager *object;
};
void Closure2::vfunc_2(int unused1, VectorPair *args, int unused2) {
    (object->*method)(args->first, args->second);
}