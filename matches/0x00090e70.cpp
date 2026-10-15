class CStatsManager {
  public:
    void Action(const char*, const char*, int, int, int, int);
};
class Closure6 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, const int*, int);
    char pad[0x18];
    void (CStatsManager::*method)(const char*, const char*, int, int, int, int);
    CStatsManager* object;
};
void Closure6::vfunc_2(int, const int* args, int) {
    const int* p = args;
    int a = *p++;
    int b = *p++;
    int c = *p++;
    int d = *p++;
    int e = *p++;
    int f = *p++;
    (object->*method)((const char*)a, (const char*)b, c, d, e, f);
}