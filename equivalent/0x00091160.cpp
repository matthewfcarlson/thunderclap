// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CStatsManager,int,const_char_*>::vfunc_2 @ 0x00091160
struct CStatsManager { int invoke(const char *); };
typedef int (CStatsManager::*StatsMethod)(const char *);
struct Closure1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const char **argument, int *result);
    char padding[0x18];
    StatsMethod method;
    CStatsManager *object;
};
void Closure1::vfunc_2(void *unused, const char **argument, int *result) {
    int value = (object->*method)(*argument);
    if (result) *result = value;
}
