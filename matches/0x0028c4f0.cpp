extern "C" void _ReadWriteBarrier();
extern void* g_f2[];
extern void* g_s[];
extern void* g_c[];
void __cdecl Drop(void*);
class Res {
  public:
    virtual void F0();
    virtual void Release();
};
class Obj {
  public:
    void* vptr;
    char pad[8];
    Res* p0;
    char pad2[4];
    void* p1;
    void* p2;
    void Reset() {
        if (!p0)
            Drop(p1);
        else {
            _ReadWriteBarrier();
            if (p0) {
                p0->Release();
                p0 = 0;
            }
        }
        p1 = 0;
    }
    void F();
};
void Obj::F() {
    vptr = g_f2;
    if (!p0)
        Drop(p2);
    p2 = 0;
    Reset();
    vptr = g_s;
    Reset();
    vptr = g_c;
}
