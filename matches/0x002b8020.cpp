struct PolySkin {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int vfunc_4();
};
struct Helper_2b8020 {
    int f(PolySkin*);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
int PolySkin::vfunc_4() {
    Helper_2b8020* p = (Helper_2b8020*)thunk_FUN_0008d690(0x78);
    if (p)
        return p->f(this);
    return 0;
}