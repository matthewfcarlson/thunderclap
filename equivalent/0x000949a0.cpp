// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CUnlockablesManager,void,int,int,bool>::vfunc_2 @ 0x000949a0
struct CUnlockablesManager { void placeholder(); };
struct Arguments { int first; int second; bool third; };
struct Closure3_CUnlockablesManager {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused1, Arguments* arguments, void* unused3);
    char padding[0x18];
    void (CUnlockablesManager::*method)(int, int, bool);
    CUnlockablesManager* object;
};
void Closure3_CUnlockablesManager::vfunc_2(void* unused1, Arguments* arguments, void* unused3) {
    (object->*method)(arguments->first, arguments->second, arguments->third);
}
