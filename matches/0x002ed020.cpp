struct Obj {
    virtual void f();
    Obj* Init();
};
extern "C" void* __cdecl Alloc(unsigned int);
extern Obj* gObj;
void __cdecl Target() {
    Obj* p = gObj;
    if (p == 0) {
        p = (Obj*)Alloc(0x38);
        if (p != 0)
            p = p->Init();
        else
            p = 0;
        gObj = p;
        p->f();
    }
}