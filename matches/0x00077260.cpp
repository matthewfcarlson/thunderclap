class CMoveAddYTrack {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    int pad4;
    int m8;
    int mc;
    float m10;
    float m14;
    int m18;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(int);
extern int vtable;
CMoveAddYTrack* __fastcall target(void* self) {
    CMoveAddYTrack* p = (CMoveAddYTrack*)FUN_0008d690(0x1c);
    if (p) {
        p->Init();
        p->m10 = 1.0f;
        p->m14 = 1.0f;
        *(int*)p = (int)&vtable;
        p->mc = 0;
        p->m18 = 0;
        p->m8 = 1;
        return p;
    }
    return 0;
}