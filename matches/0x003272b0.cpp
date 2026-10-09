typedef unsigned int uint;
struct Store {
    char pad[4];
    void* data;
};
struct Buffer {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j(const void*, int);
    char pad[0x20];
    int mCount;
    char pad2[4];
    Store* store;
};
void FUN_0031c230(int);
extern "C" void __cdecl memcpy(void*, const void*, unsigned int);
void Buffer::j(const void* src, int count) {
    void* dst = store->data;
    FUN_0031c230(0);
    memcpy(dst, src, count * 2);
    mCount = count;
}
