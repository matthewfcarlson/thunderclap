extern "C" void _ReadWriteBarrier();
extern void* g_a[];
extern void* g_b[];
void operator delete(void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct Pool {
    void Free(void*) throw();
};
struct Mgr {
    char pad[8];
    Pool* pool;
};
struct Item {
    char pad[0x18];
    int f;
};
struct Sub {
    void Fin() throw();
};
class Obj {
  public:
    void* vptr;
    char pad0[0x14];
    Sub sub;
    char pad1[0x50 - 0x19];
    Ref* m50;
    char pad2[0xc];
    Ref* m60;
    Ref* m64;
    char pad3[0xa8 - 0x68];
    Mgr* ma8;
    void* mac;
    char pad4[0x150 - 0xb0];
    Ref* arr[8][8];
    char pad5[0x2ac - 0x250];
    Item* m2ac;
    void f();
};
void Obj::f() {
    Item* it = m2ac;
    vptr = g_a;
    if (it) {
        ma8->pool->Free(&it->f);
        m2ac = 0;
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (arr[i][j]) {
                arr[i][j]->Release();
                arr[i][j] = 0;
            }
    vptr = g_b;
    _ReadWriteBarrier();
    if (m50) {
        m50->Release();
        m50 = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    if (mac) {
        operator delete(mac);
        mac = 0;
    }
    sub.Fin();
}
