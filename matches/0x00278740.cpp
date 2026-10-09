class Obj {
  public:
    virtual void V0();
    virtual void V1();
};
class GlobalObj {
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
    Obj* mObj;
    char padbc[4];
    int vbc;
    int vc0;
};
extern int vt0, vt4, vtc, vtbc, vtc0;
extern GlobalObj* gObj;
extern int gBss;
extern void Cleanup(int*);
void XboxSaveDrive::Run() {
    *(int*)this = (int)&vt0;
    *(int*)((char*)this + 4) = (int)&vt4;
    *(int*)((char*)this + 0xc) = (int)&vtc;
    *(int*)((char*)this + 0xbc) = (int)&vtbc;
    *(int*)((char*)this + 0xc0) = (int)&vtc0;
    Init();
    if (*(int*)((char*)mObj + 0x10) == 1) {
        gObj->V1();
        gObj = 0;
        Cleanup(&gBss);
        return Finish();
    }
    mObj->V1();
    return Finish();
}