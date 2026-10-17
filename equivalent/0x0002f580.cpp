// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,int>::vfunc_2 @ 0x0002f580
struct CActorManager { bool callback(const char *, int); };
struct ActorArgs { const char *name; int value; };
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const ActorArgs *args, bool *result);
    char padding[0x18];
    bool (CActorManager::*method)(const char *, int);
    CActorManager *manager;
};
void Closure2::vfunc_2(void *unused, const ActorArgs *args, bool *result) {
    bool value = (manager->*method)(args->name, args->value);
    if (result) *result = value;
}