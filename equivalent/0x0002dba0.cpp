// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CActorManager,void,const_char_*,float,float>::vfunc_2 @ 0x0002dba0
struct CActorManager { void FUN_0002dba0(const char*, float, float); };
struct ActorArgs { const char* name; float first; float second; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method3 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager* actor, ActorArgs* args, void* unused);
    char pad[0x18];
    void (CActorManager::*callback)(const char*, float, float);
};
void Method3::vfunc_2(CActorManager* actor, ActorArgs* args, void* unused) {
    (actor->*callback)(args->name, args->first, args->second);
}