typedef unsigned int U;
namespace pure3d {
class pddiPrimBufferStream {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(U*, U);
    virtual void f17();
};
class d3dPrimBufferStream : public pddiPrimBufferStream {
public:
    char pad[32];
    U* a;
    char pad2[8];
    U* b;
    void helper();
    virtual void f16(U* p, U v);
};
void d3dPrimBufferStream::f16(U* p, U v) {
    U* dst = a;
    dst[0] = p[0];
    dst[1] = p[1];
    dst[2] = p[2];
    *b = v;
    helper();
}
}
