class Obj_60850 {
  public:
    int run(void*, int, int);
};
class CGrappleEffectTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual int vfunc_10(int, int, int);
    virtual void f11();
};
struct Thing_60850 {
    char pad[0x104];
    int value;
};
extern void* Alloc(int);
extern Thing_60850* GetThing(int);
int CGrappleEffectTrack::vfunc_10(int a, int b, int c) {
    void* p = Alloc(0x2c);
    if (p) {
        Thing_60850* q = GetThing(c);
        int value = q->value;
        return ((Obj_60850*)p)->run(this, value, a);
    }
    return 0;
}