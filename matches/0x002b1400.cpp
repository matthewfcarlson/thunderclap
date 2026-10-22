class V {
  public:
    virtual void a() throw();
    virtual void b() throw();
};
extern void __cdecl FUN_002b1390(void*, void*) throw();
extern void __cdecl thunk_FUN_00267090(void*) throw();
template <class T> struct Ref_2b1400 {
    T* p;
    ~Ref_2b1400() throw() {
        if (p)
            p->b();
        p = 0;
    }
};
template <int N> struct Buf_2b1400 {
    void* p;
    char pad[N - 4];
    ~Buf_2b1400() throw() {
        if (p)
            thunk_FUN_00267090(p);
    }
};
struct Range_2b1400 {
    void* b;
    void* e;
    ~Range_2b1400() throw() {
        if (b) {
            FUN_002b1390(b, e);
            thunk_FUN_00267090(b);
        }
    }
};
class Entity_2b1400 {
  public:
    virtual ~Entity_2b1400() throw();
    char pad[0xc];
};
class VertexOffsetExpressionMixer_2b1400 : public Entity_2b1400 {
  public:
    Ref_2b1400<V> m10;
    Buf_2b1400<0xc> m14;
    Buf_2b1400<0xc> m20;
    Range_2b1400 m2c;
    virtual ~VertexOffsetExpressionMixer_2b1400() throw();
};
VertexOffsetExpressionMixer_2b1400::~VertexOffsetExpressionMixer_2b1400() throw() {}
