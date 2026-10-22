class Item_2b0100 {
  public:
    virtual void A() throw();
    virtual void B() throw();
};
extern "C" void __cdecl FreeMem(void*) throw();
template <class T> struct Vec_2b0100 {
    T* begin;
    T* end;
    T* cap;
    unsigned size() const { return end - begin; }
    T& operator[](unsigned i) { return begin[i]; }
    ~Vec_2b0100() throw() {
        if (begin)
            FreeMem(begin);
    }
};
template <int N> struct Buf_2b0100 {
    void* p;
    char pad[N - 4];
    ~Buf_2b0100() throw() {
        if (p)
            FreeMem(p);
    }
};
class Entity_2b0100 {
  public:
    virtual ~Entity_2b0100() throw();
    int pad[3];
};
class ExpressionGroup : public Entity_2b0100 {
  public:
    Vec_2b0100<Item_2b0100*> items;
    char pad2[0xc];
    Buf_2b0100<4> extra;
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
