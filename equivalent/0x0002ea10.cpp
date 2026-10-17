// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CActorManager,int,const_char_*>::vfunc_2 @ 0x0002ea10
struct CActorManager { int FUN_00000000(const char *); };
typedef int (CActorManager::*ActorMethod)(const char *);
struct Closure1_CActorManager_int_const_char {
    char padding[0x1c];
    ActorMethod method;
    CActorManager *actor;
    void vfunc_2(void *unused, const char **argument, int *result);
};
void Closure1_CActorManager_int_const_char::vfunc_2(void *unused, const char **argument, int *result) {
    int value = (actor->*method)(*argument);
    if (result) *result = value;
}
