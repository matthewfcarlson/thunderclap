// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CStatsManager,const_char_*,int>::vfunc_2 @ 0x000912e0
struct CStatsManager { int FUN_00000000(const char *); };
struct Closure1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, const char **value, int *result);
    char pad[0x18];
    int (CStatsManager::*method)(const char *);
    CStatsManager *object;
};
void Closure1::vfunc_2(void *, const char **value, int *result) {
    int resultValue = (object->*method)(*value);
    if (result) *result = resultValue;
}
