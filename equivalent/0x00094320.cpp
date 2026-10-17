// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CUnlockablesManager,void,int,const_char_*,const_char_*>::vfunc_2 @ 0x00094320
struct CUnlockablesManager { char unused; };
struct Arguments { int number; const char *first; const char *second; };
struct Method3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CUnlockablesManager *manager, Arguments *args, void *unused);
    char pad[0x18];
    void (CUnlockablesManager::*method)(int, const char *, const char *);
};
void Method3::vfunc_2(CUnlockablesManager *manager, Arguments *args, void *unused) {
    (manager->*method)(args->number, args->first, args->second);
}
