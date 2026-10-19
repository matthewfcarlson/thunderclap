struct CStatsManager {
    int FUN_00090d50(const char*);
};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method1_CStatsManager_const_char_int : Function {
    char pad[0x18];
    int (CStatsManager::*method)(const char*);
    virtual void vfunc_2(CStatsManager* manager, const char** argument, int* result);
};
void Method1_CStatsManager_const_char_int::vfunc_2(CStatsManager* manager, const char** argument,
                                                   int* result) {
    int (CStatsManager::*fn)(const char*) = method;
    const char* arg = *argument;
    int value = (manager->*fn)(arg);
    if (result)
        *result = value;
}