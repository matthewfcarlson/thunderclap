// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CUnlockablesManager,const_char_*,int>::vfunc_2 @ 0x00094aa0
struct CUnlockablesManager { char unused; int FUN_00094aa0(const char *); };
struct Closure1_CUnlockablesManager_const_char_int {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const char **argument, int *result);
    char pad[0x18];
    int (CUnlockablesManager::*method)(const char *);
    CUnlockablesManager *object;
};
void Closure1_CUnlockablesManager_const_char_int::vfunc_2(void *unused, const char **argument, int *result) {
    int value = (object->*method)(*argument);
    if (result) *result = value;
}
