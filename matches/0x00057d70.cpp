void* __cdecl Alloc(unsigned int);
struct Obj {
    void Init(int);
};
struct Tail {
    void Init();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
struct Raw {
    unsigned int vptr;
    char pad[8];
    int f;
    char pad2[12];
    unsigned char b;
};
void* Factory::vfunc_5() {
    Raw* p = (Raw*)Alloc(0x20);
    if (p != 0) {
        ((Obj*)p)->Init(0);
        p->vptr = 0x3f74e0;
        p->f = 0;
        ((Tail*)((char*)p + 0x10))->Init();
        p->b = 1;
        return p;
    }
    return 0;
}
