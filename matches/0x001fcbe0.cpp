class Obj {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual char V11();
};

extern "C" Obj* __stdcall FUN_001fc7f0(int);

char __stdcall FUN_001fcbe0(int a) {
    Obj* r = FUN_001fc7f0(a);
    if (!r)
        return 1;
    return r->V11();
}
