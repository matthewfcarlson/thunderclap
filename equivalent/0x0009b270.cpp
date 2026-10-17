// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method2<CCameraManager,void,math::Vector,math::Vector>::vfunc_2 @ 0x0009b270
namespace math { struct Vector { float x, y, z; }; }
struct CCameraManager { void FUN_0009b270(math::Vector, math::Vector); };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method2 : Function {
    virtual void vfunc_2(CCameraManager* manager, const math::Vector* args, void* unused);
    char padding[0x18];
    void (CCameraManager::*method)(math::Vector, math::Vector);
};
void Method2::vfunc_2(CCameraManager* manager, const math::Vector* args, void* unused) {
    (manager->*method)(args[0], args[1]);
}
