extern void* g_a[];
extern void* g_b[];
void operator delete[](void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct P {
    char pad[0x2c];
    Ref* r;
    void Fini() {
        if (r) {
            r->Release();
            r = 0;
        }
    }
};
class Obj {
  public:
    void* vptr;
    char pad[8];
    Ref* mc;
    int count;
    P* arr;
    void f();
};
void Obj::f() {
    vptr = g_a;
    if (arr) {
        for (int i = 0; i < count; i++)
            if (arr[i].r) {
                arr[i].r->Release();
                arr[i].r = 0;
            }
        if (arr) {
            int n = ((int*)arr)[-1];
            void* blk = (int*)arr - 1;
            P* p = arr + n;
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
    vptr = g_b;
}
