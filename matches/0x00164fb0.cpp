extern "C" char DAT_00415970[];
struct InitBase_164fb0 {
    void init(int);
};
struct Sub_164fb0 {
    void setup();
};
struct Obj_164fb0 {
    unsigned vptr;
    char pad[12];
    Sub_164fb0 sub;
    char pad2[4];
    int x;
    unsigned char flag;
};
void* __cdecl Alloc(unsigned int);
struct Factory_164fb0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Obj_164fb0* vfunc_5();
};
Obj_164fb0* Factory_164fb0::vfunc_5() {
    Obj_164fb0* p = (Obj_164fb0*)Alloc(0x20);
    if (p) {
        ((InitBase_164fb0*)p)->init(0);
        p->vptr = ((int)DAT_00415970);
        p->sub.setup();
        p->x = 0;
        p->flag = 1;
        return p;
    }
    return 0;
}