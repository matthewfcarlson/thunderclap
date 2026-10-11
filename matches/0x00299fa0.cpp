extern void __cdecl Release(void*) throw();
extern void __cdecl FUN_00299ac0(void*, void*) throw();
template <int N> struct Buf {
    void* p;
    char pad[N - 4];
    ~Buf() {
        if (p)
            Release(p);
    }
};
struct Range {
    void* b;
    void* e;
    ~Range() {
        if (b) {
            FUN_00299ac0(b, e);
            Release(b);
        }
    }
};
class IRefCount {
  public:
    virtual ~IRefCount() {}
    int pad4;
};
class CompositeDrawable : public IRefCount {
  public:
    Buf<0xc> m8;
    Buf<0x10> m14;
    Buf<0xc> m24;
    Buf<0xc> m30;
    Range m3c;
    virtual ~CompositeDrawable();
};
CompositeDrawable::~CompositeDrawable() {}
