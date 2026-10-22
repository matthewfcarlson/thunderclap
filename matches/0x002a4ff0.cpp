struct E_2a4ff0 {
    char d[0x10];
    ~E_2a4ff0() throw();
};
extern "C" void __cdecl myfree(void*) throw();
template <class T> struct Vec_2a4ff0 {
    T* mBegin;
    T* mEnd;
    ~Vec_2a4ff0() throw() {
        T* p = mBegin;
        if (p) {
            T* e = mEnd;
            while (p != e) {
                p->~T();
                ++p;
            }
            myfree(mBegin);
        }
    }
};
struct DrawableHierarchy_2a4ff0 {
    virtual ~DrawableHierarchy_2a4ff0() throw();
};
class DrawableContainer : public DrawableHierarchy_2a4ff0 {
  public:
    virtual ~DrawableContainer() throw();
    virtual void Update();
    char pad[0x44];
    Vec_2a4ff0<E_2a4ff0> items;
};
DrawableContainer::~DrawableContainer() throw() {}
