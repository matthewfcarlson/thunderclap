extern "C" char DAT_0041950c[];
struct PropTrack_18c260 {
    void Init();
    unsigned char pad[0x18];
};
void* __cdecl Alloc(unsigned int);
class Factory_18c260 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual PropTrack_18c260* vfunc_5();
};
PropTrack_18c260* Factory_18c260::vfunc_5() {
    PropTrack_18c260* p = (PropTrack_18c260*)Alloc(0x18);
    if (p) {
        p->Init();
        p->pad[0x14] = 1;
        *(int*)(p->pad + 8) = 1;
        *(int*)p->pad = ((int)DAT_0041950c);
        *(int*)(p->pad + 0xc) = 0;
        *(int*)(p->pad + 0x10) = 0;
    }
    if (!p)
        return 0;
    return p;
}