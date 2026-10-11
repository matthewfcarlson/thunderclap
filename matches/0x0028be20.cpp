typedef void(__fastcall* Callback)(void*);
extern void __fastcall ElemCtor(void*);
extern void* Alloc(unsigned int);
extern void __stdcall VecNew(void*, int, int, Callback);
class Mem {
  public:
    void* Make(unsigned int, int);
};
class Base {
  public:
    Base(int, int);
    virtual void v0();
    int m4, m8;
    Mem* mc;
    int m10, m14;
};
struct Z4 {
    int a, b, c, d;
    Z4() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }
};
class V2 : public Base {
  public:
    Z4 z;
    int m28;
    V2(int, int);
    virtual void v1();
};
V2::V2(int x, int y) : Base(x, y) {

    m28 = 0;
    if (mc == 0) {
        int n = m10;
        void* p = Alloc(n * 8);
        m28 = (int)(p ? (VecNew(p, 8, n, ElemCtor), p) : 0);
        return;
    }
    m28 = (int)mc->Make(m10 << 3, 3);
}
