// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure0<CGameFlowManager,math::Vector>::vfunc_2 @ 0x0008b1b0
namespace math { struct Vector { float x, y, z; }; }
struct CGameFlowManager { math::Vector* run(math::Vector* result); };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Closure0 : Function {
    char padding[0x18];
    math::Vector* (CGameFlowManager::*method)(math::Vector*);
    CGameFlowManager* object;
    virtual void vfunc_2(void* unused1, void* unused2, math::Vector* output);
};
void Closure0::vfunc_2(void* unused1, void* unused2, math::Vector* output) {
    math::Vector temporary;
    math::Vector result = (object->*method)(&temporary)[0];
    if (output) *output = result;
}