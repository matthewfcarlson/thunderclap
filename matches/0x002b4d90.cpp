extern "C" char DAT_0042e584[];
typedef unsigned int u32_2b4d90;
void* alloc(unsigned int);
class ShadowMeshBufferImpl {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual ShadowMeshBufferImpl* vfunc_4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    void initialize();
    char pad[0x44];
};
ShadowMeshBufferImpl* ShadowMeshBufferImpl::vfunc_4() {
    ShadowMeshBufferImpl* p = (ShadowMeshBufferImpl*)alloc(0x48);
    if (p) {
        p->initialize();
        *(u32_2b4d90*)p = ((int)DAT_0042e584);
        *(u32_2b4d90*)((char*)p + 0x40) = 0;
        *(u32_2b4d90*)((char*)p + 0x10) = 2;
        return p;
    }
    return 0;
}