// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CActorManager,void,int,int,int>::vfunc_2 @ 0x0002e330
struct CActorManager { void FUN_0002e330(int, int, int); };
struct Args { int first, second, third; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method3 : Function {
    virtual void vfunc_2(CActorManager* actor, Args* args, int unused);
    char pad[0x18];
    void (CActorManager::*callback)(int,int,int);
};
void Method3::vfunc_2(CActorManager* actor, Args* args, int unused) {
    (actor->*callback)(args->first, args->second, args->third);
}
