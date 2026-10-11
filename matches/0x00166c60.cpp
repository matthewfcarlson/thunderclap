extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
extern int check(void*, int, void*, void*, int);
struct Obj {
    void* getA();
    void* getB();
};
class TargetingCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(void* unused, void* params, void* last);
    char pad[8];
    unsigned char value;
};
bool TargetingCondition::vfunc_6(void* unused, void* params, void* last) {
    if (!check(params, 0, (void*)((int)DAT_00494b44), (void*)((int)DAT_00494b60), 0))
        return false;
    void* x = ((Obj*)params)->getA();
    void* y = ((Obj*)x)->getB();
    return *((unsigned char*)y + 0x32c) == value;
}
