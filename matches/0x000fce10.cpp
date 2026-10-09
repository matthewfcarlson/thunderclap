class Obj {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
};
class CControllerAgent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float vfunc_3(int, int);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x58 - 4];
    Obj* member58;
    char pad2[0x20a8 - 0x5c];
    float helper(int, int);
};
float CControllerAgent::vfunc_3(int a, int b) {
    helper(a, b);
    int x = member58->f6();
    if (*(int*)((char*)x + 0x20a8) >= 0)
        *(float*)((char*)this + 8) = 100.0f;
    else
        *(float*)((char*)this + 8) = 0.0f;
    return *(float*)((char*)this + 8);
}