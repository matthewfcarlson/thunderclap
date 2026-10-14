extern "C" char DAT_00494b44[];
extern "C" char DAT_004c13d0[];
struct R_1a4c50 {
    char a[4];
    int type;
    char b[12];
    int name;
};
extern void* Find(void*, int, void*, void*, int);
struct Obj_1a4c50 {
    R_1a4c50* Get();
};
class C_1a4c50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool f6(void* x, void* y, void* z);
    char pad[8];
    int mode;
    int expected;
};
bool C_1a4c50::f6(void* x, void* y, void* z) {
    void* p = Find(y, 0, (void*)((int)DAT_00494b44), (void*)((int)DAT_004c13d0), 0);
    if (!p)
        return false;
    R_1a4c50* q = ((Obj_1a4c50*)p)->Get();
    if (q->type != 15)
        return false;
    int n = q->name;
    switch (mode) {
    case 0:
        return n == expected;
    case 1:
        return n != expected;
    }
    return false;
}
