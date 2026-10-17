// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,int,int,int>::vfunc_2 @ 0x000300b0
struct CActorManager { void FUN_000300b0(int, int, int); };
struct Triple { int first; int second; int third; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, Triple *, int);
    char pad[0x18];
    void (CActorManager::*method)(int, int, int);
    CActorManager *object;
};
void Closure3::vfunc_2(int, Triple *args, int) {
    (object->*method)(args->first, args->second, args->third);
}
