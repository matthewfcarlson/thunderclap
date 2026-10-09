class pddiPrimBufferStream {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10(char, char, char, char);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
};
class d3dPrimBufferStream : public pddiPrimBufferStream {
  public:
    char pad[0x48];
    unsigned char* p;
    void f10(char, char, char, char);
};
void d3dPrimBufferStream::f10(char a, char b, char c, char d) {
    p[0] = c * 3;
    p[1] = b * 3;
    p[2] = a * 3;
    p[3] = d * 3;
}