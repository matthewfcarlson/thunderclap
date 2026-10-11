extern "C" char DAT_003fe778[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class CGrappleDrainHealthTrack {
  public:
    void Init();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CGrappleDrainHealthTrack* vfunc_5();
};
CGrappleDrainHealthTrack* Factory::vfunc_5() {
    CGrappleDrainHealthTrack* p = (CGrappleDrainHealthTrack*)FUN_0008d690(0x18);
    if (p) {
        p->Init();
        *(unsigned int*)p = ((int)DAT_003fe778);
        return p;
    }
    return 0;
}