// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CActorManager,void,const_char_*,float,float,float>::vfunc_2 @ 0x0002f790
struct CActorManager { void FUN_00000000(const char *, float, float, float); };
struct ActorArgs { const char *name; float a; float b; float c; };
class Closure4 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, ActorArgs *args, void *unused2);
    char padding[0x18];
    void (CActorManager::*method)(const char *, float, float, float);
    CActorManager *object;
};
void Closure4::vfunc_2(void *unused, ActorArgs *args, void *unused2) {
    (object->*method)(args->name, args->a, args->b, args->c);
}
