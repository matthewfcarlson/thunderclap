extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
class P_10d6b0 {
  public:
    void* get();
};
class Q_10d6b0 {
  public:
    void* query();
};
class LeashedCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int, void*, int);
    char pad[8];
    unsigned char value;
};
extern int __cdecl FUN_00344e74(void*, int, int, int, int);
bool LeashedCondition::vfunc_6(int unused, void* params, int unused2) {
    int ok = FUN_00344e74(params, 0, ((int)DAT_00494b44), ((int)DAT_00494b60), 0);
    if (!ok)
        return false;
    void* a = ((P_10d6b0*)params)->get();
    void* b = ((Q_10d6b0*)a)->query();
    if (!b)
        return false;
    void* c = *(void**)((char*)b + 0x1ca0);
    if (!c)
        return false;
    return *((unsigned char*)c + 0xe8) == value;
}