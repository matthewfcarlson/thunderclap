class PlayerBink {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void vfunc_8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    char pad[0x14];
    int state;
    int arg;
};
extern void __stdcall FUN_00366b40(int, int);
void PlayerBink::vfunc_8() {
    if (state == 3) {
        FUN_00366b40(arg, 0);
        state = 4;
        return;
    }
    if (state == 1)
        state = 2;
}