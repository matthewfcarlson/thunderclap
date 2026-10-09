extern "C" void* __cdecl alloc(unsigned int);
struct Obj {
    void* vt;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    float d;
    void Init(int x);
};
Obj* target() {
    Obj* p = (Obj*)alloc(0x14);
    if (p) {
        p->Init(0);
        p->vt = (void*)0x410c34;
        p->c = 0;
        p->d = 1.0f;
        return p;
    }
    return 0;
}
