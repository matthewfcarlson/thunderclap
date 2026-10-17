// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method2<CActorManager,void,const_char_*,math::Vector>::vfunc_2 @ 0x0002c5b0
namespace math { struct Vector { float x, y, z; }; }
struct CActorManager { void FUN_0002c5b0(const char *, math::Vector); };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method2 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager *actor, const void *args, int unused);
    char padding[0x18];
    void (CActorManager::*method)(const char *, math::Vector);
};
struct Args { const char *name; math::Vector position; };
void Method2::vfunc_2(CActorManager *actor, const void *data, int) {
    const Args *args = (const Args *)data;
    (actor->*method)(args->name, args->position);
}
