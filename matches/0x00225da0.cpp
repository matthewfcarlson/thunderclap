extern "C" void* __cdecl alloc(unsigned int);
int gCount;
int gMax;
struct Obj {
    int v;
    void InitA(void*);
    void InitB(void*);
};
struct Factory {
    Obj* Make();
};
Obj* Factory::Make() {
    Obj* p = (Obj*)alloc(0x240);
    if (p != 0) {
        p->InitA(this);
        p->v = 0x427368;
        p->InitB(this);
        ++gCount;
        if (gCount > gMax)
            gMax = gCount;
        return p;
    }
    return 0;
}