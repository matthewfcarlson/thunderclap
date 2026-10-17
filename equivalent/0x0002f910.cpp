// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure3<CActorManager,bool,const_char_*,float,float>::vfunc_2 @ 0x0002f910
struct CActorManager { bool FUN_0002f910(const char *, float, float); };
struct Arguments { const char *name; float first; float second; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, const Arguments *, bool *);
    char pad[0x18];
    bool (CActorManager::*method)(const char *, float, float);
    CActorManager *object;
};
void Closure3::vfunc_2(void *, const Arguments *args, bool *result) {
    bool value = (object->*method)(args->name, args->first, args->second);
    if (result) *result = value;
}
