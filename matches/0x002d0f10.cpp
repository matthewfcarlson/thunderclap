class Item {
  public:
    virtual void F() throw();
    virtual void Release() throw();
};
extern "C" void __cdecl Free(void*) throw();
template <class T> struct Vec {
    T* begin;
    T* end;
    unsigned size() const { return end - begin; }
    ~Vec() throw() {
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
    Item* owner;
    Vec<Item*> items;
    virtual ~VertexAnimObject() throw();
};
VertexAnimObject::~VertexAnimObject() throw() {
    unsigned n = items.size();
    unsigned i = 0;
    while (i < n) {
        Item** slot = items.begin + i;
        Item* p = *slot;
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
