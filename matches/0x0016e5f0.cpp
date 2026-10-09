typedef unsigned char u8;
void* __cdecl Alloc(unsigned int);
extern char kVtbl[];
struct Sub0 {
    void Init(int);
};
struct Sub1 {
    void Init();
};
struct Obj {
    void* vptr;
    char pad[0x18 - 4];
    int a, b, c;
    float d;
    int e, f;
    u8 flag;
};
struct Factory {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Obj* v5();
};
Obj* Factory::v5() {
    Obj* p = (Obj*)Alloc(0x38);
    if (p) {
        ((Sub0*)p)->Init(0);
        p->vptr = (void*)kVtbl;
        ((Sub1*)((char*)p + 0x10))->Init();
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->e = 0;
        p->f = 0;
        p->d = 1.0f;
        p->flag = 1;
        return p;
    }
    return 0;
}
