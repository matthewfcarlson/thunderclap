struct E {
    char d[0x10];
    ~E() throw();
};
extern "C" void __cdecl myfree(void*) throw();
template <class T> struct Vec {
    T* mBegin;
    T* mEnd;
    ~Vec() throw() {
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
struct Base {
    virtual ~Base() throw();
};
class DrawableContainer : public Base {
  public:
    virtual ~DrawableContainer() throw();
    virtual void Update();
    char pad[0x44];
    Vec<E> items;
};
DrawableContainer::~DrawableContainer() throw() {}
