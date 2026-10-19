struct CStatsManager {
    int invoke(const char*);
};
typedef int (CStatsManager::*StatsMethod)(const char*);
struct Closure1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, const char**, int*);
    char padding[0x18];
    StatsMethod method;
    CStatsManager* object;
};
void Closure1::vfunc_2(void* unused, const char** argument, int* result) {
    CStatsManager* obj = object;
    StatsMethod fn = method;
    int value = (obj->*fn)(*argument);
    if (result)
        *result = value;
}