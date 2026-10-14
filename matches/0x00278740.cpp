class Obj_278740 {
  public:
    virtual void V0();
    virtual void V1();
};
class GlobalObj_278740 {
  public:
    virtual void V0();
    virtual void V1();
};
class XboxSaveDrive {
  public:
    void Run();
    void Init();
    void Finish();
    char pad0[0xb8];
    Obj_278740* mObj;
    char padbc[4];
    int vbc;
    int vc0;
};
extern int vt0_278740, vt4, vtc, vtbc, vtc0;
extern GlobalObj_278740* gObj_278740;
extern int gBss_278740;
extern void Cleanup(int*);
void XboxSaveDrive::Run() {
    *(int*)this = (int)&vt0_278740;
    *(int*)((char*)this + 4) = (int)&vt4;
    *(int*)((char*)this + 0xc) = (int)&vtc;
    *(int*)((char*)this + 0xbc) = (int)&vtbc;
    *(int*)((char*)this + 0xc0) = (int)&vtc0;
    Init();
    if (*(int*)((char*)mObj + 0x10) == 1) {
        gObj_278740->V1();
        gObj_278740 = 0;
        Cleanup(&gBss_278740);
        return Finish();
    }
    mObj->V1();
    return Finish();
}