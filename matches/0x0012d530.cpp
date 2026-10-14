extern "C" char DAT_00410c34[];
extern "C" void* __cdecl alloc(unsigned int);
struct Obj_12d530 {
    void* vt;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    float d;
    void Init(int x);
};
Obj_12d530* target() {
    Obj_12d530* p = (Obj_12d530*)alloc(0x14);
    if (p) {
        p->Init(0);
        p->vt = (void*)((int)DAT_00410c34);
        p->c = 0;
        p->d = 1.0f;
        return p;
    }
    return 0;
}
