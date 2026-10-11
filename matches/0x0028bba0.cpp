namespace pure3d {
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
class Float2Channel : public Base {
  public:
    int m18;
    Float2Channel(int, int);
    virtual void v1();
};
Float2Channel::Float2Channel(int x, int y) : Base(x, y) {
    m18 = 0;
    if (mc == 0) {
        int n = m10;
        void* p = Alloc(n * 8);
        m18 = (int)(p ? (VecNew(p, 8, n, ElemCtor), p) : 0);
        return;
    }
    m18 = (int)mc->Make(m10 << 3, 3);
}
} // namespace pure3d
