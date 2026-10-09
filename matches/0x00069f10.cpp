extern const float zero;
class Helper {
  public:
    int Apply(int, float);
};
extern int __cdecl FUN_0008d690(int);
class CDrainHealthTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual float GetValue();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual int vfunc_12(int);
    virtual void f13();
    char pad[0x10];
    float amount;
};
int CDrainHealthTrack::vfunc_12(int arg) {
    float value = GetValue();
    if (!(value <= zero)) {
        float a = amount;
        int obj = FUN_0008d690(0x24);
        if (obj)
            return ((Helper*)obj)->Apply(arg, a / value);
    }
    return 0;
}
