class Item {
  public:
    virtual void A() throw();
    virtual void B() throw();
};
extern "C" void __cdecl FreeMem(void*) throw();
template <class T> struct Vec {
    T* begin;
    T* end;
    T* cap;
    unsigned size() const { return end - begin; }
    T& operator[](unsigned i) { return begin[i]; }
    ~Vec() throw() {
        if (begin)
            FreeMem(begin);
    }
};
template <int N> struct Buf {
    void* p;
    char pad[N - 4];
    ~Buf() throw() {
        if (p)
            FreeMem(p);
    }
};
class Base {
  public:
    virtual ~Base() throw();
    int pad[3];
};
class ExpressionGroup : public Base {
  public:
    Vec<Item*> items;
    char pad2[0xc];
    Buf<4> extra;
    virtual ~ExpressionGroup() throw();
};
ExpressionGroup::~ExpressionGroup() throw() {
    for (unsigned i = 0; i < items.size(); i++) {
        if (items[i]) {
            items[i]->B();
            items[i] = 0;
        }
    }
}
