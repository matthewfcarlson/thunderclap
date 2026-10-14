typedef unsigned int u32_238c40;
extern void PrintSomething(u32_238c40, u32_238c40, const char*, u32_238c40);
char fmt_238c40[] = "%s\n";
class PrintCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(u32_238c40, u32_238c40, u32_238c40);
    char pad[8];
    u32_238c40 a;
    u32_238c40 b;
};
bool PrintCondition::vfunc_6(u32_238c40 x, u32_238c40 y, u32_238c40 z) {
    if (b)
        PrintSomething(y, a, fmt_238c40, b);
    return true;
}