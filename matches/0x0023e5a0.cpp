extern int gState_23e5a0;
class Helper_23e5a0 {
  public:
    bool Check(int, int, int);
};
class Finisher {
  public:
    void Finish();
};
namespace fight {
class StopAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool v5(int, int);
    char pad[0x18];
    int m1c;
    Helper_23e5a0* m20;
    Finisher* m24;
    int m28;
    bool vfunc_5(int value, int unused);
};
bool StopAction::vfunc_5(int value, int unused) {
    if (value == gState_23e5a0) {
        if (((char*)m20, ((Helper_23e5a0*)((char*)m20 + 0x14)))->Check(m1c, m28, 0)) {
            m24->Finish();
            return false;
        }
    }
    return true;
}
} // namespace fight