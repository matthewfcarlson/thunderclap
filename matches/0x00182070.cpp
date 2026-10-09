struct A {
    void* f();
};
struct B {
    int f();
};
struct C {
    int f(int);
};
struct D {
    int f(int*);
};
class PropSetStateByNameAction {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual bool vfunc_5(unsigned int, unsigned int);
    char pad4[0x18];
    int* mData;
    A* mThing;
};
bool PropSetStateByNameAction::vfunc_5(unsigned int param, unsigned int) {
    if (param == 0 && mThing != 0) {
        A* p = (A*)mThing->f();
        int x = ((B*)p)->f();
        int index = mData[4];
        if (x != 0) {
            if (index < 0)
                x = *(int*)((char*)x + 0x128);
            else {
                if (index >= 8)
                    return false;
                x = ((C*)x)->f(index);
            }
            if (x != 0)
                ((D*)x)->f((int*)((char*)mData + 0x18));
        }
    }
    return false;
}