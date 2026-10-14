typedef unsigned int U_23e880;
extern void* __cdecl FUN_0008d690(int);
class Helper_23e880 {
  public:
    U_23e880 FUN_0023e610(U_23e880, U_23e880, U_23e880, U_23e880);
};
class StopTrack {
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
    virtual U_23e880 vfunc_10(U_23e880 a, U_23e880 b, U_23e880 c);
};
U_23e880 StopTrack::vfunc_10(U_23e880 a, U_23e880 b, U_23e880 c) {
    Helper_23e880* p = (Helper_23e880*)FUN_0008d690(0x2c);
    if (p)
        return p->FUN_0023e610(a, (U_23e880)this, b, c);
    return 0;
}