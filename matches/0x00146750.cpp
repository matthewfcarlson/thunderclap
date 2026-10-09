class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* vfunc_5();
};
class Motion {
  public:
    void Init();
};
extern void* __cdecl Alloc(unsigned int);
void* Factory::vfunc_5() {
    Motion* p = (Motion*)Alloc(0x14);
    if (p) {
        p->Init();
        *(int*)p = 0x413004;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return p;
    }
    return (void*)((char*)p - (char*)p);
}