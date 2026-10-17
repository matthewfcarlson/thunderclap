// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CEffectManager,int,const_char_*,math::Vector>::vfunc_2 @ 0x001f76e0
namespace math { struct Vector { float x, y, z; }; }
struct CEffectManager {
    int FUN_001f76e0(const char *, math::Vector);
};
struct EffectArguments {
    const char *name;
    math::Vector position;
};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method2 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CEffectManager *manager, const EffectArguments *args, int *result);
    char padding[0x18];
    int (CEffectManager::*method)(const char *, math::Vector);
};
void Method2::vfunc_2(CEffectManager *manager, const EffectArguments *args, int *result) {
    int value = (manager->*method)(args->name, args->position);
    if (result) *result = value;
}
