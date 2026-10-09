class Device {
  public:
    virtual void f0();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void f1(int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual int Get();
};
class audio_HalRsdFileStream {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    char pad[0x1c];
    Device* dev;
    char gap[8];
    int pos;
    int base;
    int limit;
};
void audio_HalRsdFileStream::vfunc_5(int amount) {
    int end = limit;
    if (!end)
        end = dev->Get();
    int off = (end - pos) + amount;
    pos = end - off;
    dev->f1(base + off);
}
