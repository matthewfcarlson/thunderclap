// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CActorManager,void,const_char_*,float,const_char_*>::vfunc_2 @ 0x0002c930
struct CActorManager {};
struct Args { const char *first; float second; const char *third; };
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager *, const Args *, void *);
};
struct Method3 : Function {
    char padding[0x1c - sizeof(Function)];
    void (CActorManager::*callback)(const char *, float, const char *);
    virtual void vfunc_2(CActorManager *, const Args *, void *);
};
void Method3::vfunc_2(CActorManager *actor, const Args *args, void *) {
    (actor->*callback)(args->first, args->second, args->third);
}
