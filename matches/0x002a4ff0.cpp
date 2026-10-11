struct E {
    char d[0x10];
    ~E() throw();
};

extern "C" void __cdecl myfree(void*);
extern char DrawableContainer_vftable[];

struct Base {
    ~Base() throw();
};

class DrawableContainer : public Base {
  public:
    void* vptr;
    char pad[0x44];
    E* mBegin;
    E* mEnd;
    void Dtor();
};

void DrawableContainer::Dtor() {
    *(void* volatile*)&vptr = DrawableContainer_vftable;
    E* p = *(E* volatile*)&mBegin;
    if (p) {
        E* e = mEnd;
        while (p != e) {
            p->~E();
            ++p;
        }
        myfree(mBegin);
    }
    Base::~Base();
}
