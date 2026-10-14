class Obj_323be0 {
  public:
    virtual void Init();
    Obj_323be0* Create(void*, int);
    void Attach(unsigned int*);
};
class ExtTexture {
  public:
    virtual void v0();
    virtual Obj_323be0* vfunc_1(int);
    virtual void v2();
    void* member4;
    Obj_323be0* member8;
    unsigned int* memberC;
    unsigned int member10;
};
void* __cdecl Allocate(unsigned int);
unsigned int* __stdcall GetBackBuffer(int);
Obj_323be0* ExtTexture::vfunc_1(int param) {
    if (!member8) {
        Obj_323be0* p = (Obj_323be0*)Allocate(0xf8);
        Obj_323be0* r;
        if (p)
            r = p->Create(member4, 0);
        else
            r = 0;
        member8 = r;
        r->Init();
        unsigned int* b = GetBackBuffer(param ? 0 : -1);
        memberC = b;
        unsigned int o = *b;
        member10 = o;
        *b = (o & 0xfffcffff) | 0x40000;
        member8->Attach(memberC);
    }
    return member8;
}
