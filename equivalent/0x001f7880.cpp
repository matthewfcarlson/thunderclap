// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CEffectManager,bool,int,math::Vector>::vfunc_2 @ 0x001f7880
namespace math { struct Vector { float x, y, z; }; }
struct CEffectManager { bool effect(int id, math::Vector position); };
struct Arguments { int id; math::Vector position; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };
struct Method2 : Function {
    char padding[0x18];
    bool (CEffectManager::*method)(int, math::Vector);
    virtual void vfunc_2(CEffectManager *object, Arguments *args, bool *result);
};
void Method2::vfunc_2(CEffectManager *object, Arguments *args, bool *result) {
    bool value = (object->*method)(args->id, args->position);
    if (result) *result = value;
}