class Obj {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Obj* v5();
    void Init(int);
    int a;
    char pad[4];
    int b;
    int c;
};
extern "C" void* __cdecl Alloc(unsigned int);
Obj* Obj::v5() {
    Obj* p = (Obj*)Alloc(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = 0x412ab0;
        p->b = 0;
        p->c = 0;
        return p;
    }
    return 0;
}