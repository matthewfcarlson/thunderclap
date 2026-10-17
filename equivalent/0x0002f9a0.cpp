// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,const_char_*,float,float>::vfunc_2 @ 0x0002f9a0
struct CActorManager { char placeholder; };
struct Args { const char* name; float first; float second; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, Args*, void*);
    char pad[0x1c - 4];
    void (CActorManager::*method)(const char*, float, float);
    CActorManager* actor;
};
void Closure3::vfunc_2(void* unused, Args* args, void* unused2) {
    (actor->*method)(args->name, args->first, args->second);
}
