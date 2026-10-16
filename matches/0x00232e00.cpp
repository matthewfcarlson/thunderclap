extern "C" __int64 __cdecl helper(int, int, int);
class Obj {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(__int64, int);
    void Fn(int, int);
};
void Obj::Fn(int a, int b) {
    v10(helper(a, 0, 0), b);
}
