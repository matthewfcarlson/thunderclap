struct Base {
    Base();
    virtual void vfn();
};

class Derived : public Base {
  public:
    char pad[8];
    int m0c;
    int m10;
    Derived();
};

extern "C" void _ReadWriteBarrier();

extern int vftable[];

Derived::Derived() {
    m0c = 0;
    m10 = 0;
    *(int*)this = (int)vftable;
}
