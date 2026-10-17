// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method1<CStatsManager,const_char_*,int>::vfunc_2 @ 0x00090d50
struct CStatsManager { int FUN_00090d50(const char *); };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method1_CStatsManager_const_char_int : Function {
    char pad[0x18];
    int (CStatsManager::*method)(const char *);
    virtual void vfunc_2(CStatsManager *manager, const char **argument, int *result);
};
void Method1_CStatsManager_const_char_int::vfunc_2(CStatsManager *manager, const char **argument, int *result) {
    int value = (manager->*method)(*argument);
    if (result) *result = value;
}
