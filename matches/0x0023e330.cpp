extern "C" char DAT_00428d24[];
class Ref_23e330 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action {
  public:
    virtual void v0();
    void Init();
};
extern void* Alloc(unsigned int);
class Track {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void* vfunc_10(void*, void*, Ref_23e330*);
};
void* Track::vfunc_10(void* p2, void* p3, Ref_23e330* p4) {
    Action* r = (Action*)Alloc(0x28);
    if (r) {
        r->Init();
        *(void**)((char*)r + 0x1c) = this;
        *(unsigned long*)r = ((int)DAT_00428d24);
        *(unsigned long*)((char*)r + 0x20) = 0;
        if (p4)
            p4->AddRef();
        Ref_23e330* old = *(Ref_23e330**)((char*)r + 0x20);
        if (old)
            old->Release();
        *(Ref_23e330**)((char*)r + 0x20) = p4;
        return r;
    }
    return 0;
}