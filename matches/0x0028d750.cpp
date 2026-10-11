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
class Q : public Base {
  public:
    void* m18;
    Q(int, int);
    virtual void v1();
};
Q::Q(int x, int y) : Base(x, y) {
    m18 = 0;
    if (mc == 0) {
        int n = m10;
        void* p = Alloc(n * 4);
        m18 = (p ? (VecNew(p, 4, n, ElemCtor), p) : 0);
        return;
    }
    m18 = mc->Make(m10 << 2, 3);
}
