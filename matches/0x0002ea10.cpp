struct CActorManager {
    int FUN_00000000(const char*);
};
typedef int (CActorManager::*ActorMethod)(const char*);
struct Closure1_CActorManager_int_const_char {
    char padding[0x1c];
    ActorMethod method;
    CActorManager* actor;
    void vfunc_2(void* unused, const char** argument, int* result);
};
void Closure1_CActorManager_int_const_char::vfunc_2(void* unused, const char** argument, int* result) {
    CActorManager* a = actor;
    ActorMethod fn = method;
    int value = (a->*fn)(*argument);
    if (result)
        *result = value;
}