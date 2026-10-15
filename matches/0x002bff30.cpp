extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" void* memset(void*, int, unsigned int);
class Image8 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void vfunc_16(const unsigned int*, unsigned int);
    char pad[0x2c];
    unsigned int data[256];
};
void Image8::vfunc_16(const unsigned int* src, unsigned int n) {
    if (n != 256)
        memset(data, 0, sizeof data);
    memcpy(data, src, n * 4);
}