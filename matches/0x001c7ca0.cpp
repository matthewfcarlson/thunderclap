struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}