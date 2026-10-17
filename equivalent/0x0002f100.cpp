// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CActorManager,math::Vector,const_char_*>::vfunc_2 @ 0x0002f100
struct Vector { float x, y, z; };
struct CActorManager { Vector FUN_0002f100(const char *name); };
struct Closure {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const char **name, Vector *result);
    char pad[0x18];
    Vector (CActorManager::*method)(const char *);
    CActorManager *actorManager;
};
void Closure::vfunc_2(void *unused, const char **name, Vector *result) {
    Vector value = (actorManager->*method)(*name);
    if (result) *result = value;
}