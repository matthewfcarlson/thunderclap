// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,const_char_*,const_char_*,int>::vfunc_2 @ 0x0002fbe0
struct CActorManager {};
typedef int (CActorManager::*ActorMethod)(const char *, const char *);
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const char **arguments, int *result);
    char padding[0x18];
    ActorMethod method;
    CActorManager *actorManager;
};
void Closure2::vfunc_2(void *unused, const char **arguments, int *result)
{
    int value = (actorManager->*method)(arguments[0], arguments[1]);
    if (result != 0)
        *result = value;
}