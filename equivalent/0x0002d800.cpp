// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CActorManager,void,const_char_*,float,int,float>::vfunc_2 @ 0x0002d800
struct CActorManager { char unused; };
struct Args { const char *name; float value; int count; float other; };
struct Method4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager *, const Args *, void *);
    char pad[0x18];
    void (CActorManager::*method)(const char *, float, int, float);
};
void Method4::vfunc_2(CActorManager *actor, const Args *args, void *) {
    (actor->*method)(args->name, args->value, args->count, args->other);
}