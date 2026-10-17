// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure0<CCameraManager,math::Vector>::vfunc_2 @ 0x0009cc60
namespace math { struct Vector { float x,y,z; }; }
struct CCameraManager { math::Vector *FUN_0009cc60(math::Vector *out); };
struct Closure {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused0, int unused1, math::Vector *result);
    char pad[0x18];
    math::Vector *(CCameraManager::*method)(math::Vector *);
    CCameraManager *manager;
};
void Closure::vfunc_2(int unused0, int unused1, math::Vector *result) {
    math::Vector temporary;
    math::Vector *value = (manager->*method)(&temporary);
    math::Vector copy = *value;
    if (result) *result = copy;
}
