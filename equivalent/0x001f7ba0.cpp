// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CEffectManager,int,const_char_*,math::Vector>::vfunc_2 @ 0x001f7ba0
namespace math { struct Vector { float x,y,z; }; }
struct CEffectManager { int FUN_001f7ba0(int, math::Vector); };
struct Arguments { int id; math::Vector position; };
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, Arguments* args, int* result);
    char padding[0x18];
    int (CEffectManager::*method)(int, math::Vector);
    CEffectManager* manager;
};
void Closure2::vfunc_2(void* unused, Arguments* args, int* result) {
    int value = (manager->*method)(args->id, args->position);
    if (result) *result = value;
}