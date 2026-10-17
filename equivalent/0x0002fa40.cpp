// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,float>::vfunc_2 @ 0x0002fa40
struct CActorManager { bool FUN_00000000(const char *, float); };
struct CallArgs { const char *name; float value; };
struct Closure2 {
    char padding[0x1c];
    bool (CActorManager::*method)(const char *, float);
    CActorManager *manager;
    void vfunc_2(void *unused, CallArgs *args, bool *result);
};
void Closure2::vfunc_2(void *unused, CallArgs *args, bool *result)
{
    bool value = (manager->*method)(args->name, args->value);
    if (result) *result = value;
}
