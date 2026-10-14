extern void* g_a_afd00[];
extern void* g_b_afd00[];
void operator delete[](void*);
class Ref_afd00 {
  public:
    virtual void F0();
    virtual void Release();
};
struct P_afd00 {
    char pad[0x2c];
    Ref_afd00* r;
    void Fini() {
        if (r) {
            r->Release();
            r = 0;
        }
    }
};
class Obj_afd00 {
  public:
    void* vptr;
    char pad[8];
    Ref_afd00* mc;
    int count;
    P_afd00* arr;
    void f();
};
void Obj_afd00::f() {
    vptr = g_a_afd00;
    if (arr) {
        for (int i = 0; i < count; i++)
            if (arr[i].r) {
                arr[i].r->Release();
                arr[i].r = 0;
            }
        if (arr) {
            int n = ((int*)arr)[-1];
            void* blk = (int*)arr - 1;
            P_afd00* p = arr + n;
            while (--n >= 0) {
                --p;
                p->Fini();
            }
            operator delete[](blk);
            arr = 0;
        }
    }
    if (mc) {
        mc->Release();
        mc = 0;
    }
    vptr = g_b_afd00;
}
