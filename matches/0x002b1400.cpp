class V {
  public:
    virtual void a() throw();
    virtual void b() throw();
};
extern void __cdecl FUN_002b1390(void*, void*) throw();
extern void __cdecl thunk_FUN_00267090(void*) throw();
template <class T> struct Ref {
    T* p;
    ~Ref() throw() {
        if (p)
            p->b();
        p = 0;
    }
};
template <int N> struct Buf {
    void* p;
    char pad[N - 4];
    ~Buf() throw() {
        if (p)
            thunk_FUN_00267090(p);
    }
};
struct Range {
    void* b;
    void* e;
    ~Range() throw() {
        if (b) {
            FUN_002b1390(b, e);
            thunk_FUN_00267090(b);
        }
    }
};
class Base0 {
  public:
    virtual ~Base0() throw();
    char pad[0xc];
};
class Obj : public Base0 {
  public:
    Ref<V> m10;
    Buf<0xc> m14;
    Buf<0xc> m20;
    Range m2c;
    virtual ~Obj() throw();
};
Obj::~Obj() throw() {}
