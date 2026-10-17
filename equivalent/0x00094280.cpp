// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CUnlockablesManager,void,int,int,bool>::vfunc_2 @ 0x00094280
struct CUnlockablesManager { };
struct Arguments { int first; int second; unsigned char third; };
struct Method3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CUnlockablesManager *object, Arguments *arguments, void *unused);
    char pad[24];
    void (CUnlockablesManager::*method)(int, int, int);
};
void Method3::vfunc_2(CUnlockablesManager *object, Arguments *arguments, void *unused) {
    (object->*method)(arguments->first, arguments->second, arguments->third);
}
