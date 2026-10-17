// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x000301b0
struct Vector { float x, y, z; };
struct CActorManager { bool FUN_000301b0(const char *, Vector); };
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, const void *, bool *);
    char padding[0x18];
    bool (CActorManager::*method)(const char *, Vector);
    CActorManager *actor;
};
void Closure2::vfunc_2(void *, const void *data, bool *result) {
    struct Arguments { const char *name; Vector position; };
    const Arguments *args = (const Arguments *)data;
    bool value = (actor->*method)(args->name, args->position);
    if (result) *result = value;
}