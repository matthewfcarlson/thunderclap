extern void __cdecl Release(void*) throw();
extern void __cdecl FUN_00299ac0(void*, void*) throw();
template <int N> struct Buf_299fa0 {
    void* p;
    char pad[N - 4];
    ~Buf_299fa0() {
        if (p)
            Release(p);
    }
};
struct Range_299fa0 {
    void* b;
    void* e;
    ~Range_299fa0() {
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
class ActivePrimitiveList_299fa0 : public IRefCount {
  public:
    Buf_299fa0<0xc> m8;
    Buf_299fa0<0x10> m14;
    Buf_299fa0<0xc> m24;
    Buf_299fa0<0xc> m30;
    Range_299fa0 m3c;
    virtual ~ActivePrimitiveList_299fa0();
};
ActivePrimitiveList_299fa0::~ActivePrimitiveList_299fa0() {}
