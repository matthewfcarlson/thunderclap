// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CAmbientsManager,void,const_char_*,unsigned_int,float>::vfunc_2 @ 0x0007d500
struct CAmbientsManager { void FUN_0007d500(const char *, unsigned int, float); };
struct Args { const char *name; unsigned int value; float amount; };
struct Method3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CAmbientsManager *manager, const Args *args, void *unused);
    char pad[0x18];
    void (CAmbientsManager::*callback)(const char *, unsigned int, float);
};
void Method3::vfunc_2(CAmbientsManager *manager, const Args *args, void *unused) {
    (manager->*callback)(args->name, args->value, args->amount);
}
