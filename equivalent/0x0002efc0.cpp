// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,const_char_*>::vfunc_2 @ 0x0002efc0
struct CActorManager { bool FUN_0002efc0(const char *, const char *); };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Closure2 : Function {
    char padding[0x18];
    bool (CActorManager::*method)(const char *, const char *);
    CActorManager *actor;
    virtual void vfunc_2(void *unused, const char **args, bool *result);
};
void Closure2::vfunc_2(void *unused, const char **args, bool *result) {
    bool value = (actor->*method)(args[0], args[1]);
    if (result) *result = value;
}