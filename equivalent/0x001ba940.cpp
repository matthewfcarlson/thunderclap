// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure0<CRenderManager,math::Vector>::vfunc_2 @ 0x001ba940
namespace math { struct Vector { float x,y,z; }; }
struct CRenderManager {};
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(int, int, math::Vector *); };
struct Closure : Function {
    char pad[0x1c - 4];
    math::Vector (CRenderManager::*method)();
    CRenderManager *manager;
    virtual void vfunc_2(int a, int b, math::Vector *result);
};
void Closure::vfunc_2(int a, int b, math::Vector *result) {
    math::Vector value = (manager->*method)();
    if (result) *result = value;
}