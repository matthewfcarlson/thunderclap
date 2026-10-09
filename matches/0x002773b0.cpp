class CementLibrary {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad[0x20 - 4];
    int field;
};
void thunk_FUN_00270a50();
void FUN_0026d6d0(int);
void CementLibrary::vfunc_4() {
    while (field == 0) {
        thunk_FUN_00270a50();
        FUN_0026d6d0(0);
    }
}