extern "C" char DAT_003f74e0[];
void* __cdecl Alloc(unsigned int);
struct Obj_57d70 {
    void Init(int);
};
struct Tail_57d70 {
    void Init();
};
class Factory_57d70 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
struct Raw_57d70 {
    unsigned int vptr;
    char pad[8];
    int f;
    char pad2[12];
    unsigned char b;
};
void* Factory_57d70::vfunc_5() {
    Raw_57d70* p = (Raw_57d70*)Alloc(0x20);
    if (p != 0) {
        ((Obj_57d70*)p)->Init(0);
        p->vptr = ((int)DAT_003f74e0);
        p->f = 0;
        ((Tail_57d70*)((char*)p + 0x10))->Init();
        p->b = 1;
        return p;
    }
    return 0;
}
