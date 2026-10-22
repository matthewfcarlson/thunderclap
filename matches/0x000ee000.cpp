extern "C" void _ReadWriteBarrier();
extern void* g_a_ee000[];
extern void* g_b_ee000[];
void operator delete(void*);
class Ref_ee000 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Pool_ee000 {
    void Free(void*) throw();
};
struct Mgr_ee000 {
    char pad[8];
    Pool_ee000* pool;
};
struct Item_ee000 {
    char pad[0x18];
    int f;
};
struct Sub_ee000 {
    void Fin() throw();
};
class ImageSelector_ee000 {
  public:
    void* vptr;
    char pad0[0x14];
    Sub_ee000 sub;
    char pad1[0x50 - 0x19];
    Ref_ee000* m50;
    char pad2[0xc];
    Ref_ee000* m60;
    Ref_ee000* m64;
    char pad3[0xa8 - 0x68];
    Mgr_ee000* ma8;
    void* mac;
    char pad4[0x150 - 0xb0];
    Ref_ee000* arr[8][8];
    char pad5[0x2ac - 0x250];
    Item_ee000* m2ac;
    void f();
};
void ImageSelector_ee000::f() {
    Item_ee000* it = m2ac;
    vptr = g_a_ee000;
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
    vptr = g_b_ee000;
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
