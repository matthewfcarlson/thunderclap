class Item_2d0f10 {
  public:
    virtual void F() throw();
    virtual void Release() throw();
};
extern "C" void __cdecl Free(void*) throw();
template <class T> struct Vec_2d0f10 {
    T* begin;
    T* end;
    unsigned size() const { return end - begin; }
    ~Vec_2d0f10() throw() {
        if (begin)
            Free(begin);
    }
};
class IRefCount {
  public:
    virtual ~IRefCount() throw() {}
};
class VertexAnimObject : public IRefCount {
  public:
    int pad4;
    Item_2d0f10* owner;
    Vec_2d0f10<Item_2d0f10*> items;
    virtual ~VertexAnimObject() throw();
};
VertexAnimObject::~VertexAnimObject() throw() {
    unsigned n = items.size();
    unsigned i = 0;
    while (i < n) {
        Item_2d0f10** slot = items.begin + i;
        Item_2d0f10* p = *slot;
        if (p) {
            p->Release();
            *slot = 0;
        }
        ++i;
    }
    if (owner) {
        owner->Release();
        owner = 0;
    }
}
