class CStatsManager {
  public:
    int Get(const char*);
};
typedef int (CStatsManager::*StatsFn)(const char*);
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class Method1 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CStatsManager*, const char**, int*);
    char pad[0x1c - 4];
    StatsFn fn;
};
void Method1::vfunc_2(CStatsManager* obj, const char** arg, int* out) {
    StatsFn f = fn;
    const char* a = *arg;
    int r = (obj->*f)(a);
    if (out)
        *out = r;
}