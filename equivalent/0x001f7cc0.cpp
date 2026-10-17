// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CEffectManager,bool,int,math::Vector>::vfunc_2 @ 0x001f7cc0
namespace math { struct Vector { float x, y, z; }; }
struct CEffectManager { bool FUN_001f7cc0(int value, math::Vector position); };
struct EffectArguments { int value; math::Vector position; };
class Closure2 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const EffectArguments *args, bool *result);
    char padding[0x18];
    bool (CEffectManager::*method)(int, math::Vector);
    CEffectManager *manager;
};
void Closure2::vfunc_2(void *unused, const EffectArguments *args, bool *result) {
    bool value = (manager->*method)(args->value, args->position);
    if (result) *result = value;
}