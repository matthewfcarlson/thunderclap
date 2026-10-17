// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CActorManager,const_char_*,const_char_*>::vfunc_2 @ 0x0002eaa0
struct CActorManager { const char *FUN_0002eaa0(const char *); };
struct Closure1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(const char *, const char **, const char **);
    char pad[0x18];
    const char *(CActorManager::*method)(const char *);
    CActorManager *actor;
};
void Closure1::vfunc_2(const char *unused, const char **arg, const char **out) {
    const char *result = (actor->*method)(*arg);
    if (out) *out = result;
}