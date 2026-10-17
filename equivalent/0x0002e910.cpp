// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,const_char_*,float,bool>::vfunc_2 @ 0x0002e910
struct CActorManager { void FUN_00000000(const char *, float, bool); };
struct Arguments { const char *name; float value; bool flag; };
struct Closure3_CActorManager {
    void *vtable;
    char padding[0x18];
    void (CActorManager::*method)(const char *, float, bool);
    CActorManager *object;
    void vfunc_2(void *, const Arguments *, void *);
};
void Closure3_CActorManager::vfunc_2(void *, const Arguments *args, void *) {
    (object->*method)(args->name, args->value, args->flag);
}