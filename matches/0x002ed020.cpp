struct Obj_2ed020 {
    virtual void f();
    Obj_2ed020* Init();
};
extern "C" void* __cdecl Alloc(unsigned int);
extern Obj_2ed020* gObj_2ed020;
void __cdecl Target() {
    Obj_2ed020* p = gObj_2ed020;
    if (p == 0) {
        p = (Obj_2ed020*)Alloc(0x38);
        if (p != 0)
            p = p->Init();
        else
            p = 0;
        gObj_2ed020 = p;
        p->f();
    }
}